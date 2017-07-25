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
# 组装电脑 
##题意
你有b元钱，想要组装一台电脑，给出n个配件各自的种类.品质因子，要求每种类型的配件个各买一个，总价格不超过b，且“品质最差配件”的品质因子尽量最大。
##思路
二分，我们可以二分答案，首先按价格升序排序，然后二分检查的时候循环一遍，选每种价格最低的，并且品质因子不低于mid的，看是否能取够所有种类，最后这样相当于删去品质因子小于mid的，这样符合单调。复杂度逆$（n×log(n)^2）$.
#endif 
