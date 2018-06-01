#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

#define SHSIZE 100

int main (int argc, char *argv[])
{
    int shmid;
    key_t key;
    char *shm;
    char *s;

    key = 9876;

    //Attach the shared Memory
    shmid = shmget(key, SHSIZE, 0666);
        if (shmid < 0)
    {
        perror("shmget");
        exit(1);
    }
    shm = shmat(shmid , NULL , 0);

    //Get the pointer to the shared Memory with that particular ID

    if (shm == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }
    //Read the content of the shared memory and print each char

   for (s = shm; *s !=0; s++)
        printf("%c", *s);
   printf("\n");
   //change the first char into * so that it will exit when checking
   *shm = "*";
    return 0;


}
