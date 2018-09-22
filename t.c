/*This is a proram to count time, written to meaure how ong a computer lasts on battery.
There are some differences in windows and Linux which can be understood from the comments.
So far in windows it has been tested using cygwin.
Attention: in cygwin and windows the process cannot be killed using ctrl-c like in Linux.
It will continue runningin the background*/

#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>
#include<windows.h> // not needed in linux

int countTime(int minsCount)
{
     printf("Now Counting Time...");
     fflush(stdout);//if output sequence matters
     Sleep(60000);//in linux it is sleep and the number is in seconds. In windows it is Sleep and the time is milliseconds
     minsCount = minsCount + 1;
     return minsCount;
}

int main ()
{
     printf ("Starting Program!\n");
     int minutesCounter = 0;
     //int i = 0;
     while(1)
     {
          minutesCounter = countTime(minutesCounter);
          printf("%d \n", minutesCounter);
          FILE *f = fopen("DurationResult.txt", "r+");//rewrite the file (r+)
          if (f == NULL)
          {
              printf("Error opening file!\n");
              exit(1);
          }
          else
          {
               fprintf(f, "Duration was %d time units.\n", minutesCounter);//Time unit depends on OS!
               fclose(f);//open and close(save) the file in each iteration because
          }             //if for example the battery dies, then we will have the last time value.
     }
}
