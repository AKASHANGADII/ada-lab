#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;
void search(int *arr,int key,int size){
    int mid,start,end;
    start=0;
    end=size-1;
    while(start<=end){
        mid=(start+end)/2;
        count++;
        if(arr[mid]==key){
            return;
        }
        if (key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
}

void array(int *arr, FILE *fb, FILE *fa,FILE *fw,FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {
        arr = (int *)malloc(i * sizeof(int));
        for (j = 0; j < i; j++)
        {
            arr[j] =(j==0) ? rand() % 10:arr[j-1]+1;
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
    }

    //Best case 
    search(arr,arr[i/2],i);
    fprintf(fb,"%d\t%d\n",i,count);
    count=0;

    //Avg case
    search(arr,arr[i/4],i);
    fprintf(fa,"%d\t%d\n",i,count);
    count=0;

    //Worst case
    search(arr,arr[0],i);
    fprintf(fw,"%d\t%d\n",i,count);
    count=0;

}

void main()
{
    int ch;
    int *arr;
    srand(time(0));
    FILE *fb, *fa, *fw, *fd;
    system("rm best.txt");
    system("rm avg.txt");
    system("rm worst.txt");
    system("rm data.txt");

    fb = fopen("best.txt", "a");
    fa = fopen("avg.txt", "a");
    fw = fopen("worst.txt", "a");
    fd = fopen("data.txt","a");
    array(arr,fb,fa,fw,fd);
}