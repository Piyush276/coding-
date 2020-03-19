#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

vector<int> store[10];
vector<int> dist;
vector<bool> visted;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string a;
    cin>>a;
    int n=a.size();
    for(int i=0;i<n;i++){
        store[a[i]-'0'].push_back(i);
    }

    queue<int> q;
    q.push(0);

    dist.assign(n,0);
    dist[0]=0;

    visted.assign(n,false);


    int up;
    while(!q.empty()){
        up=q.front();
        q.pop();

        if(up==n-1){
            break;
        }

        for(int i:store[a[up]-'0']){
            if(i!=up and !visted[i]){
                dist[i]=1+dist[up];
                visted[i]=true;
                q.push(i);
            }
        }

        store[a[up]-'0'].clear();

        if(up+1<n and !visted[up+1]){
            dist[up+1]=1+dist[up];
            visted[up+1]=true;
            q.push(up+1);
        }

        if(up-1>=0 and !visted[up-1]){
            dist[up-1]=1+dist[up];
            visted[up-1]=true;
            q.push(up-1);
        }

    }
    cout<<dist[n-1];

}