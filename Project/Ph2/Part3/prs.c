#include "types.h"
#include "stat.h"
#include "user.h"

int wx(int* wtime, int* rtime)
{
    return waitx(wtime,rtime);
}

int main(int argc, char *argv[])
{
    int a = fork();
    
    if(a>0){
        int npid=fork();
        if(npid==0){
            malloc( 1710 * (sizeof(int)));
            int tmp=set_priority(get_pid(),50);
            yield();
            printf(1,"%d\n",tmp);
            exit();
        }

        int nnpid=fork();
        if(nnpid==0){
            malloc(1750 * (sizeof(int)));
            int tmp=set_priority(get_pid(),51);
            yield();
            printf(1,"%d\n",tmp);

            exit();
        }

//        wx(&wtime,&rtime);
//        printf(1,"\n*************in user level*************\n");
//        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);
//        printf(1,"\n");
        wait();
        wait();
        wait();
        wait();
//        wx(&wtime,&rtime);
//        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);
//        wx(&wtime,&rtime);
//        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);
//        wx(&wtime,&rtime);
//        printf(1,"wait time= %d, run time= %d\n ",wtime,rtime);

        exit();
    }
    else
    {
        if(fork()){
            malloc(1700 * (sizeof(int)));
            if (fork())
            {
                malloc(1008 * (sizeof(int)));
                int tmp=set_priority(get_pid(),53);
                yield();
                printf(1,"%d\n",tmp);

                wait();
                wait();
                wait();

                exit();
            }
            else
            {
                malloc(1800 * (sizeof(int)));
                int tmp=set_priority(get_pid(),54);
                yield();
                printf(1,"diff:%d\n",tmp);
                tmp=set_priority(get_pid(),42);
                yield();
                printf(1,"diff2:%d\n",tmp);

                //---------------------------------------------------------------------------------------------
                exit();
            }


        }else{
            malloc(1090 * (sizeof(int)));
            if (fork())
            {
                malloc( 1030 * (sizeof(int)));
                int tmp=set_priority(get_pid(),55);
                yield();
                printf(1,"%d\n",tmp);
                wait();

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