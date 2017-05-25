#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<iostream>
#include<map>
using namespace std;
map<string,int>my;
typedef long long LL;
typedef struct node
{
    char name[100];
    char ic[100];
    LL cost;
    LL a;
} ss;
ss num[2000];
bool cmp(node p,node q)
{
    return p.cost < q.cost;
}
bool check(LL mid,LL m,int cn,int n);
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL n,m;
        scanf("%lld %lld",&n,&m);
        my.clear();
        int cn = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s %s %lld %lld",num[i].name,num[i].ic,&num[i].cost,&num[i].a);
            if(!my.count(num[i].name))
            {
                my[num[i].name] = 1;
                cn++;
            }
        }
        my.clear();
        sort(num,num+n,cmp);
        LL l = 0,r = 1e9;
        LL id = 0;
        while(l <= r)
        {
            LL mid = (l + r)/2LL;
            if(check(mid,m,cn,n))
            {
                id = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%lld\n",id);
    }
    return 0;
}
bool check(LL mid,LL m,int cn,int n)
{
    my.clear();
    int ct  = 0;
    for(int i = 0; i < n; i++)
    {
        if(!my.count(num[i].name)&&num[i].a >= mid)
            m-=num[i].cost,my[num[i].name] = 1,ct++;
        if(m < 0)
            break;
    }
    if(m < 0||ct!=cn)
        return false;
    return true;
}
#if 0
LA  3971
#endif 
