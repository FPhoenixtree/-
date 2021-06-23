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
int t[maxn4];
int mid=0;
int sumTime=0;
int n;
int sum[maxn4][maxn4];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
	{
        cin>>t[i];
        sumTime+=t[i];
    }
    mid=sumTime/2;
    for(int i=1;i<=n;++i)
	{
        for(int j=1;j<=mid;++j)
		{
            if(j-t[i]>=0)
			{
                sum[i][j]=max(sum[i-1][j],sum[i-1][j-t[i]]+t[i]);
            }
			else
			{
                sum[i][j]=sum[i-1][j];
            }
        }
    }
    cout<<(sumTime-sum[n][mid])<<endl;
    return 0;
}


