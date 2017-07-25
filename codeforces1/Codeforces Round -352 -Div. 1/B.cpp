#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL node[600000];
LL n,k;
bool checklo(LL mid)
{
    LL sum = 0;
    for(int i = 0; i < n; i++)
        if(node[i] > mid)
            sum += node[i] - mid;
    return sum <= k;
}
bool checkhi(LL mid)
{
    LL sum = 0;
    for(int i = 0; i < n; i++)
        if(node[i] < mid)
        sum += mid - node[i];
    return sum <= k;
}
int main(void)
{
    scanf("%lld %lld",&n,&k);
    LL sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&node[i]);
        sum += node[i];
    }
    LL l = 0,r = 1e9;
    LL loid = -1; 
    while(l <= r)
    {
        LL mid = (l+r)/2;
        if(checklo(mid))
            loid = mid,r = mid - 1;
        else l = mid + 1;
    }

    l = 0,r = 1e9;
    LL hiid = -1;
    while(l <= r)
    {
        LL mid = (l+r)/2;
        if(checkhi(mid))
            hiid = mid,l = mid + 1;
        else r = mid - 1;
    }
    if(hiid < loid)
        printf("%lld\n",loid - hiid);
    else
    {  
       if(sum%n)
        printf("1\n");
       else printf("0\n");
    }
    return 0;
}
/*
#Robin Hood
[题目链接][1]

##题意
给你n个人和他们的钱数，然后给你k天，每天可以从最高钱数的人那边取一块钱给最少钱数的人，问最后钱数最多的人和钱数最少的人相差多少；
##思路
二分最钱数，能下降到的位置$low$，和最低钱数能够上涨到的位置$high$，如果$low > high$,那么答案就是$low-high$，
如果$low <= high$那么经过k天后如果所有的钱数和能够整除n则答案为0，否则相差1
*/
