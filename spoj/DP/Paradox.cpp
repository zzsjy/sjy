#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int x;
    char str[20];
} ss;
ss ans[200];
typedef struct edge
{
    int to,val;
} ac;
vector<int>vecp[105];
vector<int>vecn[105];
vector<int>vs;
vector<ac>vec[105];
bool used[105];
char cp[10] = "false";
int cmp[105];
void dfs(int v);
void rdfs(int v,int k);
int slove(int k,int v);
int f[105];
int main(void)
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i = 0; i < 105; i++)
            vecp[i].clear(),vecn[i].clear(),vs.clear(),vec[i].clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %s",&ans[i].x,ans[i].str);
            if(strcmp(ans[i].str,cp)==0)
                vec[i].push_back(ac{ans[i].x,0});
            else vec[i].push_back(ac{ans[i].x,1});
        }
        memset(used,0,sizeof(used));
        for(int i = 1; i <= n; i++)
        {
            vecp[i].push_back(ans[i].x);
            vecn[ans[i].x].push_back(i);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!used[i])dfs(i);
        }
        memset(used,0,sizeof(used));
        int k = 0;
        for(int i = vs.size()-1; i >= 0; i--)
        {
            if(!used[vs[i]])rdfs(vs[i],k++);
        }
        bool flag = false;
        memset(f,-1,sizeof(f));
        for(int i = 1; i <= n; i++)
        {
            if(f[i] == -1)
            {
                f[i] = 1;
                int vk = cmp[i];
                if(!slove(i,vk))
                    flag = true;
            }
        }
        if(flag)printf("PARADOX\n");
        else printf("NOT PARADOX\n");
    }
    return 0;
}
int slove(int k,int v)
{
    for(int i = 0; i < vec[k].size(); i++)
    {
        ac a = vec[k][i];
        if(cmp[a.to] == v)
        {
            if(f[a.to] == -1)
            {
                if(f[k] == 1)
                    f[a.to] = a.val;
                else f[a.to] = (a.val + 1)%2;
                return slove(a.to,v);
            }
            else
            {
                int u;
                if(f[k] == 1)
                    u = a.val;
                else u = (a.val + 1)%2;
                if(u!=f[a.to])
                    return 0;
            }
        }
        else continue;
    }
    return 1;
}
void dfs(int v)
{
    used[v] = true;
    for(int i = 0; i < vecp[v].size(); i++)
    {
        int id = vecp[v][i];
        if(!used[id])
            dfs(id);
    }
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v] = true;
    cmp[v] = k;
    for(int i = 0; i < vecn[v].size(); i++)
    {
        int id = vecn[v][i];
        if(!used[id])
            rdfs(id,k);
    }
}
