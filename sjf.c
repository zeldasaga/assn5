#include"assn5.h"
#include<stdio.h>

void sjf(int count, int *sub, int *run){

int clock = 0;
int proc_left = count;
int next_proc = 0;
int ta = 0, wait = 0, resp = 0;
int next_clock;

  while (proc_left < count)
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


}
