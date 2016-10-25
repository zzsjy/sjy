#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<string.h>
#include<iostream>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
typedef struct node
{
        char ans[100];
        int id;
} ss;
bool cmp(node p,node q)
{
        return p.id < q.id;
}
ss a[10000];
ss b[10000];
ss ask[10000];
int main(void)
{
        int n;
        while(scanf("%d",&n)!=EOF)
        {
                int i,j;
                for(i = 0; i < n; i++)
                {
                        scanf("%s %d",a[i].ans,&a[i].id);
                }
                int ff = 0;
                sort(a,a+n,cmp);
                for(i = 0; i < n; i++)
                {
                        ask[i] = a[i];
                        if(a[i].id > i)ff=1;
                        ask[i].id = n-ask[i].id;
                }
                if(!ff)
                {
                        int cn = 1;
                        while(cn < n)
                        {
                                int sum = 0;
                                for(i = 0; i < n; i++)
                                {
                                        if(ask[i].id > ask[cn].id)
                                                sum++;
                                                if(sum == a[cn].id)
                                        {
                                            break;
                                        }

                                }
                               ss akk = ask[cn];
                                for(j = cn;j > i+1;j--)
                                {
                                    ask[j] = ask[j-1];
                                }
                                ask[i+1] = akk;
                                cn++;
                        }
                }
                if(ff)printf("-1\n");
                else
                {
                    for(i = 0;i < n;i++)
                        printf("%s %d\n",ask[i].ans,ask[i].id);
                }
        }
}
