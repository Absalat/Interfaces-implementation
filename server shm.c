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
    //Create Shared Memory

    key = 9876;

    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget");
        exit(1);
    }

    //Attach Shared Memory

    shm = shmat(shmid , NULL , 0);

    //Get Pointer to the Memory

    if (shm == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }

    //Write Something on the memory

    memcpy(shm, "Hello World", 11);

    //Add Null (0) at the end of the shared memory

    s = shm;
    s += 11;

    *s = 0;

    //If the first char in the memory is * it will exit, if not it will wait 1 sec and check again
    while (*smh != "*")
        sleep (1;)
    return 0;


}
