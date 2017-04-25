#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef struct node
{
    int x;
    int f;
} ss;
ss dp[5005][5005];
const int mod = 1988;
int slove(int n,int m);
int main(void)
{
    int n,m;
    while(scanf("%d %d",&n,&m),n!=0&&m!=0)
    {
        n-=m;
        for(int i = 0; i <= 5000; i++)
        {
            for(int j = 0; j <= 5000; j++)
            {
                dp[i][j].f = false;
                dp[i][j].x = 0;
            }
        }
        printf("%d\n",slove(n,m));
    }
    return 0;
}
int slove(int n,int m)
{
    if(n == 0||m == 1)
        return  1;
    if(dp[n][m].f)
        return dp[n][m].x;
    else
    {
        dp[n][m].f = true;
        dp[n][m].x = slove(n,m-1) + slove(n-m,min(m,n-m));
        dp[n][m].x %= mod;
        dp[n][m].f = true;
        return dp[n][m].x;
    }
}
