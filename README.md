### ASSIGNMENT TASKS
* Implement a “pid manager” API for obtaining and releasing process identifiers
* Implement a multi-threaded program to test the API

### ASSIGNMENT DETAILS:
   A “pid manager” is responsible for managing process identifiers. When a process is first created, it is assigned a unique pid by the pid manager. The pid is returned to the pid manager when the process completes execution, and the manager may later reassign this pid. Note that the process identifiers must be unique; i.e. no two active processes can have the same pid.
You are required to complete the code for the implementation of the following API for obtaining and releasing a pid:

* int allocate_map(void) – Creates and initializes a data structure for representing pids; returns -1 if unsuccessful, 1 if     successful
* int allocate_pid(void) – Allocates and returns a pid; returns -1 if unable to allocate a pid (all pids are in use)
* void release_pid(int pid) – Releases a pid

You are also required to write a multi-threaded program (in test.c) that tests your API for obtaining and releasing a pid. You will create a number of threads – for example, 100 – and each thread will request a pid, sleep for a random period of time, and then release the pid. (Note that sleeping for a random period of time approximates the typical pid usage in which a pid is assigned to a new process, the process executes and then terminates, and the pid is released on the process’s termination). On Unix and Linux systems, sleeping is accomplished through the sleep(...) function, which is passed an integer value representing the number of seconds to sleep. pid allocation and release should be printed out on screen (indicate also if pid cannot be allocated).

Use the following constants to identify the range of possible pid values that the pid manager can assign:
* #define MIN_PID 500
* #define MAX_PID 600
 
You may use any data structure of your choice to represent the availability of process identifiers. One strategy is to adopt what Linux has done and use a bitmap in which a value of 0 at position i indicates that the process id of value i is available and a value of 1 indicates that the process id is currently in use.
