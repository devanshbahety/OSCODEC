4. Create a program that simulates a simple bank with multiple accounts and multipleclients making deposits (threadl) and withdrawals (thread2) concurrently. The goal is to ensure that account balances remain consistent even with concurrent operations. Use mutex locks to implement this.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_Client 5
int account[9] = {550, 450, 300, 700, 500, 600, 400, 800, 350};
pthread_mutex_t lock;
void* Deposit(void* arg) {
int* client_id = (int*)arg;
int amount, x, k;
k=rand() % (10);
printf("\n Enter amount to deposit");
scanf("%d",&amount);
pthread_mutex_lock(&lock);
x=account[k];
x =x + amount;
account[k]=x;
pthread_mutex_unlock(&lock);
printf("Client %d deposited: %d, Amount after deposit is %d\n", *client_id, amount,
account[k]);
pthread _exit(NULL);
}
void* Withdraw(void* arg) {
int* client_id = (int*)arg;
int amount, x,k;
k=rand() % (10);
//next page q4 multithreading bank
//next page
printf("\n Enter amount to withdraw");
scanf("%d",&amount);
pthread_mutex_lock(&lock);
x=account[k];
x =x - amount;
account[k]=x;
pthread_mutex_unlock(&lock);
printf{"' Client %d withdraw: %d, Amount after withdrawl is %d\n", *client_id, amount,
account[k]);
pthread_exit(NULL);
}
int main() {
pthread_t threads[NUM_Client];
pthread_mutex_init(&lock, NULL);
int client_ids[NUM_ Client], i;
for (i= 0; i < NUM_Client; i++) {
client_ids[i] =i;
}
for(i=0;i<NUM_Client;i++){
if(i%2==0){
pthread_create(&threads[i], NULL, Deposit, &client_ids[i]);}
else
pthread create(&threads[i], NULL, Withdraw, &client_ids[i]);
}

}
for (i= 0; i <NUM_Client; i++) {
pthread_join(threads[i], NULL),
}
return 0;
}
