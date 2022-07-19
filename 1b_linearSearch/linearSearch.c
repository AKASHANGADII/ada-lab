#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
void search(int *arr, int key,int size)
{
    int j;
    for(j=0;j<size;j++){
        count++;
        if(arr[j]==key){
            return;
        }
    }
}
void array(int *arr, FILE *fb, FILE *fa, FILE *fw, FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {
        arr = (int *)malloc(i * sizeof(int));
        for (j = 0; j < i; j++)
        {
            arr[j] = rand() % 100;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        printf("%d\n",i);
        //best case
        search(arr,arr[0],i);
        fprintf(fb,"%d\t%d\n",i,count);
        count=0;

        //avg case
        arr[i/2]=500;
        search(arr,500,i);
        fprintf(fa,"%d\t%d\n",i,count);
        count=0;

        //worst case
        arr[i-1]=550;
        search(arr,550,i);
        //printf("count for worst:%d\n",count);
        fprintf(fw,"%d\t%d\n",i,count);
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
    fclose(fb);
    fclose(fa);
    fclose(fw);
    fclose(fd);
}