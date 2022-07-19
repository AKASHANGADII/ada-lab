#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *arr,int l,int mid,int r){
    int leftSize=mid-l+1;
    int rightSize=r-mid;
    int *leftArray=(int*)malloc(leftSize*sizeof(int));
    int *rightArray=(int*)malloc(rightSize*sizeof(int));
    int i,j;
    for(i=0;i<=leftSize;i++){
        leftArray[i]=arr[l+i];
    }
    for(i=0;i<=rightSize;i++){
        rightArray[i]=arr[mid+1+i];
    }
    i=j=0;
    int k=l;
    while(i<leftSize && j<rightSize){
        if(leftArray[i]<=rightArray[j]){
            arr[k]=leftArray[i];
            i++;
            k++;
        }
        else{
            arr[k]=rightArray[j];
            k++;
            j++;
        }
    }
    if(i==leftSize){
        while (j<rightSize)
        {
            arr[k]=rightArray[j];
            k++;
            j++;
        }
    }
    else{
        while (i<leftSize)
        {
            arr[k]=rightArray[i];
            k++;
            i++;
        }
    }
}
void divide(int *arr,int l,int r){
    int mid=(l+(r-l))/2;
    if(l>=r){
        return;
    }
    if(l<r){
        divide(arr,l,mid);
        divide(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void array(int *arr,FILE *fb, FILE *fa,FILE *fw,FILE *fd)
{
    int i,j;
    for (i = 10; i <= 100; i += 10)
    {
        printf("%d\n",i);
        arr = (int *)malloc(i*sizeof(int));
        for (j = 0; j < i; j++)
        {
            arr[j] = rand() % 100;
            fprintf(fd,"Loop executing");
            printf("%d ",arr[j]);
            fprintf(fd, "%d ", arr[j]);
        }
        fprintf(fd, "\n\n");
        printf("Sample");
        divide(arr,0,i);
        for(j=0;j<i;j++){
            fprintf(fd,"%d ",arr[j]);
            printf("%d ",arr[j]);
        }
        printf("25");
        fprintf(fd,"\n\n");
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

    fb=fopen("best.txt","a");
    fa=fopen("avg.txt","a");
    fw=fopen("worst.txt","a");
    fd=fopen("data.txt","a");
    fprintf(fd,"%d",5);
    array(arr,fb,fa,fw,fd);
}