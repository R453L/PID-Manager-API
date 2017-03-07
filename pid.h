#ifndef _pid_h_
#define _pid_h_

#define PID_MIN  	500
#define PID_MAX 	600

//variable declarations go here
unsigned char *pid_map;

//method declarations
int allocate_map(void);
int allocate_pid(void);
void release_pid(int pid);

#endif
