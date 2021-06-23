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
#define MAXN 10000 + 10
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI=3.14159;
const int maxn6=1e6+10;
const int maxn5=1e5+10;
const int maxn4=1e4+10;
int par[MAXN], Rank[MAXN];
typedef struct{
    int a, b, price;
}Node;
Node a[MAXN];
int cmp(const void*a, const void *b){
    return ((Node*)a)->price - ((Node*)b)->price;
}
void Init(int n){
    for(int i = 0; i < n; i++){
        Rank[i] = 0;
        par[i] = i;
    }
}
int find(int x){
    int root = x;
    while(root != par[root]) root = par[root];
    while(x != root){
        int t = par[x];
        par[x] = root;
        x = t;
    }
    return root;
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(Rank[x] < Rank[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}
int Kruskal(int n, int m){
    int nEdge = 0, res = 0;
    qsort(a, n, sizeof(a[0]), cmp);
    for(int i = 0; i < n && nEdge != m - 1; i++){
        if(find(a[i].a) != find(a[i].b)){
            unite(a[i].a, a[i].b);
            res += a[i].price;
            nEdge++;
        }
    }
    if(nEdge < m-1) res = -1;
    return res;
}
int main(){
    int n, m, ans;
    while(scanf("%d%d", &n, &m), n){
        Init(m);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].price);
            a[i].a--;
            a[i].b--;
        }
        ans = Kruskal(n, m);
        if(ans == -1) printf("?\n");
        else printf("%d\n", ans);
    }
    return 0;
}
