#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

typedef struct param_str{
    char nome [10];
}Tstr;

void *printthread(void *i) {
    char *ptr;
    ptr = &(*(( char* )i));
    printf("Eu sou a %s e meu ID é %lu\n",ptr,thrd_current());
    thrd_exit(EXIT_SUCCESS);
}

int main (){

    int N;
    scanf("%d",&N);
    thrd_t thread[N];
    Tstr param;
    char num[3];
    int thrd;
    for (int i = 0; i < N; i++){
        char aux[10] = "thread_0";
        sprintf(num,"%d",i+1);
        strcat(aux,num);//cria uma string de nome "thread_0x".
        strcpy(param.nome,aux);
        thrd = thrd_create(&thread[i],(thrd_start_t) printthread,(void*)param.nome);// segundo parametro é de uma função que a thread irá executar
    }
    
    for(int j = 0; j < N; j++){
       thrd_join(thread[j],NULL);
    }
    
    thrd_exit(EXIT_SUCCESS);

    return 0;
}