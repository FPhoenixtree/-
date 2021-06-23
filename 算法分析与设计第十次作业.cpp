#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
#include<vector>
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
int n,cw,bestw,r,c1,c2,x[100],bestx[100],w[100];
void OutPut()
{
    int restweight=0;
    for(int i=1;i<=n;++i)
    {
    	if(bestx[i]==0)
        {
        	restweight+=w[i];
		}
	}     
    for(int i=1;i<=n;++i)
    {
    	if(bestx[i]==1)
        {
       	printf(" %d", i);
		}
	} 
	printf("\n");
    for(int i=1;i<=n;++i)
    {
        if(bestx[i]!=1)
        {
        	printf(" %d",i);
		}
	}
}
void BackTrack(int i)
{
    if(i>n)
    {
        if(cw>bestw)
        {
            for(int i=1;i<=n;++i)
            {
            	bestx[i]=x[i];
			} 
            bestw=cw;
        }
        return;
    }
    r-=w[i];
    if(cw+w[i]<=c1) 
    {
        cw+=w[i];
        x[i]=1;
        BackTrack(i+1);
        x[i]=0;
        cw-=w[i];
    }
    if(cw+r>bestw) 
    {
        x[i]=0;
        BackTrack(i+1);
    }
    r+=w[i];
}
void Initialize()
{
    bestw=0;
    r=0;
    cw=0;
    for(int i=1;i<=n;++i)
    {
    	r+=w[i];
	}
}
void InPut()
{
    scanf("%d",&n);
    scanf("%d %d",&c1,&c2);
    for(int i=1;i<=n;++i)
    {
    	scanf("%d",&w[i]);
	}
}
int main()
{
    InPut();
    Initialize();
    BackTrack(1);
    OutPut();
}
