#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL n,LL m);
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL x,y,p,q;
        scanf("%lld %lld %lld %lld",&x,&y,&p,&q);
        LL ask = 0;
        if(x == 0&& p == 0)
            ask = 0;
        else if(x != 0&&p == 0)
            ask = -1;
        else
        {
            LL k;
            LL gc = gcd(p,q);
            p/=gc,q/=gc;
            gc = gcd(x,y);
            if(x / gc == p&&y / gc == q)
                ask = 0;
            else if(p == q&&x!=y)
                ask = -1;
            else if( p == q&&x == y)ask = 0;
            else
            {   
                if((y-x)%(q-p) == 0)
                    k = (y-x)/(q-p);
                else k = (y-x)/(q-p) + 1;
                LL a = k*p - x;
                LL b = k*q - y;
                if(x%p)k = max(x/p+1,k);
                else k = max(x/p,k);
                if(y%q) k = max(y/q+1,k);
                else k = max(y/q,k);
                ask = k*q-y;
            }
        }
        printf("%lld\n",ask);
    }
    return 0;
}
LL gcd(LL n,LL m)
{
    if(m == 0)
        return n;
    else return gcd(m,n%m);
}
/*
  [1]: http://codeforces.com/contest/807/problem/C
##题意
给你两个分数形式的数，然后有两种变化方式

 1. 上下都+1
 2. 仅下面部分+1
让你求第一个分数变化到第二个分数的最小步数。
##思路
有几种特殊情况分类讨论一下。
首先我们先把右边化为最简比。
我们可以得到方程$$\frac{(x+a)}{(y+b)} = \frac{k*p}{k*q}$$

$$a = k*p - x\\b = k*q - y$$
根据$b >= a$可求得$k = \frac{y-x}{q-p}$向上取整，并且要求a>=0
*/
