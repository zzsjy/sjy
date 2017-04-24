#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[5005][5005];
LL a[5005],b[5005];
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
int main(void)
{
    int n,m;
    n = read(),m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    for(int i = 1; i <= m; i++)
        b[i] = read();
    for(int i = 0; i < 5005; i++)
    {
        for(int j = 0; j < 5005; j++)
        {
            dp[i][j] = 1e11;
        }
    }
    sort(a+1,a+n+1);
    sort(b+1,b+1+m);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        LL minn = dp[i-1][i-1];
        for(int j = i; j <= m; j++)
        {
            dp[i][j] = min(dp[i][j],minn + abs(a[i]-b[j]));
            minn = min(dp[i-1][j],minn);
        }
    }
    LL ask = dp[n][n];
    for(int i = n;i <= m;i++)
        ask = min(ask,dp[n][i]);
    printf("%lld\n",ask);
    return 0;
}
