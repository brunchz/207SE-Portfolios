//This is script uses the semaphores for processes to take turns in executions to prevent
//2 or more processes executing at the same time.
//This example prints the lyrics for the song "A hole in my bucket" where 2 processes takes
//turns to print their line of the song.
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ops_sems.h"
int main(int argc, char argv[])
{
  int id;
  //Use our source file as the "key"
  id = ops_semget("critical_example2.c", 1);
  int pid = fork();
  FILE *henry;
  FILE *liza;

  if (pid)
  {
    //P1
    henry = fopen("henry.txt", "w"); 
    int count_henry = 0;
    while(count_henry<1)
    {
      //All of Henry's lines are groupped together in process 1
      ops_wait(id);
      fprintf(henry,"There's a hole in the bucket, dear Liza, dear Liza,\n");
      fprintf(henry,"There's a hole in the bucket, dear Liza, a hole.\n");
      //Printing to the screen
      printf("There's a hole in the bucket, dear Liza, dear Liza,\n");
      printf("There's a hole in the bucket, dear Liza, a hole.\n");
      rsleep();
      ops_signal(id);

      ops_wait(id);
      fprintf(henry,"With what shall I fix it, dear Liza, dear Liza?\n");
      fprintf(henry,"With what shall I fix it, dear Liza, with what?\n");
      //Printing to the screen
      printf("With what shall I fix it, dear Liza, dear Liza?\n");
      printf("With what shall I fix it, dear Liza, with what?\n");
      rsleep();

      ops_signal(id);
      //Wrong lyrics spotted, corrected (extra points?)
      ops_wait(id);
      fprintf(henry,"The stick is too big, dear Liza, dear Liza,\n");
      fprintf(henry,"The stick is too big, dear Liza, too big.\n");
      //Printing to the screen
      printf("The stick is too big, dear Liza, dear Liza,\n");
      printf("The stick is too big, dear Liza, too big.\n");
      rsleep();
      ops_signal(id);

      ops_wait(id);
      fprintf(henry,"With what shall I cut it, dear Liza, dear Liza?\n");
      fprintf(henry,"With what shall I cut it, dear Liza, with what?\n");
      //Printing to the screen
      printf("With what shall I cut it, dear Liza, dear Liza?\n");
      printf("With what shall I cut it, dear Liza, with what?\n");
      
      rsleep();
      ops_signal(id);
      count_henry++;
    }
    fclose(henry);  
  }
  else
  {
    //Liza's lines are group together under process 2
    liza = freopen("liza.txt", "w" , stderr);
    int count_liza = 0;
    while(count_liza<1)
    {
      ops_wait(id);
      fprintf(liza,"Then fix it, dear Henry, dear Henry, dear Henry,\n");
      fprintf(liza,"Then fix it, dear Henry, dear Henry, fix it.\n");
      //Printing to the screen
      printf("Then fix it, dear Henry, dear Henry, dear Henry,\n");
      printf("Then fix it, dear Henry, dear Henry, fix it.\n");
      rsleep();
      ops_signal(id);

      ops_wait(id);
      fprintf(liza,"With a stick, dear Henry, dear Henry, dear Henry,\n");
      fprintf(liza,"With a stick, dear Henry, dear Henry, a stick.\n");
      //Printing to the screen
      printf("With a stick, dear Henry, dear Henry, dear Henry,\n");
      printf("With a stick, dear Henry, dear Henry, a stick.\n");
      rsleep();
      ops_signal(id);

      ops_wait(id);
      fprintf(liza,"Then cut it, dear Henry, dear Henry, dear Henry,\n");
      fprintf(liza,"Then cut it, dear Henry, dear Henry, cut it.\n");
      //Printing to the screen
      printf("Then cut it, dear Henry, dear Henry, dear Henry,\n");
      printf("Then cut it, dear Henry, dear Henry, cut it.\n");
      rsleep();
      ops_signal(id);

      //Wrong lyrics spotted, corrected (extra points?)
      ops_wait(id);
      fprintf(liza,"With a hatchet, dear Henry, dear Henry, dear Henry,\n");
      fprintf(liza,"With a hatchet, dear Henry, dear Henry, a hatchet.\n");
      //Printing to the screen
      printf("With a hatchet, dear Henry, dear Henry, dear Henry,\n");
      printf("With a hatchet, dear Henry, dear Henry, a hatchet.\n");
      rsleep();
      ops_signal(id);
      count_liza++;
    }
    fclose(liza);  
  }
}

