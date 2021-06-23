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
int n;
int p[101],m[100][100],s[100][100];

void MatrixChain()
{
	int j=0;
	int t=0; 
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=2;r<=n;r++)
    {
        for(int i=1;i<=n-r+1;i++)
        {
            int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j])
                {
                    s[i][j]=k;
                    m[i][j]=t;
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
    {
    	cin>>p[i];
	}
    MatrixChain();
    cout<<m[1][n]<<endl;
    return 0;
}

