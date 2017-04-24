#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans[100010];
LL dp[100030];
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
    int T;
    T = read();
    while(T--)
    {
        int N;
        N = read();
        for(int i = 1; i <= N; i++)
            ans[i] = read();
        for(int i = 1; i <= N; i++)
        {
            dp[i] = -1e16;
        }
        LL maxx = 0;
        dp[0] = 0;
        for(int i = 0; i <= N; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                if(i + j <= N)
                {
                    LL sum = 0;
                    for(int s = i+1; s <= i+j; s++)
                    {
                        sum += ans[s];
                    }
                    maxx = max(dp[i] + sum,maxx);
                    if(i+2*j<=N)
                        dp[i+2*j] = max(dp[i+2*j],sum + dp[i]),maxx = max(dp[i+2*j],maxx);
                }
            }
        }
        printf("%lld\n",maxx);
    }
    return 0;
}
