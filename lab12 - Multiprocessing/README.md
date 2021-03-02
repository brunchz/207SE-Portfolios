# Lab Activity 12 – Multiprocessing

|Grade|Improvements|
|-------|------|
|3 Points|Multiprocessing - Include a little more comparison of the multiprocess approaches. - Make better use of referencing. Scheduling - Include a little more comparison of the scheduling approaches. - Make better use of referencing.|
## A. Comparison Of The Multitasking, Multiprogramming And Multithreading.
### MULTITASKING

Conventional wisdom suggests multitasking to be multiple tasks being run simultaneously, however (Abualrob 2012) suggests multitasking to be the illusion of parallelism by utilising context switching to assign different tasks to the CPU at any given time.
Multitasking can exist on a process level and also a thread level known as multithreading (discussed later). The key point is that any task (thread or process) is sharing common processing resources like memory or the CPU which are reallocated accordingly as tasks are switched between one to another.

### MULTIPROGRAMMING

Take for instance queueing up to order food at MCD. When it is my turn to order and I have not decided whether I would like a cheeseburger or a big mac, I would stand to the side while the customer behind me can proceed to order while I make up my mind.
This is similar to what multiprogramming does. When it is a process’ turn to be moved into the CPU from the ready-state queue but needs additional resources eg. I/O request/sub process, it will be sent to another part of memory thus freeing up resources for other processes to run until the I/O request has been fulfilled, thereby maximising the utilization of resources. After which the process can be moved back into the ready-state queue for execution.

![multiprogramming](https://i.postimg.cc/CxK1RTp5/image.png)

### MULTITHREADING

Multithreading as discussed earlier, allows processes to have different segments (threads) that run concurrently in the same process. (Tolomei 2017) puts it in understandable way stating multithreading to be similar to a parent process having multiple child processes that run independently, all sharing the same resources of the parent process. Multithreading, like multiprogramming and multitasking, greatly increases the efficiency of process execution and allows for improved throughput of computers.


### EVOLUTION OVERTIME & SUMMARY

The high costs of CPU execution time during the early days of computing meant execution of processes needed to be optimised to max out the usage of the CPU. This led to the creation of multiprogramming.
Similarly, multitasking employs the use of context switching which swap processes in and out of memory to make full use of computer hardware. The difference between multitasking and multiprogramming is that the latter is a subset of the former and that multitasking is used more in modern OSes.
Multithreading was created with the aim of optimising the limitation (back then) of a single core by creating multiple threads that share resources with a parent process.
All of these methods improve the efficiency of computers execution. They stem from the same economical problem that was present during the beginnings of computing and vastly helped with driving down the need for more hardware to obtain speed.

## B. Comparison Of CPU And Job Scheduling.

Scheduling is the allocation of resources to tasks in a computer. There exist 2 types of scheduling namely CPU Scheduling and Job Scheduling. The latter is responsible for task selection that will be brought from the job queue to the ready-state queue (secondary memory to main memory). From there, CPU scheduling steps in and utilises an algorithm to select which processes in the ready-state queue will be executed by the CPU next (how processes in main memory get CPU execution time). The following diagram illustrates this in more detail.

![CPU-vs-Job-scheduling](https://i.postimg.cc/8cF4pnk0/image.png)