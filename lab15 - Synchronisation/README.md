# Lab 15 - Synchronisation ‘Hole in Bucket’
|Grade|Improvements|
|-------|------|
|3 Points| Should have put the text on the screen using stderr and stdout. - Comment the code with the required level of detail..|

## A.	Brief Description Of Activity
This activity is about process synchronisation by utilizing semaphores. The task involves creating a script that prints out lyrics from a song “A hole in my bucket” where 2 characters will take turns to sing their lines which uses the fork() function from lab 13.
Typically processes that run at the same time will encounter the problem of collision where both processes choose to run at the same time and causes an error. The use of semaphores allows both processes to be run in sync while not encountering any collision. This allows the lyrics to be printed back and forth (in this case by Henry and Liza) by each process until all the lyrics have been successfully read to stdout. 

### Screenshot of working code
![Synchronisation-demo](https://i.postimg.cc/fRqwdvGD/image.png)

### Screenshot of henry.txt
![henry.txt](https://i.postimg.cc/qM7SKd46/image.png)

### Screenshot of liza.txt
![liza.txt](https://i.postimg.cc/fLZgTG8L/image.png)