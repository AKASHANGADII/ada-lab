#include<stdio.h>
#include<stdlib.h>
int count=0;
int euclid(int m,int n){
    count++;
    if(m%n==0){
        return n;
    }
    else{
        return euclid(n,m%n);
    }
}

int modified(int m,int n){
    while (n!=0)
    {
        count++;
        if(m>n){
            m=m-n;
        }
        else{
            n=n-m;
        }
    }return m;
    
}
int intCheck(int m,int n){
    int min=(m>n)? n:m;
    while(min>0){
        count++;
        if (n%min==0)
        {
            if (m%min==0)
            {
                return min;
            }
            
        }
        min--;
        
    }
}
void main(){
    int m,n,ch;
    printf("Enter the numbers>>");
    scanf("%d%d",&m,&n);
    for(;;){
        printf("\n\n1.Euclid's\n2.Modified Euclid's\n3.Concecutive integer checking\nEnter your choice>>");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("The gcd of %d and %d is %d",m,n,euclid(m,n));
            printf("The count is %d",count);
            count=0;
            break;
        case 2:
            printf("The gcd of %d and %d is %d",m,n,modified(m,n));
            printf("The count is %d",count);
            count=0;
            break;
        case 3:
            printf("The gcd of %d and %d is %d",m,n,intCheck(m,n));
            printf("The count is %d",count);
            count=0;
            break;
        default:exit(0);
            break;
        }
    }
}