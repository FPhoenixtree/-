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
int T[maxn6];
int main()
{
	int n,x,a=0;
	cin >> n >> x;
	for(int i=1;i<=n;i++)
	{
		cin >> T[i];
		if(T[i]==x)
		{
			a=i;
		}
	}
	cout << a;
	return 0;
}

