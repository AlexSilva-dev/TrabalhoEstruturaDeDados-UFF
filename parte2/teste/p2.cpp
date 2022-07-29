

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <threads.h>
#include <string.h>

#define tam 4

typedef struct dados
{
    int m1[tam][tam];
    int m2[tam][tam];
    int resul[tam][tam];
    int *parte;
}dados;


void *soma(void *d2) {

    
    dados *d = (dados*)d2;
    int comeco, fim, p;
    p = *(*d).parte;
    if(p == 0){
        comeco = (tam / 4) * p;
        fim = comeco + (tam/4);
    }else if(p ==1){
        comeco = ((tam) / 4)*p;
        fim = comeco + (tam/4);
    }else if(p == 2){
        comeco = (tam / 4)*p;
        fim = comeco + (tam/4);
    }else if( p == 3){
        comeco = (tam / 4)*p;
        fim = comeco + (tam/4);
    }

    //int a[1000][1000], b[1000][1000];
    for(int x =comeco; x<=fim; x++){
        for(int y = comeco; y<=tam; y++){

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
    
    for(int x =0; x<tam; x++){
        for(int y = 0; y<tam; y++){
            (*d1).m1[x][y] = 1;
            (*d1).m2[x][y] = 2;
            (*d1).resul[x][y] = 1;
            }
    }
    
    
    int *c = (int*)malloc(sizeof(int));
    *c = 0;
    (*d1).parte = c;
    for(int cont = 0; cont < numThr; cont++ ){

        inf = thrd_create(&threads[cont], (thrd_start_t) soma, (void *)d1);
        *c++;
        //*(*d1).parte = c;
        //thrd_join(threads[cont],NULL);
        
    }
    for(int c = 0; c<4; c++){
        thrd_join(threads[c],NULL);
    }
    for(int i = 0; i< 10000; i++){
        
        
    }
    
    for(int x =0; x<tam; x++){
        for(int y = 0; y<tam; y++){
            printf("%d ", (*d1).resul[x][y]);
            }
    }
    free(d1);
    return 0;
}