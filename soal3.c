#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int kepiting=100, lohan = 100, makan = 10;
void* statusKep(){
    while(1){
        sleep(20);
        kepiting-=10;
    }
}

void* statusLoh(){
    while(1){
        sleep(10);
        lohan-=15;
    }
}

