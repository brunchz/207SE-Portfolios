//Menu system that uses the fork() function to run multiple processes by creating parent and a child process.
#include <unistd.h> 
#include <stdio.h> 
#include "sys/types.h" 
#include <sys/wait.h>
int main()
{
    int a = 0;
    for (a = 0; a <= 5; a++)
    { //creating all the variables used
        int input;
        int input2;
        pid_t pid_value;
        int status = 0;
        //prints out a menu option to allow users to choose options 1-3
        //takes user input and stores it in variable int input;
        printf("Please select option 1 - 6\n");
        printf("1. ps\n");
        printf("2. date\n");
        printf("3. ifconfig\n");
        printf("4. ls\n");
        printf("5. ping\n");
        printf("6. pause\n");
        printf("Enter your option: ");
        scanf("%d", &input);
        //checks input
        if input
            is 1 - 6 if (input == 1)
            {
                pid_value = fork();
                if (pid_value != 0)
                {
                    wait(&status); //since the return value of the fork() fn is the child's pid, we can use that to show the value of the child's pid
                    printf("=====================================\n ");
                    printf("I am the parent my Process ID is %d, myChild's PID is %d, \n ", getpid(), pid_value);
                    printf("Using the wait ensures that my child finishes first. \n ");
                }
                else
                {
                    printf("I am the child, my Process ID is %d , my Parents PID is %d \n", getpid(), getppid());
                    sleep(2);
                    printf("Using execl to display running processes\n");
                    printf("=====================================\n ");
                    execl("/bin/ps", "ps", (char *)0);
                }
            }
        //Date command
        else if (input == 2)
        {
            pid_value = fork();
            if (pid_value != 0)
            {
                wait(&status);
                printf("=====================================\n ");
                printf("I am the parent my Process ID is %d, myChild's PID is %d, \n ", getpid(), pid_value);
                printf("Using the wait ensures that my child finishes first. \n ");
            }
            else
            {
                printf("I am the child, my Process ID is %d , my Parents PID is %d \n", getpid(), getppid());
                sleep(2);
                printf("Using execl to display the current date & time.\n");
                printf("=====================================\n ");
                execl("/bin/date", "date", (char *)0);
            }
        }
        //ifconfig command
        else if (input == 3)
        {
            pid_value = fork();
            if (pid_value != 0)
            {
                wait(&status);
                printf("=====================================\n ");
                printf("I am the parent my Process ID is %d, myChild's PID is %d, \n ", getpid(), pid_value);
                printf("Using the wait ensures that my child finishes first. \n ");
            }
            else
            {
                printf("I am the child, my Process ID is %d , my Parents PID is %d \n", getpid(), getppid());
                sleep(2);
                printf("Lisitng all network interfaces.\n");
                printf("=====================================\n ");
                execl("/sbin/ifconfig", "ifconfig", (char *)0);
            }
        }
        //ls command
        else if (input == 4)
        {
            pid_value = fork();
            int child_pid;
            if (pid_value != 0)
            {
                wait(&status);
                printf("=====================================\n ");
                printf("I am the parent my Process ID is %d, myChild's PID is %d, \n ", getpid(), pid_value);
                printf("Using the wait ensures that my child finishes first.\n ");
            }
            else
            {
                printf("I am the child, my Process ID is %d , my Parents PID is %d \n", getpid(), getppid());
                sleep(2);
                printf("Listing files in current directory\n");
                printf("=====================================\n ");
                execl("/bin/ls", "ls", (char *)0);
            }
        }
        //ping command for Google and Yahoo
        else if (input == 5)
        {
            pid_value = fork();
            int child_pid;
            if (pid_value != 0)
            {
                wait(&status);
                printf("--------------------------------------------------------------------------\n ");
                printf(" I am the parent my Process ID is %d, myChild's PID is %d, \n ", getpid(), pid_value);
                printf("I am pinging yahoo.com with 2 packets\n ");
                printf("=====================================\n ");
                execl("/bin/ping", "ping", "www.yahoo.com", "-c", "2", (char *)0);
                //the parent pings yahoo.com 2 packets
            }
            else
            {
                printf("I am the child, my Process ID is %d , my Parents PID is %d \n", getpid(), getppid());
                sleep(4);
                printf("I am pinging www.google.com with 2 packets\n");
                printf("=====================================\n ");
                execl("/bin/ping", "ping", "www.google.com", "-c", "2", (char *)0);
                //the child pings google.com 2 packets
            }
        }
        else if (input == 6)
        {
            pid_value = fork();
            int child_pid;
            if (pid_value != 0)
            {
                printf("I am the parent my Process ID is %d, myChild's PID is %d, \n ", getpid(), pid_value);
                printf("Pausing child process...\n");
                kill(pid_value, SIGSTOP);
                execl("/bin/ps", "ps", (char *)0);
            }
            else
            {
                printf("I am the child, my Process ID is %d , my Parents PID is %d \n", getpid(), getppid());
                sleep(2);
                execl("/bin/ping", "ping", "www.google.com", (char *)0);
                //The child doesn't actually ping as the parent pauses it.
            }
        }
        //if input is not 1 - 6, it's invalid input.
        else
        {
            printf("Invalid Input\n");
        }
        return 0;
    }
}