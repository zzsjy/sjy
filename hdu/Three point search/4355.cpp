#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef struct node
{
    double p,w;
} ss;
ss num[60000];
double f(double x,int n);
double EFS = 1e-4;
int main(void)
{
    int T,__cn = 0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%lf %lf",&num[i].p,&num[i].w);
        double l = 0,r = 1e6;
        int cnt = 30;
        while(fabs(l-r) > EFS)
        {
            cnt--;
            double ll = (2*l+r)/3;
            double rr = (2*r+l)/3;
            if(f(ll,n) > f(rr,n))
                l = ll;
            else r = rr;
        }
        printf("Case #%d: ",++__cn);
        printf("%.0f\n",f(l,n));
    }
    return 0;
}
double f(double x,int n)
{
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        double u = fabs((num[i].p-x)*(num[i].p-x)*(num[i].p-x));
        sum += u*num[i].w;
    }
    return sum;
}
