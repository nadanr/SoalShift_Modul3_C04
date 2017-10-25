#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
 
pthread_t tid1;
pthread_t tid2;
int status;

FILE *in, *inn;
int hitungIfah( *argv ){
    int countIf=0;
    char simpan[1000];
    status = 0;

    in=fopen("Novel.txt", "r");
    
    while(fgets(simpan, 1000, in)!=NULL){
        if(strstr(simpan,"Ifah")){
            countIf++;        
        }
    }
    status = 1;
    printf("Ifah= %d\n", countIf);
    fclose(in);
}

int hitungFina( *argv ){
    int countFi=0;
    char simpan2[1000];
    
    while(status!=1){
    
    }
    
    inn = fopen("Novel.txt", "r");
    
    while(fgets(simpan2, 1000, inn)!=NULL){
        if(strstr(simpan2, "Fina")){
            countFi++;        
        }    
    }
    printf("Fina = %d\n", countFi);
    fclose(inn);
}

int main( void *arg ){
    pthread_create(&(tid1), NULL, &hitungFina, NULL);
    pthread_create(&(tid2), NULL, &hitungIfah, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
