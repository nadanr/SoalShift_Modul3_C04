#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{
        key_t key = 1234;
        int *value;
        int menu;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);

        *value = 10;

        printf("Program 1 : %d\n", *value);

        sleep(5);

        printf("Program 1: %d\n", *value);
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
	menu();
        gets(menu);
        if(menu == '1'){
        
        }
        else if(menu == '2'){
        
        }
        else return 0;
}

void menu(void *arg){
    printf("SILAHKAN PILIH MENU YANG DIINGINKAN!\n");
    printf("1. Tambah senjata\n");
    printf("2. Lihat stock senjata\n\n");
    printf("Masukkan angka menu: ");
}
