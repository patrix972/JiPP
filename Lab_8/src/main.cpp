#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;


void eating(int n, mutex forks[]) {

    printf("Philosopher %d is thinking \n",n);

    forks[n].lock();
    forks[(n + 1) % 5].lock();


    printf("[+] Philosopher %d took forks \n", n);

    printf("Philosopher %d is eating \n", n);
    
    printf("[-] Philosopher %d put down forks \n", n);
    forks[n].unlock();
    forks[(n + 1) % 5].unlock();

}

int main() {

    thread phil[5];
    mutex forks[5];

    for (int i = 0; i < 5; i++) {
        phil[i] = thread(eating, i, forks);
    }


    for (int i  = 0; i < 5; i++) {
        phil[i].join();
    }

}