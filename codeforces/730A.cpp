#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
typedef struct node
{
        int id;
        int cost;
        bool operator<(const node&cx)const
        {
                return cx.cost > cost;
        }
} ss;
int ans[1000];
int ab[10005][105];
priority_queue<ss>que;
int flag[1005];
int main(void)
{
        int n;
        scanf("%d",&n);
        int i,j;
        for(i = 0; i < n; i++)
        {
                scanf("%d",&ans[i]);
        }
        memset(ab,0,sizeof(ab));
        while(!que.empty())
                que.pop();
        memset(flag,0,sizeof(flag));
        int cn = 0;
        for(i = 0; i < n; i++)
        {
                if(!flag[ans[i]])
                {
                        cn++;
                }
                flag[ans[i]]++;
                ss ak;
                ak.cost = ans[i];
                ak.id = i;
                que.push(ak);
        }
        int cnt = 0;
        while(cn>1)
        {
                ss a = que.top();
                que.pop();
                ss b = que.top();
                que.pop();
                if(a.cost!=b.cost)
                {
                        if(a.cost>0)
                        {
                                flag[a.cost]--;
                                if(flag[a.cost]==0)cn--;
                                if(flag[a.cost-1]==0)cn++;
                                a.cost--;
                                flag[a.cost]++;
                        }
                        if(b.cost>0)
                        {
                                flag[b.cost]--;
                                if(flag[b.cost]==0)cn--;
                                if(flag[b.cost-1]==0)cn++;
                                b.cost--;
                                flag[b.cost]++;
                        }
                        ab[cnt][a.id]++;
                        ab[cnt][b.id]++;
                }
                else if(flag[a.cost]%2==0)
                {
                        if(a.cost>0)
                        {
                                flag[a.cost]--;
                                if(flag[a.cost]==0)cn--;
                                if(flag[a.cost-1]==0)cn++;
                                a.cost--;
                                flag[a.cost]++;
                        }
                        if(b.cost>0)
                        {
                                flag[b.cost]--;
                                if(flag[b.cost]==0)cn--;
                                if(flag[b.cost-1]==0)cn++;
                                b.cost--;
                                flag[b.cost]++;
                        }
                            ab[cnt][a.id]++;
                        ab[cnt][b.id]++;
                }
                else
                {
                        ss c = que.top();
                        que.pop();
                          if(a.cost>0)
                        {
                                flag[a.cost]--;
                                if(flag[a.cost]==0)cn--;
                                if(flag[a.cost-1]==0)cn++;
                                a.cost--;
                                flag[a.cost]++;
                        }
                        if(b.cost>0)
                        {
                                flag[b.cost]--;
                                if(flag[b.cost]==0)cn--;
                                if(flag[b.cost-1]==0)cn++;
                                b.cost--;
                                flag[b.cost]++;
                        }
                        if(c.cost>0)
                        {
                                flag[c.cost]--;
                                if(flag[c.cost]==0)cn--;
                                if(flag[c.cost-1]==0)cn++;
                                c.cost--;
                                flag[c.cost]++;
                        }ab[cnt][c.id]++;
                            ab[cnt][a.id]++;
                        ab[cnt][b.id]++;
                        que.push(c);
                }
                cnt++;
                que.push(a);
                que.push(b);
        }
        int x = que.top().cost;
        printf("%d\n",x);
        printf("%d\n",cnt);
        for(i = 0;i < cnt;i++)
        {
            for(j = 0;j < n;j++)
            {
                if(j == 0)
                    printf("%d",ab[i][j]);
                else printf("%d",ab[i][j]);
            }
            printf("\n");
        }
        return 0;
}
