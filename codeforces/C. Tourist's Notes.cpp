#include<iostream>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<stack>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef struct node
{
    int day;
    int hi;
} ss;
ss ans[1000005];
int main(void)
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i,j;
        int flag = 0;
        for(i = 0; i < m; i++)
            scanf("%d %d",&ans[i].day,&ans[i].hi);
        int maxx = -1;
        for(i = 0; i < m; i++)
        {
            if(i == 0)
            {
                maxx = max(ans[i].day-1+ans[i].hi,maxx);
            }
            else
            {
                if(abs(ans[i].hi-ans[i-1].hi)>ans[i].day-ans[i-1].day)
                    flag = 1;
                else
                {
                    int l = max(ans[i-1].hi,ans[i].hi);
                    int r = 1e9;
                    while(l<=r)
                    {
                        int mid = (l+r)/2;
                        int x = abs(mid-ans[i].hi);
                        int y = abs(mid-ans[i-1].hi);//printf("%d\n",mid);
                        if(x+y<=ans[i].day-ans[i-1].day)
                        {
                            maxx = max(maxx,mid);
                            l = mid+1;
                        }
                        else r = mid-1;
                    }
                }
            } if(i == m-1)
            {
                maxx = max(maxx,n-ans[i].day+ans[i].hi);
            }
        }if(flag)printf("IMPOSSIBLE\n");
        else
        printf("%d\n",maxx);
    }
    return 0;
}
