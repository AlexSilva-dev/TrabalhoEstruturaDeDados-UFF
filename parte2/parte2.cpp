#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <threads.h>
#include <string.h>


typedef struct dados
{
    int m1[1000][1000];
    int m2[1000][1000];
    int resul[1000][1000];
    int parte;
}dados;


void *soma(void *d2) {

    
    dados *d = (dados*)d2;
    int comeco, fim;
    if((*d).parte == 0){
        comeco = 0;
        fim = 250;
    }else if((*d).parte ==1){
        comeco = 251;
        fim = 500;
    }else if((*d).parte == 2){
        comeco = 501;
        fim = 750;
    }else if( (*d).parte == 3){
        comeco = 751;
        fim = 1000;
    }

    //int a[1000][1000], b[1000][1000];
    for(int x =comeco; x<=fim; x++){
        for(int y = 0; y<=1000; y++){

            (*d).resul[x][y] = (*d).m1[x][y] + (*d).m2[x][y];
            }
    }

    
    
    thrd_exit(EXIT_SUCCESS);
}

int main(){
    dados *d1 = (dados*)malloc(sizeof(dados));
    thrd_t threads[4];
    int numThr = 4;
    int valor = 0;
    int valor2 = 2;
    int inf;

    for(int x =0; x<=1000; x++){
        for(int y = 0; y<=1000; y++){
            (*d1).m1[x][y] = valor++;
            (*d1).m2[x][y] = 2;
            //(*d1).resul[x][y] = 1;
            }
    }
    
    (*d1).parte = 0;
    for(int cont = 0; cont < numThr; cont++ ){

        inf = thrd_create(&threads[cont], (thrd_start_t) soma, (void *)d1);
        (*d1).parte++;
    }
    for(int x =0; x<=1000; x++){
        for(int y = 0; y<=1000; y++){
            printf("%d ", (*d1).resul[x][y]);
            }
    }
    return 0;
}