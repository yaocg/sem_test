#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

static sem_t g_semaphore;
static const int g_iRunTimes = 100;

void* Fun(void* ptr)
{
  int iRunTime = 0;
  while(++iRunTime< g_iRunTimes)
  {
    sem_wait(&g_semaphore);
    cout<< "Fun() is running!" << endl;
    sem_post(&g_semaphore);
    usleep(10000);
  }
}


int main(void)
{
  pthread_t hHandle;
  sem_init(&g_semaphore, 0, 1);
  int iRet = pthread_create(&hHandle, NULL, Fun, NULL);        //create a thread;
  if(0 != iRet)
  {
    cout << "Create thread failed!" << endl;
    return -1;
  }

  sleep(1);

  int iRunTime = 0;
  while(++iRunTime<g_iRunTimes)
  {
    sem_wait(&g_semaphore);
    cout << "main is running!" << endl;
    sem_post(&g_semaphore);
    usleep(10000);
  }

  pthread_join(hHandle, NULL);
  return 0;
}
