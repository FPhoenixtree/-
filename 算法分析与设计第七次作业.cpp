#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
#include<cstdlib>
#include<vector>
#include<stdexcept>
#include<fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI=3.14159;
const int maxn6=1e6+10;
const int maxn5=1e5+10;
const int maxn4=1e4+10;
int main() {
	int m,n;
	int i,j;
	int tmp_m,tmp_F=0;
	cin>>m>>n;
	vector<vector<int> > f(n,vector<int>(m + 1));
	vector<vector<int> > F(n,vector<int>(m + 1));
	for(i=0;i<n;++i)
	{
		f[i][0]=0;
	}
	for(i=0;i<n;++i)
	{
		for(j=1;j<m+1;++j)
		{
			cin>>f[i][j];
		}
	}
	for(j=0;j<m+1;++j)
	{
		F[0][j]=f[0][j];
	}
	for(i=1;i<n;++i)
	{
		for(j=0;j<m+1;++j)
		{
			for(tmp_m=0;tmp_m<=j;++tmp_m)
			{
				tmp_F=F[i-1][j-tmp_m]+f[i][tmp_m];
				if(tmp_F>F[i][j])
				{
					F[i][j]=tmp_F;
				} 
			}
		}
	}
	cout<<F[n-1][m]<<endl;
}
