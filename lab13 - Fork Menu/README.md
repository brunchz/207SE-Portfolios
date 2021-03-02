# Lab 13 - Fork Menu  
|Grade|Improvements|
|-------|------|
|5 Points|None.|
### Option 1 - ps
![process1-ps](https://i.postimg.cc/gc6T8NPK/image.png)

As shown, the child process prints its PID as well as its parent’s PID while the parent prints its own PID as well as its child’s PID.


### Option 2 - date
![process2-date](https://i.postimg.cc/FFjxhq4w/image.png)

### Option 3 - ifconfig
![process3-ifconfig](https://i.postimg.cc/zDjRt15D/image.png)

### Option 4 - ls
![process4-ls](https://i.postimg.cc/7ZpCGH19/image.png)

### Option 5 - Ping
![process5-ping](https://i.postimg.cc/WzbtLhjN/image.png)

### Option 6 - Pause Child Processes
![process6-pause-child-process](https://i.postimg.cc/bvxvZQwY/image.png)

As shown, the parent process pauses the child process by sending a SIGSTOP signal. It then executes ps to show that the child process (PID: 11082) is still alive and can be restarted sending a SIGCONT signal if needed.