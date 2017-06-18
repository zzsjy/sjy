#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
map<LL,LL>my;
LL slove(LL n);
int main(void)
{
    int a,b;
    while(scanf("%d %d",&a,&b),a!=-1&&b!=-1)
    {
        if(a == 0)a++;
        printf("%lld\n",slove(b)-slove(a-1));
    }
    return 0;
}
LL slove(LL n)
{
    if(my.count(n))
    {
        return my[n];
    }
    if(n <= 9)
    {
        return my[n] = (n+(LL)1)*n/(LL)2;
    }
    LL t = 1;
    int cp = n;
    while(cp > 0)
    {
        t*=10;
        cp/=10;
    }
    t/=10;
    LL c = n%t + 1;
    LL head  = n/t;
    LL ask = head*c + slove(c-1) + slove(t-1)*head + slove(head - 1)*t;
    my[n] = ask;
    return ask;
}
