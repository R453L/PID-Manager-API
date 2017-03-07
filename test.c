/*
 * test.c
 * Test the implementation of the pid manager.
 */
#include <pthread.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include "pid.h"

#define NUM_THREADS 125

void* pid_thread( void* argument )
{
	int thread_num = *( ( int* )argument ) + 1;
	int pid_value = allocate_pid();
	if (pid_value == -1) {
		printf("Thread %d. Unable to allocate pid. All pid's in use.\n", thread_num);
	}
	else {
		printf("Thread %d. pid# %d allocated.\n", thread_num, pid_value);
		int sleep_time = rand() % 5;
		sleep(sleep_time);
		release_pid(pid_value);
		printf("Thread %d. pid# %d deallocated.\n", thread_num, pid_value);
	}
	return NULL;
}

int main( )
{
  pthread_t threads[ NUM_THREADS ];
  int thread_args[ NUM_THREADS ];
  int thread_result_val;
  unsigned index;

	int map_val = allocate_map();

	if (map_val == -1) {
		printf("Unable to allocate map. Exiting program.");
		return 0;
	}

  // create all threads
  for( index = 0; index < NUM_THREADS; ++index )
  {
    thread_args[ index ] = index;
    thread_result_val = pthread_create( &threads[index], NULL, pid_thread, &thread_args[index] );
    assert( !thread_result_val );
  }

  // wait for each thread to complete
  for( index = 0; index < NUM_THREADS; ++index )
  {
    thread_result_val = pthread_join( threads[ index ], NULL );
    assert( !thread_result_val );
   }

   printf( "All processes completed.\n" );
	 return 0;
}
