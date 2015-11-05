//Primary Coder: Zachary Hall
//Group project
//CS 3060-601 Fall 2015
//Assignment #5
/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/
#include"assn5.h"
#include<stdio.h>


void srtf(int count, int *sub, int *run)
{
	const int MAX_SIZE = 100;
	// Put start times and durations in two arrays.  Keep these arrays synced
	int start_time [MAX_SIZE];
	int duration [MAX_SIZE];
	int time_left;
	int elapsed;

	if (count == 0)
	{
		// initialize the arrays
		start_time[count] = sub;
		duration[count] = run;
		time_left = duration[count];
	}

	else
	{
		// Find how much time has elapsed from the start of the current process to the introduction of the newest process
		elapsed = sub - start_time[0];
		// Find out how much time is left on the current process
		time_left = duration[0] - elapsed;
		// Compare the remaining time on the current process to the duration of the newest process
		// If the current process is less, insert the newest process into the appropriate place in the array
		if (time_left <= run)
		{
			int x = 1;
			while (duration[count] >= duration[x] && x < MAX_SIZE)
			{
				x++;
			}
			// Move all processes with longer duration times down a space in the array
			for (int i = count; i >= x; i--)
			{
				start_time[count + 1] = start_time[count];
				duration[count + 1] = duration[count];
			}
			start_time[x] = sub;
			duration[x] = run;
		}
		// If the newest process will complete in less time, move all processes down in the array and insert the newest
		// process into the first 
		else
		{
			for (int i = count; i >= 0; i--)
			{
				start_time[count + 1] = start_time[count];
				duration[count + 1] = duration[count];
			}
			start_time[0] = sub;
			duration[0] = run;
		}
	}
}