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
typedef long long LL;
int dp[100005];
int main(void)
{
    int n;
    int __cn = 0;
    memset(dp,0x3f,sizeof(dp));
    dp[1] = 1;dp[0] = 0;
    for(int i = 2;i <= 100000;i++)
    {
        for(int j = 1;j <= min(i,100);j++)
        {
            if(j*j*j <= i)
                dp[i] = min (dp[i],dp[i-j*j*j] + 1);
            else break;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
       printf("Case #%d: ",++__cn);
       printf("%d\n",dp[n]);
    }
    return 0;
}



