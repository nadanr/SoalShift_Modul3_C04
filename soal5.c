#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
char simpan[2000];
char simpan2[2000];
FILE *in, *inn;

void* hitung( void *arg ){
    int countIf=0;
    int count=0, j, i, f, a, h, space;
    status = 0;
    //int line_num = 1;

    in=fopen("/home/nadanr/SISOP/Novel.txt", "r");

    while(fgets(simpan, 2000, in)!=NULL){
        while(simpan[count]!='\0'){
        count++;
    }
    //printf("count = %d\n\n", count);

    /*for(j=0; j<=count-4; j++){
        i = (simpan[j] == 'i' || simpan[j] == 'I' );
        f = (simpan[j+1] == 'f' || simpan[j+1] == 'F' );
        a = (simpan[j+2] == 'a' || simpan[j+2] == 'A' );
        h = (simpan[j+3] == 'h' || simpan[j+3] == 'H' );
        //space = (simpan[j+4] == ' ' || simpan[j+4] == '\0');
        if((i && f && a && h ) ==1){
            countIf++;
        }
    }*/
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
    printf("%s = %d\n", cari, countIf);
    //return;
}
    
    /*while(fgets(simpan, 1000, in)!=NULL){
        if(strstr(simpan,"Ifah")!=NULL){
            //printf("A match found on line number = %d\n", line_num);
            //printf("\n%s\n", simpan);
            countIf++;        
        }
        line_num ++;
    }*/
    //status = 1;
    fclose(in);
    //printf("Ifah = %d\n", countIf);
    
}

/*void* hitungFina( void *arg ){
    int countFi=0;
    int count=0;
    int j, f, i, n, a, space;
    while(status!=1){
    
    }
    
    inn = fopen("/home/nadanr/SISOP/Novel.txt", "r");
    
    while(fgets(simpan2, 2000, inn)!=NULL){
        while(simpan2[count]!='\0'){
        count++;
    }
    //printf("count = %d\n\n", count);

    for(j=0; j<=count-4; j++){
        f = (simpan2[j] == 'f' || simpan2[j] == 'F' );
        i = (simpan2[j+1] == 'i' || simpan2[j+1] == 'I' );
        n = (simpan2[j+2] == 'n' || simpan2[j+2] == 'N' );
        a = (simpan2[j+3] == 'a' || simpan2[j+3] == 'A' );
        //space = (simpan2[j+4] == ' ' || simpan2[j+4] == '\0');
        if((f && i && n && a )==1){
            countFi++;
        }
    }
}
    /*while(fgets(simpan2, 1000, inn)!=NULL){
        if(strstr(simpan2, "Fina")){
            countFi++;        
        }    
    }*/
    /*fclose(inn);
    printf("Fina = %d\n", countFi);
    
}*/

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
