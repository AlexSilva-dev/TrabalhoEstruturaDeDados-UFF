#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <threads.h>
#include <string.h>


void *printHello(void *nome) {

    //char n [20];
    //n = *(char*)nome;
    for(int i; i<100; i++){
        printf("Eu sou a thread %s e meu ID é %lu\n", (char*)nome, thrd_current());
    }
    thrd_exit(EXIT_SUCCESS);
}

int main(int argc, char const *argv[]) {
    int numT = 2;
    thrd_t threads[numT];
    int rc;
    int t;

    for (t = 0; t <= numT; t++) {
        char euSou [12];
        char num [3];
        sprintf(num, "%d", t);
        strcat(strcpy(euSou, "thread_0"), num);
        printf("\n%s \n %s\n",num,euSou);
        rc = thrd_create(&threads[t], (thrd_start_t) printHello, (void *)euSou);
        if (rc == thrd_error) {
            printf("ERORR; thrd_create() call failed\n");
            exit(EXIT_FAILURE);
        }
    }
    thrd_exit(EXIT_SUCCESS);
    return 0;

}
