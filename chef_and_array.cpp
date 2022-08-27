#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5;
const int MAXM=1e8;
int n, m;
int X, Y;
int f[20][MAXN+5];
char lg[MAXN+5];
int main(){
//    freopen("FRMQ.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>f[0][i];
    }
    for(int i=1; (1<<i)<=n; i++){
        for(int j=0; j+(1<<i)-1<n; j++){
            f[i][j]=max(f[i-1][j], f[i-1][j+(1<<i-1)]);
        }
    }
    for(int i=0, j=0; i<=n; i++, j++){
        lg[i]=j;
        while(i<n && i+1<(1<<j+1)){
            i++;
            lg[i]=j;
        }
    }
    ll res=0;
    cin>>m>>X>>Y;
    while(m--){
        int L=min(X, Y), R=max(X, Y);
        short len=lg[R-L+1];
        res+=max(f[len][L], f[len][R-(1<<len)+1]);
        X+=7;
        Y+=11;
        while(X>=n-1) X-=n-1;
        while(Y>=n) Y-=n;
    }
    cout<<res;
    return 0;
}
