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
int n,a;
priority_queue<int, vector<int>, greater<int> >qu;
queue<int>res;
void slove(){
	while(qu.size()!=1){
		int a=qu.top();
		qu.pop();
		int b=qu.top();
		qu.pop();
		int c=a+b;
		res.push(a);
		res.push(b);
		qu.push(c);
	}
	printf("��������Ϊ:\n");
	while(!res.empty()){
		printf("����%lld��",res.front());
		res.pop();
		printf("%lld\n",res.front());
		res.pop();
	}
	printf("���ս��Ϊ:%lld\n",qu.top()); 
}
int main() {
	printf("��������n\n");
	cin>>n;
	printf("������ÿһ���ַ���Ƶ��:\n");
	for(int i=1;i<=n;i++){
		cin>>a;
		qu.push(a);
	}
	slove();
	return 0;
}
