#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count=0;

void sort(int *arr,int size,FILE *fd){
    int min,i,j;

    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++){
            count++;
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    // fprintf(fd,"After sorting>>\n");
    // for(i=0;i<size;i++){
    //     fprintf(fd,"%d ",arr[i]);
    // }
    // fprintf(fd,"\n\n\n");
}
void array(int *arr,FILE *f, FILE *fd)
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
        sort(arr,i,fd);
        fprintf(f,"%d\t%d\n",i,count);
        count=0;
    }
    
}

void main()
{
    int ch;
    int *arr;
    srand(time(0));
    FILE *f, *fd;
    system("del output.txt");
    system("del data.txt");

    f = fopen("output.txt", "a");
    fd = fopen("data.txt","a");
    array(arr,f,fd);
}