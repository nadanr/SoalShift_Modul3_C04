#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
char simpan[1000];
char simpan2[1000];
FILE *in, *inn;

void* hitungIfah( void *arg ){
    int countIf=0;
    status = 0;

    in=fopen("/home/nadanr/SISOP/Novel.txt", "r");
    
    while(fgets(simpan, 1000, in)!=NULL){
        if(strstr(simpan,"Ifah")){
            countIf++;        
        }
    }
    status = 1;
    fclose(in);
    printf("Ifah = %d\n", countIf);
    
}

void* hitungFina( void *arg ){
    int countFi=0;
    
    while(status!=1){
    
    }
    
    inn = fopen("/home/nadanr/SISOP/Novel.txt", "r");
    
    while(fgets(simpan2, 1000, inn)!=NULL){
        if(strstr(simpan2, "Fina")){
            countFi++;        
        }    
    }
    fclose(inn);
    printf("Fina = %d\n", countFi);
    
}

int main( void *arg ){
    pthread_create(&(tid1), NULL, &hitungFina, NULL);
    pthread_create(&(tid2), NULL, &hitungIfah, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
