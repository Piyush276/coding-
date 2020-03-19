
// #include </Users/piyush/Desktop/CP/bits/stdc++.h>
#include <bits/stdc++.h>
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll test_case;
	cin>>test_case;
    while(test_case--){
        ll n;
        cin>>n;
        
    }

}

//////////////////////////////////////////////////////////



N = int(input())
A = list(map(lambda x: int(x), input().split()))
mod=1000000007
 
def find(N, A, i=0, l=-1, g=0, memory={}):
    if i == N:
        if g == 1:
            return 1
        else:
            return 0
 
    if (i, l, g) in memory:
        return memory[i, l, g]
 
    t1,t2=0,0
    t1 = find(N, A, i+1, l, g, memory)
    if A[i] > l:
        t2 = find(N, A, i+1, A[i], gcd(g, A[i]), memory)
 
    res = t1 + t2
    while res >= mod:
        res -= mod
    memory[i, l, g] = res
    return res
  
def gcd(a, b):
    if a > b:
        a, b = b, a
 
    while a != 0:
        b = b % a
        a, b = b, a
 
    return b
 
 
print(find(N, A))
7:13 PM
10/4/2019
Art Bal
10:18 AM
SUNDAY
void Helper(bool ar[10],int k,vector<int> &temp,bool &isEmpty){
    if(k<0) return;
    if(k==0){
        isEmpty=0;
        cout<<"(";
        int i;
        for(i=0;i<temp.size()-1;i++){
            cout<<temp[i]<<" ";
        }
        cout<<temp[i]<<")";
        return;
    }
    int prev=1;
    if(temp.size()>=1) prev=temp[temp.size()-1];
    for(int i=prev;i<=9;i++){
        if(ar[i]){
            temp.push_back(i);
            Helper(ar,k-i,temp,isEmpty);
            temp.pop_back(); // FOr Backtracking.
        }
    }
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n;
	    bool ar[10]={0};
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        ar[x]=1;
	    }
	    cin>>k;
	    vector<int> temp;
	    bool i… Read more
3:19 AM
MONDAY
///////////////////////   basic   template


#include </Users/piyush/Desktop/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1500

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){

    }

}

///////////////////////   Gold Mine Problem


ll get_max(ll **grid,ll row,ll col,ll realrow){
    ll maxi=-1;
    if(row-1>=0){
        if(maxi<grid[row-1][col-1]){
            maxi=grid[row-1][col-1];
        }
    }
    if(maxi<grid[row][col-1]){
            maxi=grid[row][col-1];
    }
    if(row+1<realrow){
        if(maxi<grid[row+1][col-1]){
            maxi=grid[row+1][col-1];
    }
    }
    return maxi;
}

// void show(ll **grid,ll row,ll col){
//     for(ll i=0;i<row;i++){
//             for(ll j=0;j<col;j++){
//                 cout<<grid[i][j]<<" ";
//             }
//             br;
//         }
//         br;
// }

ll solve(ll **grid,ll row,ll col){
    ll temp;
    for(ll y=1;y<col;y++){
        for(ll x=0;x<row;x++){
            temp=get_max(grid,x,y,row);
            grid[x][y]+=temp;
        }
        // show(grid,row,col);
    }
    ll maxi=-1;
    for(ll x=0;x<row;x++){
            if(maxi<grid[x][col-1])
            maxi=grid[x][col-1];
        }
    return maxi;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll row,col,t;
	cin>>t;
    while(t--){
        cin>>row>>col;
        ll *grid=new ll[row];
        for(ll i=0;i<row;i++){
            grid[i]=new ll[col];
            for(ll j=0;j<col;j++){
                cin>>grid[i][j];
            }
        }
        cout<<solve(grid,row,col);
        br;
        
    }
    
    
}


///////////////////////////////  Maximum sum Problem

 map<ll,ll> store;
ll solve( ll n){
    if(store[n]!=0){
        return store[n];
    }
    if(n==0){
        return 0;
    }
    ll ans=max(n,solve(n/2)+solve(n/3)+solve(n/4));
    store[n]=ans;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    cout<<solve(n)<<endl;
	}
	return 0;
}

///////////////////////////////////////////     ROD CUTTING	



#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

long DP[100];
std::vector<int> array;
long getMax(int length)
{
    if(length==array.size()) return 0;
    if(length>array.size()) return INT_MIN;
    
    if(DP[length]!=-1)  return DP[length];
    
    long res=0;
    for(int i=0; i<array.size(); i++)
    {
        res=std::max(res, array[i]+getMax(length+i+1));
    }
    return DP[length]=res;
}

int main() 
{
    int t, n, temp;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        memset(DP, -1, sizeof(DP));
        array.clear();
        for(int i=0; i<n; i++)
        {
            cin>>temp;
            array.push_back(temp);
        }
        cout<<getMax(0)<<endl;
    }
}




///////////////////////////////////////   Temple Offerings

ll solve(ll *a,ll n){
    ll *val=new ll[n];
    for(ll i=0;i<n;i++){
            val[i]=0;
        }
    val[0]=1;
    for(ll i=1;i<n;i++){
            
            if(a[i]>a[i-1]){
                val[i]=val[i-1]+1;
            }
            else if(a[i]==a[i-1]){
                val[i]=1;
            }
            else if(a[i]<a[i-1]){
                val[i]=1;
                ll ii=i-1;
                while(ii!=-1){
                    if(a[ii+1]<a[ii] and !(val[ii+1]<val[ii])){
                        val[ii]++;
                    }
                    ii--;
                }
            }
    }
    
    ll total=0;
    for(ll i=0;i<n;i++){
           //cout<<val[i]<<" ";
            total+=val[i];
        }
       // br;
        return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,t;
	cin>>t;
    while(t--){
        cin>>n;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<solve(a,n);br;
    }

}


///////////////////////////////////////   Minimum number of deletions

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sl(x) scanf("%lld",&x)
#define p printf
int lcps(string s1,string s2){
    int n=s1.size();
    int lcs[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
        if(i==0||j==0)
        	lcs[i][j]=0;
        else if(s1[i-1]==s2[j-1])
        	lcs[i][j]=1+lcs[i-1][j-1];
        else 
        	lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        cout<<lcs[i][j]<<"  ";
        }
        br;
    }
    br;
    return lcs[n][n];
}
int main()
 {
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;string s1;
        cin>>n>>s1;
        string s2=s1;
        reverse(s2.begin(),s2.end());
        cout<<n-lcps(s1,s2)<<endl;
    }
	return 0;
}


///////////////////////////////////////   Longest Palindromic Subsequence



int main() {
int t;cin>>t;
  while(t--){
      string s;cin>>s;
      int j,maxx=0,n=s.size();int l=2,t[n][n]={};
      for(int i=0;i<n;i++)t[i][i]=1;
      while(l<=n){
			for(int i=0;i<=n-l;i++)
				if(s[i]==s[i+l-1])  
					t[i][i+l-1]=2+t[i+1][i+l-2];
		        else	
		        	t[i][i+l-1]=max(t[i][i+l-2],t[i+1][i+l-1]);
			   	l++;
		}	cout<<t[0][n-1]<<endl;
  }
	return 0;
}


									/////////  OR
	



#include<stdio.h> 
#include<string.h> 


int max (int x, int y) { return (x > y)? x : y; }

int lps(char *str)
{
    int n = strlen(str);
    int i, j, cl;
    int L[n][n];
    memset(L,0,sizeof(L));
    for (i = 0; i < n; i++)
        L[i][i] = 1;

    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i+1][j-1] + 2;
            else
                L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
//        for (i = 0; i < n; i++){
//            for (j = 0; j < n; j++){
//                cout<<L[i][j]<<" ";
//            }
//            br;
//        }
//        br;
    }

//    for (i = 0; i < n; i++){
//        for (j = 0; j < n; j++){
//            cout<<L[i][j]<<" ";
//        }
//        br;
//    }
//    br;


    return L[0][n-1];
}

int main()
{
    char seq[] = "agbdba";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d", lps(seq));
    getchar();
    return 0;
}



///////////////////////////////////////   Skip the work


ll solve(ll *a,ll n,ll pos=0,bool prev=true){
    if(pos==n){
        return 0;
    }
    ll first=LONG_LONG_MAX;
    ll second=LONG_LONG_MAX;
    first=a[pos]+solve(a,n,pos+1,true);
    if(prev!=false)
    second= solve(a,n,pos+1,false);
    return min(first,second);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,t;
	cin>>t;
    while(t--){
        cin>>n;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<solve(a,n)<<endl;
    }

}

							///////// INCASE
				
	public static int skip_one(int arr[],int n)
     {
         int incl=arr[0];
         int excl=0;
         int res;
         for(int i=1;i<n;++i)
         {
             res=arr[i]+Math.min(incl,excl);
             excl=incl;
             incl=res;
             
         }
         return Math.min(excl,incl);
     }


///////////////////////////////////////   Maximum Sum Bitonic Subsequence



ll bitonic(ll *input,ll n,ll pos=0,ll tempsum=0,ll prev=0,bool flag_d=false){
    if(pos==n){
        return tempsum;
    }
    ll p1=0,p2=0,p3=0;
    if(prev<input[pos] and flag_d==false){
        p1=max(p1,bitonic(input,n,pos+1,tempsum+input[pos],input[pos],false));
    }
    if(prev>input[pos]){
        p2=max(p2,bitonic(input,n,pos+1,tempsum+input[pos],input[pos],true));
    }
    p3=max(p3,bitonic(input,n,pos+1,tempsum,prev,flag_d));
    return max(p1,max(p2,p3));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,t;
	cin>>t;
    while(t--){
        cin>>n;
        ll *input=new ll[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        cout<<bitonic(input,n);br;
    }

}


///////////////////////////////////////   Reach a given score



ll dp11[1000][1000];
ll solve(ll n,ll *dp,ll pos=0,ll tempsum=0){
    if(tempsum==n){
        return 1;
    }
    if(pos==3 or tempsum>n){
        return 0;
    }
    if(dp11[pos][tempsum]!=0){
        return dp11[pos][tempsum];
    }
    ll first=solve(n,dp,pos,tempsum+dp[pos]);
    ll second=solve(n,dp,pos+1,tempsum);
    dp11[pos][tempsum]=first+second;
    return first+second;
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n;
	cin>>t;
	ll *dp=new ll[3];
	dp[0]=3;
	dp[1]=5;
	dp[2]=10;
	while (t--){
	    memset(dp11,0,sizeof(dp11));
	    cin>>n;
	    cout<<solve(n,dp);
	    br;
	}
	return 0;
}


						///////////////  OR BEST SOLUTION

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f(int a[],int n,int sum,int dp[][5000])
{
  if(sum==0)
  return 1;
  if(sum<=0 || n<=0)
  return 0;
  if(dp[n][sum]!=0)
  return dp[n][sum];
  else
  {
     dp[n][sum]=f(a,n-1,sum,dp)+f(a,n,sum-a[n-1],dp);
     return dp[n][sum];
  }
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	   int a[]={3,5,10};
	   int n=3;
	   int sum;
	   cin>>sum;
	   int dp[n+1][5000];
	   memset(dp,0,sizeof(dp));
	   cout<<f(a,n,sum,dp)<<endl;
	   
	}
	
	return 0;
}

///////////////////////////////////////   Count of strings that can be formed using a, b and c under given constraints


for _ in range(int(input())):
    n=int(input())
    print(1+2*n+((n*(n-1)*(n+1))//2))


///////////////////////////////////////    Number of Unique Paths


ll solve(ll r,ll c,ll x=0,ll y=0){
    if(x==r-1 and y==c-1){
        return 1;
    }
    if(x>=r or y>=c){
        return 0;
    }
    return solve(r,c,x+1,y)+solve(r,c,x,y+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,t,r,c;
	cin>>t;
    while(t--){
     cin>>r>>c;
     cout<<solve(r,c);br;
    }

}

///////////////////////////////////////    Count number of hops

map<ll,ll> dp;

ll solve(ll n){

    if(n==0 or n==1){
        dp[n]=1;
        return 1;
    }
    if(n==2){
        dp[2]=1;
        return 2;
    }
    if(n==3){
        dp[3]=4;
        return 4;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=0)
    return dp[n];
    dp[n]=solve(n-1)+solve(n-2)+solve(n-3);
    return dp[n];
    
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,t;
	cin>>t;
    while(t--){
        cin>>n;
        cout<<solve(n);br;
    }

}

///////////////////////////////////////    Distinct occurrences

int solve(string s,string t,int pos1,int pos2){
        if(pos2 == 0)
          return 1;
        
        if(pos1 == 0)
          return 0;
          
        if(s[pos1-1] != t[pos2-1])
           return solve(s,t,pos1-1,pos2);
        else
          return solve(s,t,pos1-1,pos2) + solve(s,t,pos1-1,pos2-1);
}
int subsequenceCount(string S, string T)
{
  //Your code here
  return solve(S,T,S.size(),T.size());
}
 

///////////////////////////////////////    Minimum Operations

#include <iostream>
using namespace std;

int main() {
	int t,n,m,i,j,k,p;
	cin>>t;
	while(t--){
	cin>>n;
	int count=0;
	while(n>0){
	if(n%2!=0){
		n=n-1;
	}
	else{
		n=n/2;
	}
	count++;
	}
	printf("%d\n",count);
	}
}

///////////////////////////////////////////  Minimal moves to form a string



long getMin(int i, string cur, string input)
{
    if(i>=input.size() && cur==input) return 0;
    if(i>=input.size() && cur!=input) return _INT_MAX_;
    if(input.find(cur) == std::string::npos) return _INT_MAX_;
    
    if(i==0) return 1+getMin(i+1, cur+input[i], input);
    return 1+std::min(getMin(i*2, cur+cur, input), getMin(i+1, cur+input[i], input));
}

int main()
{
  int n, t;
  cin>>t;

  while(t--)
  {
    std::string input;
    cin>>input; 
    cout<<getMin(0, "", input)<<endl;
  }
}


///////////////////////////////////////////  Paths to reach origin


ll solve(ll r,ll c){
    if(r==0 and c==0){
        return 1;
    }
    if(r<0 or c<0){
        return 0;
    }
    return solve(r-1,c)+solve(r,c-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,t,r,c;
	cin>>t;
    while(t--){
        cin>>r>>c;
        cout<<solve(r,c);br;
    }

}

////////////////////////////////////////   0/1 KNAPsack 



// #include </Users/piyush/Desktop/CP/bits/stdc++.h>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 1050
#define mod 1000000007
#define pb(a) push_back(a)

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

class node{
public:
    ll item;
    ll w;
};

ll table[max_val][max_val];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll max_w;
        cin>>max_w;
        node *val=new node[n];

        for(ll i=0;i<n;i++){
            cin>>val[i].item;
        }
        for(ll i=0;i<n;i++){
            cin>>val[i].w;
        }
        for(ll i=0;i<n+1;i++){
            for(ll j=0;j<max_w+1;j++){
                if(i==0 or j==0){
                    table[i][j]=0;
                    continue;
                }
                if(val[i-1].w<=j){
                    table[i][j]=max(val[i-1].item+table[i-1][j-val[i-1].w],table[i-1][j]);
                    continue;
                }
                table[i][j]=table[i-1][j];
            }
        }

        cout<<table[n][max_w];br;
    }

}

/////////////////////////////////  longest common subseq


#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;



#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define max_val 150
#define mod 1000000007
#define pb(a) push_back(a)

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);


ll table[max_val][max_val];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll s1,s2;
        cin>>s1>>s2;
        string a,b;
        cin>>a>>b;

        for(ll i=0;i<s2+1;i++){
            for(ll j=0;j<s1+1;j++){
                if(i==0 or j==0){
                    table[i][j]=0;
                    continue;
                }
                if(a[j-1]==b[i-1]){
                    table[i][j]=table[i-1][j-1]+1;
                }else{
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
                }
            }
        }

//        for(ll i=0;i<s2+1;i++){
//            for(ll j=0;j<s1+1;j++){
//                cout<<table[i][j]<<" ";
//            }
//            br;
//        }

        cout<<table[s2][s1];br;
    }

}
							//////////////// longest incresing subsequence

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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll *a=new ll[n];
        ll *dp=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            dp[i]=1;
        }

        for(ll i=0;i<n;i++){
            for(ll j=0;j<i;j++){
                if(dp[j]>=dp[i] and a[i]>a[j]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
        }
        ll maxi=INT_MIN;
        for(ll i=0;i<n;i++){
            //cout<<dp[i]<<" ";
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        //br;
        cout<<maxi<<endl;


    }

}

///////////////////////////////////////////////      subset sum 


#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;



#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define mod 1000000007
#define pb(a) push_back(a)

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);


#define max_val 100000

bool table[103][max_val];

bool solve(ll sum,ll *a,ll n){

    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=sum;j++){
            if(i==0 and j==0){
                table[i][j]=true;
                continue;
            }
            if(i==0){
                table[i][j]=false;
                continue;
            }
            if(j==0){
                table[i][j]=true;
                continue;
            }


            if(j<a[i-1]){
                table[i][j]=table[i-1][j];
            }
            else{
                table[i][j]=table[i-1][j-a[i-1]];
            }
            if(table[i-1][j]){
                table[i][j]=true;
            }
            if(j==sum and table[i][j]){
                return true;
            }
        }
    }

//    for(ll i=0;i<=n;i++){
//        for(ll j=0;j<=sum;j++){
//            if(table[i][j]){
//                cout<<"T";
//            }else{
//                cout<<"F";
//            }
//            cout<<" ";
//        }
//        br;
//    }



        return false;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll *a=new ll[n];
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2!=0){
            cout<<"NO";
            br;
            continue;
        }
        sum=sum/2;
        if(solve(sum,a,n)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        br;
    }

}


///////////////////////////////////////////////      matrix chain multiplication



// #include </Users/piyush/Desktop/CP/bits/stdc++.h>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1500

#define INF 10000000000

ll table[max_val][max_val];

ll solve(ll *a,ll n){
    for(ll l=2;l<n;l++){
        for(ll i=0;i<n-l;i++){
            ll j=i+l;
            table[i][j]=INF;
            for(ll k=i+1;k<j;k++){
                ll temp=table[i][k]+table[k][j]+a[i]*a[k]*a[j];
                if(table[i][j]>temp)
                    table[i][j]=temp;
            }
        }
    }
    return table[0][n-1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){
        ll n;
        cin>>n;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<solve(a,n);br;
    }

}

 //////////////////////////////////////   mininum no of coins coin changing
#include </Users/piyush/Desktop/CP/bits/stdc++.h>
// #include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1500

#define INF 10000000000



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){
        ll k;
        cin>>k;
        ll n;
        cin>>n;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll *dp=new ll[k+10];
        dp[0]=0;
        for(ll i=1;i<k+10;i++){
            dp[i]=INF;
        }

        for(ll i=0;i<n;i++){
            ll val=a[i];
            for(ll j=1;j<=k;j++){
                if(j<val){
                    continue;
                }
                dp[j]=min(1+dp[j-val],dp[j]);
            }
        }

//        for(ll j=1;j<=k;j++){
//            cout<<dp[j]<<" ";
//        }
//        br;
        if(dp[k]!=INF)
        cout<<dp[k];
        else{
            cout<<-1;
        }
        br;

    }

}

////////////////////////////////////////////////////  edit distance


#include </Users/piyush/Desktop/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1500

ll table[max_val][max_val];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,test_case;
    cin>>test_case;
    while(test_case--){
        ll la,lb;
        cin>>la>>lb;
        string a,b;
        cin>>a>>b;
        for(ll i=0;i<la+1;i++){
            for(ll j=0;j<lb+1;j++){
                if(i==0){
                    table[i][j]=j;
                    continue;
                }
                if(j==0){
                    table[i][j]=i;
                    continue;
                }
                ll min_val=min(table[i-1][j],min(table[i-1][j-1],table[i][j-1]));
                if(a[i-1]==b[j-1]){
                    table[i][j]=table[i-1][j-1];
                }else{
                    table[i][j]=min_val+1;
                }
            }
        }

//        for(ll i=0;i<la+1;i++){
//            for(ll j=0;j<lb+1;j++){
//                cout<<table[i][j]<<" ";
//            }
//            br;
//        }
        cout<<table[la][lb];br;
    }

}

//////////////////////////////////////////////////////  longest palindrome subseq
///


#include </Users/piyush/Desktop/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1500

ll table[max_val][max_val];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){
        memset(table,0,sizeof(table));
        string a;
        cin>>a;
        ll n=a.size();
        for(ll i=0;i<n;i++){
            ll k=0;
            for(ll j=i;j<n;j++){
                if(k>=n) break;
                if(i==0){
                    table[k++][j]=1;
                    continue;
                }
                ll val=max(table[k][j-1],table[k+1][j]);
                if(a[k]==a[j]){
                    table[k][j]=table[k+1][j-1]+2;
                }else{
                    table[k][j]=val;
                }
                k++;
            }
        }
//
//        for(ll i=0;i<n;i++){
//            for(ll j=0;j<n;j++){
//                cout<<table[i][j]<<"\t";
//            }
//            br;
//        }

        cout<<table[0][n-1];br;

    }

}


/////////////////////////////////////////////////// print all subseq
///

 #include </Users/piyush/Desktop/CP/bits/stdc++.h>
//#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 1500

void all_subseq(string a,ll n,ll ind=0,string out=""){
    if(ind>=n) {
        cout<<out;br;
        return;
    }
    all_subseq(a,n,ind+1,out+a[ind]);
    all_subseq(a,n,ind+1,out);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){
        string a;
        cin>>a;
        all_subseq(a,a.size());
    }

}

//////////////////////////////////////////////////////////  rod cutting problem
///

//  #include </Users/piyush/Desktop/CP/bits/stdc++.h>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define br cout<<"\n"
#define max_val 4001

ll table[10][max_val];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test_case;
    cin>>test_case;
    while(test_case--){
        ll l;
        cin>>l;
        ll n=3;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++) {
            cin >> a[i];
        }

        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=l;j++){
                if(i==0 or j==0){
                    table[i][j]=0;
                    continue;
                }
                if(a[i-1]>j){
                    table[i][j]=table[i-1][j];
                    continue;
                }
                if(a[i-1]==j){
                    table[i][j]=1;
                    continue;
                }
                if(table[i][j - a[i - 1]]==0){
                    table[i][j]=table[i-1][j];
                    continue;
                }
                table[i][j] = max(table[i - 1][j], 1 + table[i][j - a[i - 1]]);

            }
        }

        // for(ll i=0;i<=n;i++){
        //     for(ll j=0;j<=l;j++){
        //         cout<<table[i][j]<<" ";
        //     }
        //     br;
        // }
        cout<<table[n][l];br;

    }

}
///////////////////////////////////////  all possible string spaces
///
void solve(string a,int n,set<string> &ans,int ind=0,string out=""){
    if(ind==n){
        ans.insert(out);
        return;
    }
    if(ind>=n) return;
    string temp(1,a[ind]);
    temp+=" ";
    solve(a,n,ans,ind+1,out+temp);
    solve(a,n,ans,ind+1,out+a[ind]);
}


void  printSpace(char str[])
{
//Your code here
    string a(1,str[0]);
    for(int i=1;i<strlen(str);i++){
        a+=str[i];
    }
    set<string> ans;
    solve(a,a.size(),ans);

    auto pt1=ans.rbegin();
    for(int i=1;i<ans.size();i++){
        if(i%2==0){
            cout<<*pt1<<"$";
        }
        pt1++;
    }
    cout<<*pt1<<"$";
}

/////////////////////////////   Count of strings that can be formed using a, b and c under given constraints
///

#include <iostream>
#include <cstring>
using namespace std;

int DP[1000][2][3];
int getCount(int n, int b=1, int c=2)
{
    if(n==0) return 1;
    if(DP[n][b][c]!=-1) return DP[n][b][c];
    int res=0;

    if(b>0) res+=getCount(n-1, b-1, c);
    if(c>0) res+=getCount(n-1, b, c-1);
    return DP[n][b][c] = res+getCount(n-1, b, c);
}

int main()
{
    int t, n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        memset(DP, -1, sizeof(DP));
        cout<<getCount(n)<<endl;
    }
}


//////////////////////////////////////////////			floyd warshell
///
#include <iostream>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--){
	    int V; cin>>V;
	    int graph[V][V]; int d[V][V];
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            cin>>graph[i][j];
	            d[i][j]=graph[i][j];
	        } 
	    }
	    for(int k=0;k<V;k++){
	        for(int i=0;i<V;i++){
    	        for(int j=0;j<V;j++){
    	            if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
    	        } 
    	    }
	    }
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            if(d[i][j]==10000000) cout<<"INF"<<" ";
	            else cout<<d[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}


//////////////////////////////////////////////			box stacking
///

typedef tuple<int,int,int> t3i;
bool baseArea_comp(t3i &a,t3i &b){
    return get<0>(a)*get<1>(a) > get<0>(b)*get<1>(b);
}
int max(int a,int b){
    return a>b?a:b;
}
int maxHeight(int h[],int w[],int l[],int n)
{
    vector<tuple<int,int,int> > v;
    //Generate all rotation of boxes
    for(int i=0;i<n;i++){
        if(l[i] > w[i])
            v.push_back(make_tuple(l[i],w[i],h[i]));
        else
            v.push_back(make_tuple(w[i],l[i],h[i]));
        if(w[i] > h[i])
            v.push_back(make_tuple(w[i],h[i],l[i]));
        else
            v.push_back(make_tuple(h[i],w[i],l[i]));
        if(h[i] > l[i])
            v.push_back(make_tuple(h[i],l[i],w[i]));
        else
            v.push_back(make_tuple(l[i],h[i],w[i]));
    }
    
    //sort acording to base area
    sort(v.begin(),v.end(),baseArea_comp);
    
  
    vector<int> ht;
    
    //store Height using concept of LIS(longest increasing subsequence)
    for(int i=0;i<3*n;i++)
        ht.push_back(get<2>(v[i]));
    int H=0;
    for(int i=1;i<3*n;i++){
        for(int j=0;j<i;j++){
            //CAN i go on top of j?? IF  YES execute below
            if(get<0>(v[i]) < get<0>(v[j]) && get<1>(v[i]) < get<1>(v[j])
                             &&  ht[j] + get<2>(v[i]) > ht[i])
            {
                ht[i] = ht[j] + get<2>(v[i]);
                
                //finding max height
                    H = max(H,ht[i]);
            }
        }
    }
    return H;
}

