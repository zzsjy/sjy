#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<deque>
using namespace std;
typedef long long LL;
int ans[1005];
int id[1005];
typedef struct node
{
        int x;
        int y;
        bool operator<(const node&cx)const
        {
                if(y == cx.y)return cx.x > x;
                else return y < cx.y;
        }
} ss;
priority_queue<ss>que;
bool cmp(node p,node q)
{
        return p.y < q.y;
}
ss ak[10005];
int dp[105][10005][105];
int main(void)
{
        int n,m;
        scanf("%d",&n);
        int i,j;
        int sum = 0;
        int uu ;
        for(i = 1; i <= n; i++)
        {
                scanf("%d",&ak[i].x);
                sum+=ak[i].x;
        }
        uu = sum;
        int vv = 0;
        for(i = 1; i <= n; i++)
        {
                scanf("%d",&ak[i].y);
                vv+=ak[i].y;
        }
        sort(ak+1,ak+n+1,cmp);
        int s;
        for(i = 0; i < 105; i++)
        {
                for(j = 0; j <= 10000; j++)
                {
                        for(s = 0; s < 105; s++)
                        {
                                dp[i][j][s] = -1e9;
                        }
                }
        }
        for(i = 0; i < 105; i++)
        {

                        dp[i][0][0]=0;
        }
        int cn = 0;
        int nn = n;
        while(sum  > 0)
        {
                sum -= ak[nn].y;
                cn++;
                nn--;
        }
        int maxx = 0;
        for(i = 1; i <= n; i++)
        {
                for(s = vv; s >= ak[i].y; s--)
                {
                        for(j = cn; j >= 1; j--)
                        {
                                dp[i][s][j] = max(dp[i][s][j],dp[i-1][s][j]);
                                dp[i][s][j] = max(dp[i][s][j],dp[i-1][s-ak[i].y][j-1]+ak[i].x);
                                if(j == cn&&s >= uu)
                                        maxx = max(maxx,dp[i][s][j]);
                        }
                }
                for(s = ak[i].y-1; s >= 0; s--)
                {
                        for(j = cn ; j >= 1; j--)
                        {
                                dp[i][s][j] =max(dp[i-1][s][j],dp[i][s][j]);
                                if(j == cn&&s >= uu)
                                        maxx = max(maxx,dp[i][s][j]);
                        }
                }
        }
        printf("%d %d\n",cn,uu-maxx);
        return 0;
}
