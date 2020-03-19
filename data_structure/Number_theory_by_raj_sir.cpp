// //Stormer Number N=N*N+1 , max prime factor >= 2*N;
// #include<bits/stdc++.h>
// using namespace std;
// int primes(int n){
// 	int mx=INT_MIN;
// 	while(n%2==0){
// 		mx=2;
// 		n/=2;
// 	}
// 	for(int i=3;i*i<=n;i+=2){
// 		while(n%i==0){
// 			mx=i;
// 			n=n/i;
// 		}
// 	}
// 	if(n>2){
// 		if(n>mx)
// 			mx=n;
// 	}
// 	return mx;
// }
// bool is_stormer(int n){
// 	int temp=n*n+1;
// 	int mx=primes(temp);
// 	if(mx>=2*n){
// 		return true;
// 	}	
// 	else{
// 		return false;
// 	}
// }
// int main(){
// 	int n;
// 	cin>>n;
// 	if(is_stormer(n)){
// 		cout<<"Yes\n";
// 	}
// 	else{
// 		cout<<"No\n";
// 	}
// // }
// #include<bits/stdc++.h>
// using namespace std;
// int x,y,d;
// void extended_Euclid(int a,int b){
// 	if(b==0){
// 		x=1,y=0,d=a;
// 		return;
// 	}
// 	extended_Euclid(b,a%b);
// 	int temp=x;
// 	x=y;
// 	y=temp-(a/b)*y;
// }
// int main(){
// 	int a,b;
// 	cin>>a>>b;
// 	extended_Euclid(a,b);
// 	cout<<x<<" "<<y<<" "d;
// }

//P-smooth number if it's largest prime factor is greater than or eqaul to P
// #include<iostream>
// using namespace std;
// int main()
// {
//     int p=10;   
//     int dp[115]={0};
//     for(int i=2;i<=115;i++)
//     {
//         if(dp[i]==0)
//         for(int j=i;j<=115;j+=i)
//         {
//             dp[j]=i;
//         }
//     }
//     for(int i=11;i<=115;i++) 
//     if(dp[i]==0) 
//     dp[i]=i;
//     int m=0;
//     for(int i=11;i<115 && m!=10;i++)
//     {
//         if(dp[i]>=p)
//             {cout<<i<<" ";
//         m++;}
//     }
//     cout<<endl; m=0;
//     for(int i=2;i<115 && m!=10;i++)
//     {
//         if(dp[i]<=p)
//             {cout<<i<<" ";
//         m++;}
//     }
//     cout<<endl;
//     return 0;
// }
//k jagged numbers