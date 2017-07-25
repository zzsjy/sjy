#include<bits/stdc++.h>
using namespace std;
int a[20],b[20];
int dp[(1<<17)+100][20];
int short_pa(int i,int j);
int dfs(int id,int pos,int n);
int main(void)
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d",&b[i]);
        memset(dp,0x3f,sizeof(dp));
        printf("%d\n",dfs((1<<n)-1,n,n));
    }
    return 0;
}
int short_pa(int i,int j)
{
    return abs(i-j) + abs(a[i]-b[j]);
}
int dfs(int id,int pos,int n)
{
    if(dp[id][pos] < 1e8)
        return dp[id][pos];
    if(id == 0&&pos == 0)
        return dp[id][pos] = 0;
    int sum = 1e9;
    for(int i = 0; i < n; i++)
    {
        if(id&(1<<i))
        {
            sum = min(sum,dfs(id^(1<<i),pos-1,n) + short_pa(i + 1,pos));
        }
    }
    return dp[id][pos] = sum;
}
