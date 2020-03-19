/*
* @Author: piyush
* @Date:   2020-03-05 00:45:18
* @Last Modified by:   Piyush Sinha
* @Last Modified time: 2020-03-11 11:24:14
*/



#include </Users/piyush/Desktop/nodejs/first-app/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 1000000
#define mod 1000000007
#define pb(a) push_back(a)

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);



struct point{
    int x,y;
};

struct segment{
    point a,b;
};

#define _max 1024
segment seg[_max];
int root[_max];

int find(int a){
    if(a==root[a]){
        return a;
    }
    return root[a]=find(root[a]);
}

void link(int a,int b){
    root[a]=root[b];
}

int direction(point pi,point pj,point pk){
    return (pk.x-pi.x)*(pj.y-pi.y) - (pj.x-pi.x)*(pk.y-pi.y);
}
template<class T> bool inside(T a,T b,T c) { return a<=b and b<=c ;}

bool onsegment(point pi,point pj,point pk)
{
    return inside(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) and
    inside(min(pi.y,pj.y),pk.y,max(pi.y,pj.y));
}

bool intersect(point p1,point p2,point p3,point p4){
    int d1,d2,d3,d4;
    d1=direction(p3,p4,p1);
    d2=direction(p3,p4,p2);
    d3=direction(p1,p2,p3);
    d4=direction(p1,p2,p4);

    if(((d1>0 and d2<0) or (d1<0 and d2>0))  and ((d3>0 and d4<0) or (d3<0 and d4>0))){
        return true;
    }

    if(!d1 and onsegment(p3,p4,p1)) return true;
    if(!d2 and onsegment(p3,p4,p2)) return true;
    if(!d3 and onsegment(p1,p2,p3)) return true;
    if(!d4 and onsegment(p1,p2,p4)) return true;

    return false;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll test;
    cin>>test;
    while(test--){
        ll n,query;
        cin>>n>>query;

        for(ll i=1;i<=n;i++){
            root[i]=i;
            cin>>seg[i].a.x>> seg[i].a.y>>seg[i].b.x>>seg[i].b.y;
        }
        int p1,p2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                p1=find(root[i]);
                p2=find(root[j]);
                if(p1!=p2 and intersect(seg[i].a,seg[i].b,seg[j].a,seg[j].b)){
                    link(p1,p2);
                }
            }
        }

        while(query--){
            cin>>p1>>p2;
            if(find(root[p1])!=find(root[p2])){
                cout<<"NO";br;
            }else{
                cout<<"YES";br;
            }
        }
    }
}











// ////////////////////////////////////////////   dont know about geometery so copied

// #include <cassert>
// #include <cctype>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
// #include <sstream>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <deque>
// #include <list>
// #include <set>
// #include <map>
// #include <bitset>
// #include <stack>
// #include <queue>
// #include <algorithm>
// #include <functional>
// #include <iterator>
// #include <numeric>
// #include <utility>
// using namespace std;

// template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
// template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
// template< class T > T _min(T a, T b) { return (a < b ? a : b); }
// template< class T > T sq(T x) { return x * x; }
// template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
// template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
// template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
// template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

// #define ALL(c) c.begin(), c.end()
// #define PB(x) push_back(x)
// #define UB(s, e, x) upper_bound(s, e, x)
// #define LB(s, e, x) lower_bound(s, e, x)
// #define REV(s, e) reverse(s, e);
// #define SZ(c) c.size()
// #define SET(p) memset(p, -1, sizeof(p))
// #define CLR(p) memset(p, 0, sizeof(p))
// #define MEM(p, v) memset(p, v, sizeof(p))
// #define CPY(d, s) memcpy(d, s, sizeof(s))
// #define i64 long long
// #define ff first
// #define ss second
// #define DEBUG if(0)

// const double EPS = 1e-9;
// const double BIG = 1e15;
// const int NIL = 0;
// const int INF = 0x3f3f3f3f;

// const int MAX = 1024;

// struct Point { int x, y; };
// struct Segment { Point a, b; };

// Segment seg[MAX];
// int root[MAX];

// int find(int u) {
//     if(u!=root[u]) root[u] = find(root[u]);
//     return root[u];
// }

// inline void link(int u, int v) {
//     root[u] = root[v];
// }

// inline int direction(Point &pi, Point &pj, Point &pk) {
//     return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
// }
// template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
// inline bool onsegment(Point &pi, Point &pj, Point &pk) {
//     return (inside(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) &&
//      inside(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
// }

// inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) {
//     int d1, d2, d3, d4;
//     d1 = direction(p3, p4, p1);
//     d2 = direction(p3, p4, p2);
//     d3 = direction(p1, p2, p3);
//     d4 = direction(p1, p2, p4);
//     if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0)))
//         return true;
//     if(!d1 && onsegment(p3, p4, p1)) return true;
//     if(!d2 && onsegment(p3, p4, p2)) return true;
//     if(!d3 && onsegment(p1, p2, p3)) return true;
//     if(!d4 && onsegment(p1, p2, p4)) return true;
//     return false;
// }

// int main() {
//     //freopen("in.txt", "r", stdin);
//     //freopen("out.txt", "w", stdout);
//     int t, m, n, i, j, u, v;
//     scanf("%d", &t);
//     while(t--) {
//         scanf("%d%d", &n, &m);
//         for(i = 1; i <= n; i++) {
//             root[i] = i;
//             scanf("%d%d%d%d", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
//         }
//         for(i = 1; i <= n; i++) {
//             for(j = 1; j <= n; j++) {
//                 u = find(i);
//                 v = find(j);
//                 if(u != v && intersect(seg[i].a, seg[i].b, seg[j].a, seg[j].b))
//                     link(u, v);
//             }
//         }
//         while(m--) {
//             scanf("%d%d", &i, &j);
//             u = find(i);
//             v = find(j);
//             if(u==v) printf("YES\n");
//             else printf("NO\n");
//         }
//     }
//     //system("pause");
//     return 0;
// }
