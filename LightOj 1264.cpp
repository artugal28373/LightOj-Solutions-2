/*
 Problem name : 1264 - Grouping Friends
 Algorithm : Sub set Masking
 Contest/Practice : Off Line Practice
 Source : Light OJ
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 09-Jun-15
 Last Update : 25-Mar-2015
*/
  
 
#include<bits/stdc++.h>
 
#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
 
typedef long long ll;
typedef unsigned long long llu;
 
using namespace std;
 
 
template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}
template<class T>
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);
 
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
 
template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}
 
template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}
 
template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}
 
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
 
 
 template<class T>  
 inline int in() {
    T x;
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
 
/******* ! Code start from here ! *******/
 
int kp[20][20];
int dis[17500];
int dp[17500];
int done[17500]={0},cc=1;
 
int re(int mask)
{
    if(mask==0) return 0;
 
    if(done[mask]==cc) return dp[mask];
 
    done[mask]=cc;
    dp[mask]=inf;
 
    for(int i=mask;i!=0;i=mask&(i-1))
    {
        if(dis[i]<=0)
            dp[mask]=min(dp[mask],dis[i]+re(mask^i) );
    }
 
    return dp[mask];
}
 
int main()
{
//     std::ios_base::sync_with_stdio(false);
 
    #ifdef kimbbakar
//        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif
 
 
    int n,t=in<int>(),tcase=1;
    int test;
 
    while(t--)
    {
        n=in<int>();
 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                kp[i][j]=in<int>();
        }
 
        for(int i=0;i<(1<<n);i++)
        {
            test=0;
            for(int j=0;j<n;j++)
            {
                if(check(i,j))
                {
                    for(int k=0;k<n;k++)
                    {
                        if(check(i,k))
                            test+=kp[j][k];
                    }
                }
            }
 
            dis[i]=test;
        }
 
 
        printf("Case %d: %d\n",tcase++,re((1<<n)-1 ));
 
        cc++;
 
    }
 
 
    return 0;
}
