/*http://codeforces.com/problemset/problem/543/B*/


#include<bits/stdc++.h>
using namespace std;
vector<int>vec[3005];
int short_pa[3005][3005];
bool flag[3005];
queue<int>que;
void bfs(int n);
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    int all = m;
    memset(short_pa,0x3f,sizeof(short_pa));
    int maxx = short_pa[0][0];
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int s1,t1,co1;
    int s2,t2,co2;
    scanf("%d %d %d",&s1,&t1,&co1);
    scanf("%d %d %d",&s2,&t2,&co2);
    for(int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    int minn = short_pa[s1][t1] + short_pa[s2][t2];
    bool fl = false;
    if(short_pa[s1][t1] > co1||short_pa[s2][t2] > co2)
        fl = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(short_pa[s1][i] + short_pa[i][j] + short_pa[j][t1] <= co1&&short_pa[s2][i] + short_pa[i][j] + short_pa[j][t2] <= co2)
            {
                minn = min(short_pa[s1][i] + short_pa[s2][i] + short_pa[i][j] + short_pa[j][t1] + short_pa[j][t2],minn);
            }
            if(short_pa[s1][i] + short_pa[i][j] + short_pa[j][t1] <= co1&&short_pa[t2][i] + short_pa[i][j] + short_pa[j][s2] <= co2)
            {
                minn = min(short_pa[s1][i] + short_pa[t2][i] + short_pa[i][j] + short_pa[j][t1] + short_pa[j][s2],minn);
            }
            if(short_pa[t1][i] + short_pa[i][j] + short_pa[j][s1] <= co1&&short_pa[s2][i] + short_pa[i][j] + short_pa[j][t2] <= co2)
            {
                minn = min(short_pa[t1][i] + short_pa[s2][i] + short_pa[i][j] + short_pa[j][s1] + short_pa[j][t2],minn);
            }
             if(short_pa[t1][i] + short_pa[i][j] + short_pa[j][s1] <= co1&&short_pa[t2][i] + short_pa[i][j] + short_pa[j][s2] <= co2)
            {
                minn = min(short_pa[s1][i] + short_pa[t2][i] + short_pa[i][j] + short_pa[j][t1] + short_pa[j][s2],minn);
            }

        }
    }
    if(fl)printf("-1\n");
    else
        printf("%d\n",all - minn);
    return 0;
}
void bfs(int n)
{
    memset(flag,0,sizeof(flag));
    flag[n] = true;
    short_pa[n][n] = 0;
    while(!que.empty())
        que.pop();
    que.push(n);
    while(!que.empty())
    {
        int id = que.front();
        que.pop();
        for(int i = 0; i < vec[id].size(); i++)
        {
            int ic = vec[id][i];
            if(!flag[ic])
            {
                flag[ic] = true;
                short_pa[n][ic]= short_pa[n][id] + 1;
                que.push(ic);
            }
        }
    }
}
