#include <nuttx/config.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_func(void *arg)
{
  while (1)
    {
      printf("Thread %ld running\n", (long)arg);
      sleep(2);
    }
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t t1, t2;
  pthread_create(&t1, NULL, thread_func, (void *)1);
  pthread_create(&t2, NULL, thread_func, (void *)2);

  while (1)
    {
      printf("Main task running\n");
      sleep(3);
    }
  return 0;
}
