#include<bits/stdc++.h>
using namespace std;
const int BufferSize=1<<16;
char buffer[BufferSize],*head,*tail;
inline char Getchar()
{
    if(head==tail)
    {
        int l=fread(buffer,1,BufferSize,stdin);
        tail=(head=buffer)+l;
    }
    return *head++;
}
inline int read()
{
    int x=0,f=1;
    char c=Getchar();
    for(; !isdigit(c); c=Getchar()) if(c=='-') f=-1;
    for(; isdigit(c); c=Getchar()) x=x*10+c-'0';
    return x*f;
}
typedef unsigned long long LL;
bool prime[100004];
int ans[100000];
int t[100000];
LL dp[10000];
int main(void)
{
    for(int i = 2; i <= 1000; i++)
    {
        if(!prime[i])
            for(int j = i; (i*j) <= 100000; j++)
                prime[i*j] = true;
    }
    int cn = 0;
    for(int i = 2; i <= 10000; i++)
        if(!prime[i])ans[cn++] = i;
    int f = 0;
    for(int i = 0; i < cn; i++)
    {
        bool flag = false;
        for(int s = 1; s <= sqrt(ans[i]); s++)
        {
            for(int j = 1; j <= sqrt(ans[i]); j++)
            {
                if(s*s + j*j == ans[i])
                {
                    t[f++] = ans[i];
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int c = t[n-1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 1;i <= m;i++)
        {
            for(int j = i;j <= c;j++)
            {
                dp[j] += dp[j-i];
            }
        }
        printf("%lld\n",dp[c]);
    }
    return 0;
}
