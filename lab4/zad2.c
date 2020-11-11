#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void catch_term( int sig_num )
{
  printf("SIGTERM caught!\n");
  exit(0);
}
void catch_alrm(int sig_num)
{
  printf("SIGALRM caught\n");
}
void catch_usr1(int sig_num)
{
  printf("USR1 caught\n");
  for(int i=0;i<10;i++)
    printf("%d",i);
}
void catch_usr2(int sig_num)
{

}

int main()
{

  signal(SIGTERM, catch_term);
  signal(SIGALRM, catch_alrm);
  signal(SIGUSR1, catch_usr1);
  signal(SIGUSR2, catch_usr2);
    while (1)
      {
        printf("Dzialam dalej...\n");
        sleep(1);
      }
    
    return 0;
}
