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
#define MAX 100
#define MAXCOST 0x7fffffff
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI=3.14159;
const int maxn6=1e6+10;
const int maxn5=1e5+10;
const int maxn4=1e4+10;

int graph[MAX][MAX];
int prim(int graph[][MAX], int n)
{
	int lowcost[MAX];
	int mst[MAX];
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; i++)
	{
		lowcost[i] = graph[1][i];
		mst[i] = 1;
	}
	mst[1] = 0;
	for (i = 2; i <= n; i++)
	{
		min = MAXCOST;
		minid = 0;
		for (j = 2; j <= n; j++)
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;
		sum += min;
		lowcost[minid] = 0;
		for (j = 2; j <= n; j++)
		{
			if (graph[minid][j] < lowcost[j])
			{
				lowcost[j] = graph[minid][j];
				mst[j] = minid;
			}
		}
	}
	return sum;
}
int main()
{
	int i, j, k, m, n;
	int x, y, cost;
	ifstream in("input.txt");
	in >> m >> n;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	for (k = 1; k <= n; k++)
	{
		in >> i >> j >> cost;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	cost = prim(graph, m);
	cout << "最小权值和=" << cost << endl;
	system("pause");
	return 0;
}


