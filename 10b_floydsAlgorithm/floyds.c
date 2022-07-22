#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void floyds(int arr[4][4]){
    int i,j,k;
    for(k=0;k<4;k++){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                    arr[i][j]=(arr[i][j]<(arr[i][k]+arr[k][j])? arr[i][j]:arr[i][k]+arr[k][j]);
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int arr[4][4],i,j;
    int n=4;
    
    printf("Enter the array elements>>");
    for(i=0;i<n;i++){
        for(j=0;j<4;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    floyds(arr);
}