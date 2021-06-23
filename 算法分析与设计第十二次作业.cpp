#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<queue>
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
int color[100];
bool ok(int k ,int c[][100])
{
    int i,j;
    for(i=1;i<k;i++)
        if(c[k][i]==1&&color[i]==color[k])
        {
        	return false;
		}
        return true;
}
void graphcolor(int n,int m,int c[][100])
{
    int i,k;
    for(i=1;i<=n;i++)
    {
    	color[i]=0;
	}  
    k=1;
    while(k>=1)
    {
        color[k]=color[k]+1;
        while(color[k]<=m)
        {
        	if (ok(k,c))
			{
				break;
			}
            else
			{
				color[k]=color[k]+1;
			}
		}
        if(color[k]<=m&&k==n)
        {
            for(i=1;i<=n;i++)
            {
                printf("%d ",color[i]);
			}   
            printf("\n");
        }
        else if(color[k]<=m&&k<n)
        {
            k=k+1;
		}     
        else
        {
            color[k]=0;
            k=k-1;
        }
    }
}
int main()
{
    int i,j,n,m;
    int c[100][100];
    printf("输入顶点数n和着色数m:\n");
    scanf("%d %d",&n,&m);
    printf("输入无向图的邻接矩阵:\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
        {
        	scanf("%d",&c[i][j]);
		}
	}     
    printf("着色所有可能的解:\n");
    graphcolor(n,m,c);
}

