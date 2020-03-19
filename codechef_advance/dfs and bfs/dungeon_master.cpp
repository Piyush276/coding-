/*
* @Author: piyush
* @Date:   2020-02-28 03:32:08
* @Last Modified by:   piyush
* @Last Modified time: 2020-02-28 03:32:16
*/


#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<long long,long long> pll;


#define S second
#define F first
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 1000000
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

ll min_count;

class moves{
public:
    ll z,x,y;
    moves(){
        x=0;
        y=0;
        z=0;
    }
};

ll node_left_in_level=1,node_next_level=0;
ll x=0, y=0, z=0;


char ***grid;
queue<moves> yolo;

map<vector<ll>,bool> dp;

void possible_ways(moves up){
    ll z[]={1,-1,0,0,0,0};
    ll x[]={0,0,-1,1,0,0};
    ll y[]={0,0,0,0,1,-1};

    ll newx=up.x,newy=up.y,newz=up.z;

    for(ll i=0;i<(sizeof(z)/ sizeof(z[0]));i++){
        newz=up.z+z[i];
        newy=up.y+y[i];
        newx=up.x+x[i];
        if(newx>= ::x or newy>=::y or newz>=::z or
            newx<0 or newy<0 or newz<0){
            continue;
        }
        vector<ll> temp;
        temp.pb(newz);
        temp.pb(newx);
        temp.pb(newy);
        if(dp[temp]){
            continue;
        }

        if(grid[newz][newx][newy]=='#') continue;
        //print(temp);
        dp[temp]=true;
        moves har;
        har.x=newx;
        har.y=newy;
        har.z=newz;
        yolo.push(har);
        node_next_level+=1;
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    while(true) {

        cin >> z >> x >> y;               /// z x y

        if(x==0 and y==0 and z==0){
            break;
        }

        dp.clear();
        node_left_in_level=1,node_next_level=0;
        queue<moves> qwerty;
        yolo=qwerty;

        moves start;
        char ***grid1;

        grid1 = new char **[z];
        for (ll i = 0; i < z; i++) {
            grid1[i] = new char *[x];
            for (ll j = 0; j < x; j++) {
                grid1[i][j] = new char[y];
                for (ll k = 0; k < y; k++) {
                    cin >> grid1[i][j][k];
                    if (grid1[i][j][k] == 'S') {
                        start.z = i;
                        start.x = j;
                        start.y = k;
                    //out<<i<<" "<<j<<" "<<k;br;
                    }
                }
            }
        }

        grid=grid1;

        min_count = 0;
        vector<ll> temp;
        moves up;
        yolo.push(start);
        temp.clear();
        temp.pb(start.z);
        temp.pb(start.x);
        temp.pb(start.y);
        dp[temp] = true;

        bool flag = false;

        while (!yolo.empty()) {
            up = yolo.front();
            yolo.pop();

            //cout<<up.x<<" "<<up.y<<" "<<up.z;br;

            if (grid[up.z][up.x][up.y] == 'E') {
                flag = true;
                break;
            }

            possible_ways(up);

            node_left_in_level--;

            if (node_left_in_level == 0) {
                node_left_in_level = node_next_level;
                node_next_level = 0;
                min_count += 1;
            }


        }

        if (flag) {
            cout<<"Escaped in ";
            cout << min_count;
            cout<<" minute(s).";
            br;
        } else {
            cout << "Trapped!";
            br;
        };

        for(ll i=0;i<z;i++){
            for(ll j=0;j<x;j++){
                delete [] grid[i][j];
            }
        }

        for(ll i=0;i<z;i++){
            delete [] grid[i];
        }

        delete [] grid;


    }
}
