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
int arr[100];
int m[20];
int sort(int arr[],int l,int r)
{
	int i,j;
	int s;
	for (i=l;i<=r;i++)
	{
		for(j=i+1;j<=r;j++)
		{
			if(arr[i]>arr[j])
			{
				s=arr[i];
				arr[i]=arr[j];
				arr[j]=s;
			}
		}
	}
} 
int select(int arr[],int n,int l,int r,int k)
{
	int num=r-l+1;
	int s=num/5;
	int i=0;
	int count=0;
	int mid;
	int j=0;
	for(i=l;i<=r;i)
	{
		sort(arr,i,i+(i+4<=r?4:r-i));
		m[j]=arr[l+(i+4<=r?(i+2):(r+i/2))];
		count=j++;
		i+=5;
	}
	sort(m,0,count);
	mid=m[count/2];
	int a1[100],c1=0;
	int a2=mid;
	int a3[100],c3=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]>mid)
		{
			a3[c3]=arr[i];
			c3++;
		}
		else if(arr[i]<mid)
		{
			a1[c1]=arr[i];
			c1++;
		}
	}	
	if(k<=c1)
	{
		return select(a1,c1,0,c1-1,k);
	}
	else if(k>c1+1)
	{
		return select(a3,c3,0,c3-1,k-1-c1);
	}
	else if(k=c1+1)
	{
		return a2;
	}	 
}
int main()
{
	int k;
	int n;
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int end = select(arr,n,0,n-1,k);
	printf("%d",k,end);
	return 0;
}
