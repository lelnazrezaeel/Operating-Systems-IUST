#include "types.h"
#include "stat.h"
#include "user.h"

int wx(int* wtime, int* rtime)
{
    return waitx(wtime,rtime);
}

int main(int argc, char *argv[])
{
    int wtime;
    int rtime;

    int a = fork();
    
    if(a>0){
        int npid=fork();
        if(npid==0){
            malloc( 1710 * (sizeof(int)));
            exit();
        }

        int nnpid=fork();
        if(nnpid==0){
            malloc(1750 * (sizeof(int)));
            exit();
        }

        wx(&wtime,&rtime);
        printf(1,"\n*************in user level*************\n");
        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);
//        printf(1,"\n");
//        wait();
//        wait();
//        wait();
        wx(&wtime,&rtime);
        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);
        wx(&wtime,&rtime);
        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);
        wx(&wtime,&rtime);
        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);

        exit();
    }
    else
    {
        if(fork()){
            malloc(1700 * (sizeof(int)));
            if (fork())
            {
                malloc(1008 * (sizeof(int)));
                wait();
                wait();
                exit();
            }
            else
            {
                malloc(1800 * (sizeof(int)));
                exit();
            }

        }else{
            malloc(1090 * (sizeof(int)));
            if (fork())
            {
                malloc( 1030 * (sizeof(int)));
                wait();
                exit();
            }
            else
            {
                malloc(1100 * (sizeof(int)));
                exit();
            }
        }

    }
}