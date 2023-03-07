#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;
#define SWAP(x,y,t)(t=x,x=y,y=t)

void towerHanoi(int n, char A, char B, char C)
{
    if (n==0) return;
    towerHanoi(n-1,A, C, B);
    printf("move disk %d from %c to %c \n",n,A,C);
    towerHanoi(n-1, B, A, C);

}

float sum(float list[], int n)
{
    float tempsum;
    int i;
    for (i=0; i<n; i++)
        tempsum+=list[i];
    return tempsum;
}

long Factorial(long n)
{
    if (n==1 || n==0)
        return 1;
    else
        return (n*Factorial(n-1));
}

void perm(char c[], int k, int n)
{
    if (k==n-1)
    {
        for (int i=0; i<n; i++)
            printf("%c ",c[i]);
        printf("\n");
    }
    else
    {

        for (int i=k; i<n; i++)
        {
           char temp;
           SWAP(c[k],c[i],temp);
           perm(c,k+1,n);
           SWAP(c[k],c[i],temp);
        }

    }
}

int main()
{

}
