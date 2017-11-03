#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[3];
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

void* beriMakan(){
    printf("Pilih hewan yang ingin diberi makan\n");
    printf("1.Kepiting\n");
    printf("2.Lohan\n");
    int menu;
    //printf("Masukkan pilihan > ");
    scanf("%d", &menu);
    
    if(menu == 1){
        kepiting+=10;
    }
    else if(menu == 2){
        lohan+=10;
    }
}

int main(void){
    pthread_create(&(tid[0]), NULL, &statusKep, NULL);
    pthread_create(&(tid[1]), NULL, &statusLoh, NULL);
    
    while(1){
        printf("Macam-macam hewan di kolam Aidil");
        printf("\nStatus Kepiting = %d\n",kepiting);
        printf("Status Lohan = %d\n",lohan);
        if(lohan <= 0 || kepiting <= 0 || lohan > 100 || kepiting > 100){
            printf("\n\nMaaf hewan peliharaan sudah mati\n\n");
            break;
        }
        pthread_create(&(tid[3]), NULL, &beriMakan, NULL);
        
        sleep(2);//tunggu 2 detik sebelum kasih makan lagi
    }
    
}
