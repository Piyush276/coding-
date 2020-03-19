 #include </Users/piyush/Desktop/CP/bits/stdc++.h>
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


bool colouring(vector<ll> *edge,ll n,bool *visted,map<ll,int> &gender,ll start,ll last=1){
    ll val= {(last==1)?2:1};
    if(gender[start]!=0 and gender[start]!=val){
        return false;
    }
    gender[start]=val;
    last=val;
    val= {(last==1)?2:1};
    bool ret=true;
    visted[start]=true;
    for(ll i:edge[start]){
        if(gender[i]!=0 and gender[i]!=val){
//            cout<<"triggered";br;
            ret=false;
            break;
        }
        if(!visted[i]){
            ret=colouring(edge,n,visted,gender,i,last);
            if(!ret){
                break;
            }
        }
    }
    return ret;

}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll test;
   cin>>test;
   ll counting=1;
   while(test--){
       ll n,v;
       cin>>n>>v;
       vector<ll> *edge=new vector<ll>[n];
       map<ll,int> gender;  // 1 for male 2 for female
       ll e1,e2;
       bool flag=true;

       for(ll i=0;i<v;i++){
           cin>>e1>>e2;
           e1--;
           e2--;
           edge[e1].push_back(e2);
           edge[e2].push_back(e1);
       }

       bool *visted=new bool[n];
       for(ll i=0;i<n;i++){
           visted[i]=false;
       }

       for(ll i=0;i<n;i++){
           if(!visted[i]){
               flag= colouring(edge,n,visted,gender,i);
               if(!flag){
                   break;
               }
           }
       }

       cout<<"Scenario #"<<counting<<":";br;
       if(flag){
           cout<<"No suspicious bugs found!";br;
       }else{
           cout<<"Suspicious bugs found!";br;
       }

//       auto ptr= gender.begin();
//       while(ptr!=gender.end()){
//           cout<<ptr->first<<" "<<ptr->second;br;
//           ptr++;
//       }

       counting++;
   }

}