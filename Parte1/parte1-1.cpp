#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <threads.h>
#include <string.h>


typedef struct dados
{
    int numThr
};

void *printThr(void *nome) {
    char euSou [12];
    char num [3];
    sprintf(num, "%d", n);
    strcat(strcpy(euSou, "thread_0"), num);



    printf("Eu sou a thread %s e meu ID é %lu\n", (char*)nome, thrd_current());
    
    thrd_exit(EXIT_SUCCESS);
}

int main(int argc, char const *argv[]) {
    int numT = 0;
    printf("Digite a quantidade de Threads: ");
    scanf("%d", &numT);
    thrd_t threads[numT];
    int rc;
    int n;

    for (n = 0; n <= numT; n++) {
        
        //printf("\n%s \n %s\n",num,euSou);
        rc = thrd_create(&threads[n], (thrd_start_t) printThr, (void *)euSou);
        if (rc == thrd_error) {
            printf("Erro!\n");
            exit(EXIT_FAILURE);
        }
    }
    thrd_exit(EXIT_SUCCESS);
    return 0;

}
