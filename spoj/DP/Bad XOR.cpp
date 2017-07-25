#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1000];
int b[1000];
int dp[2][1024];
const LL mod = 1e8+7;
LL quick(LL n,LL m);
const int BufferSize=1<<16;
char buffer[BufferSize],*head,*tail;
inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,BufferSize,stdin);
        tail=(head=buffer)+l;
    }
    return *head++;
}
inline int read() {
    int x=0,f=1;char c=Getchar();
    for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
    return x*f;
}
int main (void)
{
    int T,__cn = 0;
    T = read();
    while(T--)
    {
 
        int n,m;
        int maxx = 0;
        n = read(),m = read();
        for(int i = 1; i <= n; i++)
            a[i] = read(),maxx = max(maxx,a[i]);
        for(int i = 0; i < m; i++)
            b[i] = read();
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        int u;
        for(int i = 1; i <= n; i++)
        {
            if(i%2)u = 1;
            else u = 0;
            for(int j = 0; j < 1024; j++)
                dp[u][j] = dp[u^1][j],dp[u][j]%=mod;
            for(int j = 0; j < 1024; j++)
            {
                dp[u][j^a[i]] = dp[u^1][j] + dp[u][j^a[i]];
                dp[u][j^a[i]]%=mod;
            }
 
        }
        LL sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum = sum + dp[n%2][b[i]];
            sum%=mod;
        }
        LL all = quick(2LL,n);
        sum = all-sum;
        sum = sum%mod + mod;
        printf("Case %d: ",++__cn);
        printf("%lld\n",sum%mod);
    }
    return 0;
}
LL quick(LL n,LL m)
{
    LL ask = 1;
    while(m)
    {
        if(m&1)
            ask = ask*n%mod;
        n = n*n%mod;
        m/=2;
    }
    return ask;
}
