#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int x[maxn];
int y[maxn];
string str[maxn];
int L[maxn];
int n,m;
int k[5];
bool ok2(int X,int Y)
{
    for(int i=1; i<=m; ++i)
    {
        if(str[i]=="GCD")
        {
            if(__gcd(X,Y)==L[i])
                continue;
            else
                return false;
        }
        else
        {
            if((X*Y)/__gcd(X,Y)==L[i])
                continue;
            else
                return false;
        }
    }
    return true;
}
bool tmn2()
{
    for(int i=1; i<=200; ++i)
        for(int j=1; j<=200; ++j)
        {
            if(ok2(i,j))
            {
                return true;
            }
        }
    return false;
}
bool ok3()
{
    for(int i=1; i<=m; ++i)
    {
        if(str[i]=="GCD")
        {
            int h=__gcd(k[x[i]],k[y[i]]);
            if(h==L[i])
                continue;
            else
                return false;
        }
        else
        {
            int h=1ll*(k[x[i]]*k[y[i]])/__gcd(k[x[i]],k[y[i]]);
            if(h==L[i])
                continue;
            else
                return false;
        }
    }
    return true;
}
bool tmn3()
{
    for(int i=1; i<=200; ++i)
        for(int j=1; j<=200; ++j)
            for(int kh=1; kh<=200; ++kh)
            {
                k[1]=i;
                k[2]=j;
                k[3]=kh;
                if(ok3())
                {
                    return true;
                }
            }
    return false;
}
void subtask1()
{
    if(n==1)
    {
        cout<<"N";
    }
    if(n==2)
    {
        if(tmn2())
        {
            cout<<"Y";
        }
        else
            cout<<"N";
    }
    if(n==3)
    {
        if(tmn3())
        {
            cout<<"Y";
        }
        else
            cout<<"N";

    }
}
int main()
{

    //freopen("task.inp","r",stdin);
    freopen("GCDLCM.INP","r",stdin);
    freopen("GCDLCM.OUT","w",stdout);

    int Q,t;
    cin>>Q>>t;
    for(int k1=1; k1<=t; ++k1)
    {
        scanf("%d %d",&n,&m);
        int maxl=0;
        for(int i=1; i<=m; ++i)
        {
            cin>>str[i]>>x[i]>>y[i]>>L[i];
            maxl=max(maxl,L[i]);
        }
        if(n<=3)
        {
            subtask1();
        }
        else printf("N");
    }
}
