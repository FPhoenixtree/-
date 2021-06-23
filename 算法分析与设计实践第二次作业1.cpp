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
const int INF=0x3f3f3f3f;
const int maxn6=1e6+10;
const int maxn5=1e5+10;
const int maxn4=1e4+10;
void floyd(int a[100][100],int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[i][k]+a[k][j]<a[i][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[100][100];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				a[i][j]=INF;
				a[j][i]=INF;
			}
			else
			{
				a[i][j]=0;
			}
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int a1,a2,a3;
		scanf("%d %d %d",&a1,&a2,&a3);
		a[a1][a2]=a3;
	}
	floyd(a,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=INF)
			{
				printf("%5d ",a[i][j]);
			}
			else
			{
				printf("-1 ");
			}
		}
		printf("\n");
	}
	return 0;
}

