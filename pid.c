/**
 * Assignment 1: pid manager
 */
#include "pid.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
*	Allocate process id manager map
* Return 1 if successful, -1 if unsuccessful.
*/
int allocate_map(void)
{
	pid_map = (unsigned char*)malloc((PID_MIN + PID_MAX + CHAR_BIT - 1)/CHAR_BIT *  sizeof(char));
	if (pid_map) return 1;
	return -1;
}

/*
* Allocates and returns a process id value if process id availble.
* If no process id avilable, returns -1.
*/
int allocate_pid(void)
{
	int map_value = 0;
	int process_id = pid_map[map_value/CHAR_BIT] & (1 << (map_value & (CHAR_BIT - 1)));
	while (process_id != 0) {
		map_value++;
		process_id = pid_map[map_value/CHAR_BIT] & (1 << (map_value & (CHAR_BIT - 1)));
	}
	if (map_value + PID_MIN > PID_MAX) { return -1; }
	pid_map[map_value/CHAR_BIT] |= 1 << (map_value & (CHAR_BIT-1));
	return map_value + PID_MIN;
}

/*
* Given an int process id value, resets that value in the bitmap to 0.
*/
void release_pid(int pid)
{
	if (pid < PID_MIN) {
		printf("Invalid process id value.");
		return;
	}
	int map_value = pid - PID_MIN;
	pid_map[map_value/CHAR_BIT] &= ~(1 << (map_value & (CHAR_BIT - 1)));
}
