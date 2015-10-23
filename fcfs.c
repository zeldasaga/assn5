#include"assn5.h"
#include<stdio.h>


void fcfs (int count, int *sub, int *run)
{

  int clock = 0;
//int proc_left = count;
  int next_proc = 0;
  int ta = 0, wait = 0, resp = 0;
  int next_clock;
  while (next_proc < count)
    {

      if (sub[next_proc] > clock)
	clock = sub[next_proc];

      resp += clock - sub[next_proc];

      next_clock = clock + run[next_proc];
      ta += next_clock - sub[next_proc];
      wait += next_clock - sub[next_proc] - run[next_proc];

      clock = next_clock;
      next_proc++;


    }


  printf ("Avg. Resp.:%.2f, Avg. T.A:%.2f, Avg. Wait:%.2f\n",(float) resp / count, (float) ta / count, (float) wait / count);
}
