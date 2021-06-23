#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
#include<cstdlib>
#include<stdexcept>
#include<fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI=3.14159;
const int maxn6=1e6+10;
const int maxn5=1e5+10;
const int maxn4=1e4+10;
void Merge(int A[], int p, int q, int r)
{
	int *L, *R,x,y;
	x=q-p+1,y=r-q;
	L = (int*)malloc(sizeof(int)*x);
	R = (int*)malloc(sizeof(int)*y);
	int i,j;
	for(i=0;i<x;i++)
		L[i]=A[i+p];
	for(j=0;j<y;j++)
		R[j]=A[j+q+1];
	i=j=0;
	int k=p;
	while(i<x && j<y)
	{
		if (L[i]<=R[j])
			A[k++]=L[i++];
		else
			A[k++]=R[j++];
	}
	while(i<x)
	{
		A[k++]=L[i++];
	} 
	while(j<y)
	{
		A[k++]=R[j++];
	}
	free(L);
	free(R);
}
int MergeSort(int A[],int p,int r)
{
	if(p<r)
	{
		int q=(p + r) / 2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
    MergeSort(a,0,9);
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
