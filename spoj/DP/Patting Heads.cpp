#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int f[1000005];
int cnt[1000005];
int ask[1000005];
int main(void)
{
    int T;
    scanf("%d",&T);
    int maxx = 0;
    for(int i = 0;i < T;i++)
    {   int u;
        scanf("%d",&u);
        cnt[u]++;
        f[i] = u;
        maxx = max(u,maxx);
    }
    for(int i = 1;i <= maxx;i++)
    {  if(cnt[i])
        for(int j = 1;i*j <= maxx;j++)
        {
          if(j == 1)
            ask[i*j] += cnt[i]-1;
          else ask[i*j] += cnt[i];
        }
    }
    for(int i = 0;i < T;i++)
    {
        printf("%d\n",ask[f[i]]);
    }
    return 0;
}
