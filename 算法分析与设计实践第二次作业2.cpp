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
const int INF=0x3f3f3f3f3f;
const int maxn6=1e6+10;
const int maxn5=1e5+10;
const int maxn4=1e4+10;
int a[100][100],dis[100],vis[100]={0};
void dijkstra(int n,int b)
{
	dis[b]=0;
	for(int i=1;i<=n;i++)
	{
		dis[i]=a[b][i];
	}
	vis[b]=1;
	for(int i=1;i<=n;i++)
	{
		int m;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0)
			{
				m=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(vis[j]!=1)
			{
				if(a[b][j]<a[b][m])
				{
					m=j;
				}
			}
		}
		vis[m]=1;
		for(int j=1;j<=n;j++)
		{
			if(a[b][m]+a[m][j]<a[b][j])
			{
				a[b][j]=a[b][m]+a[m][j];
				dis[j]=a[b][j];
			}
		}
	}
} 
int main()
{
	int n,b,l;
	scanf("%d%d%d",&n,&b,&l);
	int m;
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				a[i][j]=INF;
			}
			else
			{
				a[i][j]=0;
			}
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t1==b)
		{
			dis[t2]=t3;
		}
		a[t1][t2]=t3;
	}
	dijkstra(n,b);
	printf("%d",dis[l]);
	return 0;
}
