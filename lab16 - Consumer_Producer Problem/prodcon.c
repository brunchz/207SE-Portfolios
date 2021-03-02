#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ops_sems.h"
#include <sys/wait.h>

/* Remember to try reversing the timings...*/
int bufferlength = 8; //Limited buffer length
//what could we do about this?
int main(int argc, char argv[])
{
  //Created 2 variables to store the positions of the consumer & producer relative to the buffer length
  int conslot = bufferlength + 1; 
  int prodslot = bufferlength + 2;
  pid_t pid;
  int status = 0;
  int i;
  //Create shared memory segment
  int shm_id = shmget(ftok("prodcon_example2.c", 2), bufferlength,
                      0666 | IPC_CREAT);
  //Use our source file as the "key"
  int id = ops_semget("prodcon_example2.c", 0);
  char *data; //For our pointer to shared memory...
  pid = fork();
  if (pid)
  {
    //P1 - CONSUMER
    shm_id = shmget(ftok("prodcon_example2.c", 2), 0, 006);
    //Attach the shared buffer
    data = shmat(shm_id, (void *)0, 0);
    //Initialise the positions of the consumer & producer to 0
    data[conslot] = 1; 
    data[prodslot] = 0;

    while (1){ //Runs the code indefinitely
      //If the position of the producer is equaled to the position of the consumer, do nothing
      while (data[prodslot] == data[conslot]); 
      ops_wait(id);
      printf("Consuming item number %d...\n", data[conslot]);
      sleep(1);
      char item = data[data[conslot]];
      printf("Consumed item number %d.  Item value was %d\n",
             data[conslot], item);
      //Adds 1 to the position and mods prevents the consumer position from going beyong the buffer
      data[conslot] = (data[conslot] + 1) % bufferlength; 
   }
    //Detatch
    shmdt(data);
    printf("All done consuming.\n");
    wait(&status); //For child process so that we can
    //Delete the shared memory
    printf("Child ended, removing shm\n");
    shmctl(shm_id, IPC_RMID, NULL);
 }
  else
  {
    //P2
    shm_id = shmget(ftok("prodcon_example2.c", 2), 0, 006);
    //Attach the shared buffer
    data = shmat(shm_id, (void *)0, 0);
    //Initialise the positions of the consumer & producer to 0
    data[conslot] = 0; 
    data[prodslot] = 0;

    while (1){ //Runs the code indefinitely
      //Blocks the producer from moving on if the next position is the consumer.
      while ((data[prodslot] + 1) % bufferlength == data[conslot]); 
      printf("Producing item number %d...\n", data[prodslot]);
      sleep(2);
      data[data[prodslot]] = data[prodslot] * 2; //Simple data, easy to check.
      printf("Produced item number %d.  Value is %d\n",
             data[prodslot], data[data[prodslot]]);
      ops_signal(id);
      //Adds 1 to the position and mods prevents the producer position from going beyong the buffer
      data[prodslot] = (data[prodslot] + 1) % bufferlength;
   }
    //Detatch
    shmdt(data);
    printf("Producer finished.");
 }
}
 