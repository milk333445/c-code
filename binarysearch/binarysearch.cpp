#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#define MAX_SIZE 10000
using namespace std;
#define SWAP(x,y,t)(t=x,x=y,y=t)
void SelectionSort(int [], int);
int data[MAX_SIZE], n,x,mid;
int BinarySearch(int data[], int x, int left, int right)
{
    int mid;
    if (left <= right)
    {
        mid=(left+right)/2;
        if (data[mid] == x) return(mid);
        if (data[mid] < x)
            return BinarySearch(data, x, mid+1, right);
        else
            return BinarySearch(data, x, left, mid-1);
    }
    return -1;
}

void SelectionSort(int data[], int n)
{
    int i,j;
    int min,temp;
    for (i=0; i<n-1; i++)
    {
        min=i;
        for (j=i+1; j<n; j++)
        {
            if (data[min] > data[j])
                min=j;
        }
        SWAP(data[i],data[min],temp);
    }
}


void input_data()
{
    int i;
    printf("#data=");
    scanf("%d",&n);
    if (n<1 || n>MAX_SIZE)
    {
        fprintf(stderr,"improper value of data \n");
        exit(1);
    }
    for (i=0; i<n; i++)
    {
        data[i]=rand() % MAX_SIZE+1;
        printf("\n[%d]", data[i]);
    }
    printf("\n");
}



void print(int data[], int n)
{
    int i;
    printf("\nsorted array:\n");
    for (i=0; i<n; i++)
    {
        printf("[%d]\n", data[i]);
    }

}
clock_t t0,tx;
int main()
{
    input_data();
    t0=clock();
    SelectionSort(data, n);
    tx=clock();
    printf("-------------");
    print(data, n);
    getchar();
    printf("\n time(sec.)=%.6f\n",(float)(tx-t0)/CLOCKS_PER_SEC);
    printf("which number do yo want to search? ");
    scanf("%d",&x);
    mid=BinarySearch(data, x, 0, n);
    printf("data[%d]=%d",mid,data[mid]);

    return 1;
}

