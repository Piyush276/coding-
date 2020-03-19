// #include </Users/piyush/Desktop/CP/bits/stdc++.h>
// // #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// #define br cout<<"\n"
// #define mod 1000000007
// #define max_val 10500


// bool sorting(pair<ll,ll> a,pair<ll,ll> b){
//     if(a.first<a.second){
//         return true;
//     }
//     return false;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll n;
//     cin>>n;
//     vector<pair<ll,ll>> a;
//     ll e1,e2;
//     for(ll i=0;i<n;i++){
//         cin>>e1>>e2;
//         a.push_back(make_pair(e1,e2));
//     }
//     sort(a.begin(),a.end(),sorting);
//     for(ll i=0;i<n;i++){
//         cout<<a[i].first<<" "<<a[i].second;br;
//     }
// }

// C++ program for activity selection problem 
// when input activities may not be sorted. 
#include <bits/stdc++.h> 
using namespace std; 

// A job has a start time, finish time and profit. 
struct Activitiy 
{ 
    int start, finish; 
}; 


bool activityCompare(Activitiy s1, Activitiy s2) 
{ 
    return (s1.finish < s2.finish); 
} 
void printMaxActivities(Activitiy arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr+n, activityCompare); 

    int i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 

    for (int j = 1; j < n; j++) 
    { 
    if (arr[j].start >= arr[i].finish) 
    { 
        cout << "(" << arr[j].start << ", "
            << arr[j].finish << "), "; 
        i = j; 
    } 
    } 
} 


int main() 
{ 
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, 
                                    {5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMaxActivities(arr, n); 
    return 0; 
} 





/// incomplete. no idea

#include </Users/piyush/Desktop/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

typedef vector<vector<ll>> vvl;
typedef vector<ll> vll;


#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 1000000
#define mod 1000000007
#define pb(a) push_back(a)

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);


/// 0 not used 1 in stack and 2 in complete

map<ll,ll> dp;
map<pair<ll,ll>,ll> store;      // s->e    1 false 2 true

bool count_false(vector<ll> *edge,ll n,map<ll,ll> &visit,ll start,ll end, ll &temp){
    if(start==end){
        return true;
    }
    visit[start]=1;
    for(ll i:edge[start]){
        if(visit[i]==0){
            pair<ll,ll> val;
            val=make_pair(start,i);
            if(store[val]==1){
                temp+=1;
                if(count_false(edge,n,visit,i,end,temp))
                    return true;
            }else{
                if(count_false(edge,n,visit,i,end,temp))
                    return true;
            }
        }
    }
    return false;
}

stack<ll> s;
bool count_odd_false_in_graph(vector<ll> *edge,ll n,bool *visted,ll start=0){
    s.push(start);
    dp[start]=1;
    visted[start]=true;
    for(ll i:edge[start]){
        if(dp[i]==1 and !visted[i]){
            ll temp=1;
            map<ll,ll> visit;
            count_false(edge,n,visit,start,i,temp);
            cout<<temp;br;
            if(temp%2!=0){
                return true;
            }
        }
        dp[i]=1;
        count_odd_false_in_graph(edge,n,visted,i);
    }
    dp[start]=2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case=1;
    while(test_case!=0) {
        dp.clear();
        store.clear();
        cin >> test_case;
        ll e1=0;
        if(test_case==0){
            break;
        }
        vector<ll> *edge=new vector<ll>[test_case];
        string value;
        bool flag=true;
        ll test_case1=test_case;
        while (test_case--) {
            ll e2;
            cin>>e2>>value;
            e2--;
            edge[e1].pb(e2);
            pair<ll,ll> val;
            val=make_pair(e1,e2);
            if(value=="false")
                store[val]=1;
            else
                store[val]=2;
            ++e1;
        }
        bool *visted=new bool[test_case1];
        for(ll i=0;i<test_case1;i++){
            visted[i]=false;
        }
        if(count_odd_false_in_graph(edge,test_case,visted)){
            cout<<"PARADOX";
        }else{
            cout<<"NOT PARADOX";
        }
        br;
        delete [] visted;
    }




}
