
///         not done showing wrong ans




/////////////////////////////////////////       BY USING dp
// #include </Users/piyush/Desktop/CP/bits/stdc++.h>
// // #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;



// #define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
// #define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
// #define br cout<<"\n"
// #define max_val 1000000
// #define mod 1000000007
// #define pb(a) push_back(a)

// #define FILE_READ_IN freopen("input.txt","r",stdin);
// #define FILE_READ_OUT freopen("output.txt","w",stdout);


// void dfs(char **grid,ll **val,ll row,ll col,ll x,ll y,ll last_val=0){
// if(x<0 or y<0 or x>=row or y>=col){
// return;
// }
// if(grid[x][y]=='#' or val[x][y]!=1){
// return;
// }
// val[x][y]+=last_val;
// dfs(grid,val,row,col,x+1,y,val[x][y]);
// dfs(grid,val,row,col,x,y+1,val[x][y]);
// dfs(grid,val,row,col,x-1,y,val[x][y]);
// dfs(grid,val,row,col,x,y-1,val[x][y]);
// }



// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll test;
//     cin>>test;
//     while(test--){
//         ll row,col;
//         cin>>col>>row;

//         char **grid=new char*[row];
//         ll **val=new ll*[row];

//         for(ll i=0;i<row;i++){
//             grid[i]=new char[col];
//             val[i]=new ll[col];
//             for(ll j=0;j<col;j++){
//                 cin>>grid[i][j];
//                 if(grid[i][j]=='.'){
//                     val[i][j]=1;
//                 }else{
//                     val[i][j]=-1;
//                 }
//             }
//         }

//         ll maxd=0;
//         for(ll i=0;i<row;i++){
//             for(ll j=0;j<col;j++){
//                 if(grid[i][j]=='.' and val[i][j]==1){
//                     dfs(grid,val,row,col,i,j);
//                 }
//             }
//         }

//         for(ll i=0;i<row;i++){
//             for(ll j=0;j<col;j++){
//                 if(val[i][j]>maxd){
//                     maxd=val[i][j];
//                 }
//             }
//         }
//         if(maxd!=0) {
//             cout << "Maximum rope length is " << maxd - 1 << ".";
//             br;
//         }
//         else{
//             cout << "Maximum rope length is " << maxd<< ".";
//             br;
//         }

//     }



// }






/////////////////////////////////////////////.          RECURSION SHOWING TLE;
// #include </Users/piyush/Desktop/CP/bits/stdc++.h>
// // #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;



// #define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
// #define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
// #define br cout<<"\n"
// #define max_val 1000000
// #define mod 1000000007
// #define pb(a) push_back(a)

// #define FILE_READ_IN freopen("input.txt","r",stdin);
// #define FILE_READ_OUT freopen("output.txt","w",stdout);

// map<pair<ll,ll>,ll> dp;

// void dfs(char **grid,ll row,ll col,ll x,ll y,ll &maxd,ll temp=0){
//     if(x<0 or y<0 or x>=row or y>=col){
//         return;
//     }
//     pair<ll,ll> val=make_pair(x,y);
//     if(grid[x][y]=='#' or dp[val]==1){
//         return;
//     }
//     if(maxd<temp){
//         maxd=temp;
//     }
//     dp[val]=1;
//     dfs(grid,row,col,x+1,y,maxd,temp+1);
//     dfs(grid,row,col,x,y+1,maxd,temp+1);
//     dfs(grid,row,col,x-1,y,maxd,temp+1);
//     dfs(grid,row,col,x,y-1,maxd,temp+1);
// }


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll test;
//     cin>>test;
//     while(test--){
//         ll row,col;
//         cin>>col>>row;
//         char **grid=new char*[row];
//         for(ll i=0;i<row;i++){
//             grid[i]=new char[col];
//             for(ll j=0;j<col;j++){
//                 cin>>grid[i][j];
//             }
//         }

//         ll maxd=0;
//         for(ll i=0;i<row;i++){
//             for(ll j=0;j<col;j++){
//                 if(grid[i][j]=='.'){
//                     dp.clear();
//                     dfs(grid,row,col,i,j,maxd);
//                 }
//             }
//         }

//         cout<<"Maximum rope length is "<<maxd<<".";br;

//     }



// }
