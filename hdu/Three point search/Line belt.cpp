#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
const double EPS = 1e-6;
const double pi = acos(-1.0);
typedef struct node
{
    double ax,ay,bx,by;
} ss;
ss head[4];
double len(double t,double v1,double v2,int i,double xx,double yy,double co,double si);
double three_po1(double l,double r,int i,double v1,double v2,double v3,double r2);
double three_po2(double l,double r,double xx,double yy,int i,double v1,double v2,double v3);
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 0; i < 2; i++)
            scanf("%lf %lf %lf %lf",&head[i].ax,&head[i].ay,&head[i].bx,&head[i].by);
        double v1,v2,v3;
        scanf("%lf %lf %lf",&v1,&v2,&v3);
        double t1 = sqrt(pow(head[0].ax - head[0].bx,2) + pow(head[0].ay - head[0].by,2))/v1;
        double t2 = sqrt(pow(head[1].ax - head[1].bx,2) + pow(head[1].ay - head[1].by,2))/v2;
        double ask = three_po1(0,t1,0,v1,v2,v3,t2);
        printf("%.2f\n",ask);
    }
    return 0;
}
double three_po1(double l,double r,int i,double v1,double v2,double v3,double r2)
{
    double a,c,t;
    double co,si;
    if(head[i].ax == head[i].bx&&head[i].ay <= head[i].by)
        co = 0,si = 1;
    else if(head[i].ax == head[i].bx&&head[i].ay > head[i].by)
        co = 0,si = -1;
    else
    {
        t = sqrt(pow((head[i].ax - head[i].bx),2) + pow(head[i].ay - head[i].by,2));
        c = head[i].bx - head[i].ax;
        double  d=  head[i].by - head[i].ay;
        co = c/t;
        si = d/t;
    }
    while(fabs(l-r) > EPS)
    {
        double ll = (2*l+r)/3;
        double rr = (2*r+l)/3;
        double tl = ll + three_po2(0,r2,head[i].ax + v1*co*ll,head[i].ay + v1*si*ll,1,v1,v2,v3);
        double tr = rr + three_po2(0,r2,head[i].ax + v1*co*rr,head[i].ay + v1*si*rr,1,v1,v2,v3);
        if(tl >= tr)
            l = ll;
        else r = rr;
    }
    return l + three_po2(0,r2,head[i].ax + v1*co*l,head[i].ay + v1*si*l,1,v1,v2,v3);
}
double three_po2(double l,double r,double xx,double yy,int i,double v1,double v2,double v3)
{
    double a,c,t;
    double co,si;
    if(head[i].ax == head[i].bx&&head[i].ay <= head[i].by)
        co = 0,si = -1;
    else if(head[i].ax == head[i].bx&&head[i].ay > head[i].by)
        co = 0,si = 1;
    else
    {
        t = sqrt(pow((head[i].ax - head[i].bx),2) + pow(head[i].ay - head[i].by,2));
        c = head[i].ax - head[i].bx;
        double  d=  head[i].ay - head[i].by;
        co = c/t;
        si = d/t;
    }
    while(fabs(l-r) > EPS)
    {
        double ll = (2*l+r)/3;
        double rr = (2*r+l)/3;
        if(len(ll,v2,v3,i,xx,yy,co,si) >= len(rr,v2,v3,i,xx,yy,co,si))
            l = ll;
        else r = rr;
    }
    return len(l,v2,v3,i,xx,yy,co,si);
}
double len(double t,double v1,double v2,int i,double xx,double yy,double co,double si)
{
    double x = head[i].bx + v1*co*t;
    double y = head[i].by + v1*si*t;
    double lt = pow(x-xx,2) + pow(y - yy,2);
    lt = sqrt(lt);
    return t + lt/v2;
}
