#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>

const int N = 500;
const int BUFF_SIZE = 50;

key_t token;
int shmid;
int* ptr;

void main()
{
    int n;
    int c = 0;
    n = 2;
    char s[N];

    FILE *f, *o1, *o2;
    f = fopen("input.txt", "r");
    o1 = fopen("2019B5A70671H_t1.txt", "w");
    fscanf(f,"%d\n%s", &n, s);
    fclose(f);
    int len = strlen(s);
    char t[N];
    int x = 0,y = 0;


    //creating a process
    pid_t main_pid = getpid();
    int path[N];
    int i = 1;
    path[0] = 0;
    

    //shared memory
    shmid = shmget(token,BUFF_SIZE, 0666|IPC_CREAT);
    ptr = shmat(shmid,0,0);
    *ptr = 0;



    while(c<len && *ptr==0)
    {
        if(s[c] == '1')
        {
            if(fork())
            {
                y++;
            }
            else
            {
                y--;
            }
        }
        else
        {
            if(fork())
            {
                x++;
            }
            else
            {
                x--;
            }
        }

        path[i++] = (n+1)*y+x;
        if(x<0 || x>n || y<0 || y>n)
        {
            break;
        }
        if(*ptr == 0)
        {
            fprintf(o1, "Exploring Path: ");
            for(int j = 0;j<i;j++){

                fprintf(o1, "%d ", path[j]);
            }
            fprintf(o1, "\n");
            fflush(o1);
        }
        c++;
    }

    while(wait(NULL) >0);
    if(x == n && y == n)
    {
        if(*ptr == 0)
        {
            fprintf(o1, "Accepted! Followed path: ");
            for(int j = 0;j<i;j++){
                fprintf(o1, "%d ",path[j]);
            }
            fprintf(o1, "\n");
            fflush(o1);
            *ptr = getpid();
        }
    }
    else
    {
        if(*ptr == 0)
        {
            fprintf(o1, "Failed at path: ");
            for(int j = 0;j<i;j++){
                fprintf(o1, "%d ",path[j]);
            }
            fprintf(o1, "\n");
            fflush(o1);
        }

    }
}