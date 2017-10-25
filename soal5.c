#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
 
FILE *in;

void* hitung( void *arg ){
    int countIf=0;
    int count=0, j, i, wordLen;
    int found;
    char* cari=(char *) arg;
    //status = 0;
    char simpan[1500];
    //int line_num = 1;

    in=fopen("/home/nadanr/SISOP/Novel.txt", "r");

    while(fgets(simpan, 2000, in)!=NULL){
        while(simpan[count]!='\0'){
        count++;
    }
   
     wordLen = strlen(cari);//find length of the word

        for(i=0; i<count-wordLen; i++){
        
            found = 1;
            for(j=0; j<wordLen; j++){
                if(simpan[i + j] != cari[j]){
                    found = 0;
                    break;
                }
            }
            
            if(found == 1){
                countIf++;
            }
        }    
    }
    fclose(in);
    printf("%s = %d\n", cari, countIf);
    //return;
}

int main(int j, char **arg)
{
    pthread_t t[j];
    int i;
    i = j;
    while(--j){
        pthread_create(&t[j], NULL, &hitung, arg[j]);
        pthread_join(t[j], NULL);    
    }
}
