2. Two threads thread] and thread2 are updating the common variable inside a critical section. Write a program using semaphore to ensure that only one thread can access the critical section at a time, to prevent the race condition.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
int common _variable = 10;
sem_t semaphore;
void *Incre(void *arg) {
int thread_id = *((int *)arg);
sem_wait(&semaphore);
int i= common_variable;
i+=1;
sleep(2);
common_variable =i;
printf("Thread %d updated common _variable to %d\n", thread_id, common _variable);
sem _post(&semaphore);
pthread_exit(NULL);
}
void *Decr(void *arg) {
int thread _id = *((int *)arg);
sem _wait{&semaphore);
int i= common_variable;
i=1;
common_variable =i;
printf("Thread %d decremented common variable to %d\n", thread_id, common_variable);
sem _post(&semaphore);
pthread_exit(NULL);
}
//next page continue

//next page question 2 multi threading
int main() {
sem_init(&semaphore, 0, 1);
pthread_t threadl, thread2;
int thread_id1 =1;
int thread_id2 =2;
pthread_create(&threadl, NULL, Incre, &thread_id1);
pthread_create(&thread2, NULL, Decr, &thread_id2);
pthread_join(threadl, NULL);
pthread_join(thread2, NULL);
sem_destroy(&semaphore);
printf("Final common_variable value: %d\n", common_variable);
return 0;
}
