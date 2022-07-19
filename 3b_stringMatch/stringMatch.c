#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
void match(int *arr,int *ptn,int a,int p){
    int i,j;
    i=0;
    while(i<a-p){
        j=0;
        while(j<p && arr[i+j]==ptn[j]){
            j++;
            count++;
        }
        if(j==p){
            return;
        }
        i++;
    }
}

void array(int *arr,FILE *fb, FILE *fa,FILE *fw,FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {   
        int ptn[4]={0};
        arr = (int *)malloc(i * sizeof(int));
        for (j = 0; j < i; j++)
        {
            arr[j] = 0;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");

        //best case
        match(arr,ptn,i,4);
        fprintf(fb,"%d\t%d\n",i,count);
        count=0;

        //worst case
        arr[i-1]=1;
        ptn[3]=1;
        match(arr,ptn,i,4);
        fprintf(fw,"%d\t%d\n",i,count);
        count=0;

        //average case
        arr[(i/2)+2]=1;
        match(arr,ptn,i,4);
        fprintf(fa,"%d\t%d\n",i,count);
        count=0;
        

        
    }
}

void main()
{
    int ch;
    int *arr;
    srand(time(0));
    FILE *fb, *fa, *fw, *fd;
    system("del best.txt");
    system("del avg.txt");
    system("del worst.txt");
    system("del data.txt");

    fb = fopen("best.txt", "a");
    fa = fopen("avg.txt", "a");
    fw = fopen("worst.txt", "a");
    fd = fopen("data.txt","a");
    array(arr,fb,fa,fw,fd);
}