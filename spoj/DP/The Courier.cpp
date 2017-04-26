#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int ma[105][105];
typedef struct node
{
    int x,y,t,ip;
} ss;
ss ans[20];
int dp[(1<<13) + 100][105];
vector<ss>vec[105];
ss cnt[105][20];
int ic[105];
int cs[105][105];
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        memset(ma,0x3f,sizeof(ma));
        memset(cnt,0,sizeof(cnt));
        memset(ic,0,sizeof(ic));
        memset(cs,0,sizeof(cs));
        int maxx = ma[0][0];
        for(int i = 0; i < 105; i++)
            vec[i].clear();
        while(m--)
        {
            int x,y,v;
            scanf("%d %d %d",&x,&y,&v);
            if(ma[x][y] > v)
                ma[x][y] = ma[y][x] = v;
        }
        ss u;
        for(int s = 1; s <= n; s++)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    ma[i][j] = min(ma[i][j],ma[i][s] + ma[s][j]);
                }
            }
        }
        int z;
        scanf("%d",&z);
        int cn = 0;
        for(int i = 0; i < z; i++)
        {
            int x,y,v;
            scanf("%d %d %d",&x,&y,&v);
            while(v)
                vec[y].push_back(node{x,y,ma[x][y],cn++}),v--;
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0][k] = 0;
        for(int i = 0; i < (1<<cn); i++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int u = 0; u < vec[j].size(); u++)
                {
                    ss ad = vec[j][u];
                    if(i&(1<<ad.ip))
                    {
                        dp[i][j] = min(dp[i][j],dp[i^(1<<ad.ip)][ad.x]+ad.t);
                    }
                }

            }
            for(int j = 1; j <= n; j++)
                for(int s = 1; s <= n; s++)
                {
                    if(ma[s][j]!=maxx)
                        dp[i][j] = min(dp[i][j],dp[i][s] + ma[s][j]);
                }
        }
        printf("%d\n",dp[(1<<cn)-1][k]);
    }
    return 0;
}
