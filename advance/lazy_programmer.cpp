
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>


#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

#define eps 1e-8
typedef __int64 ll;

#define fre(i,a,b)  for(i = a; i <b; i++)
#define free(i,b,a) for(i = b; i >= a;i--)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define ssf(n)      scanf("%s", n)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pf          printf
#define bug         pf("Hi\n")

using namespace std;

#define INF 0x3f3f3f3f
#define N 100005

struct stud{
    int a,b,d;
    double money;
    bool operator<(const stud b) const
    {
        return a<b.a;
    }

}f[N];

int cmp(stud x,stud y)
{
    return x.d<y.d;
}

priority_queue<stud>q;

int n;

int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].d);
            f[i].money=0;   //已经给这个任务的钱
        }
        sort(f,f+n,cmp);

        while(!q.empty()) q.pop();
        double ans,day;
        ans=day=0;
        stud cur;
        for(i=0;i<n;i++)
        {
            q.push(f[i]);
            day+=f[i].b;
            while(day>f[i].d)
            {
                cur=q.top();
                q.pop();
                double temp=(double)(day-f[i].d)/cur.a;
                if(temp+cur.money<(double)cur.b/cur.a)  
                {
                    day-=temp*cur.a;
                    cur.money+=temp;
                    ans+=temp;
                    q.push(cur);
                    break;
                }
                else
                {
                    temp=((double)cur.b/cur.a-cur.money);
                    day-=temp*cur.a;
                    ans+=temp;
                }
            }
        }

        printf("%.2f\n",ans);
    }
    return 0;
}
