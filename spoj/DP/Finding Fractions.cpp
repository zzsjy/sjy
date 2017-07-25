#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL gcd(LL n,LL m);
pair<LL,LL>slove(LL a,LL b,LL c,LL d);
int main(void)
{
    LL a,b,c,d;
    while(scanf("%lld %lld %lld %lld",&a,&b,&c,&d)!=EOF)
    {
        LL gc = gcd(a,b);
        a/=gc,b/=gc;
        gc = gcd(c,d);
        c/=gc,d/=gc;
        pair<LL,LL>ask = slove(a,b,c,d);
        printf("%lld/%lld\n",ask.first,ask.second);
    }
    return 0;
}
LL gcd(LL n,LL m)
{
    if(m == 0)return n;
    else return gcd(m,n%m);
}
pair<LL,LL>slove(LL a,LL b,LL c,LL d)
{
    if(a < b)
    {
        if(c > d)
            return make_pair(1,1);
        pair<LL,LL>ask = slove(d,c,b,a);
        return make_pair(ask.second,ask.first);
    }
    else
    {   LL k = a/b;
        pair<LL,LL> ask = slove(a%b,b,c-k*d,d);
        return make_pair(ask.first + k*ask.second,ask.second);
    }
}
