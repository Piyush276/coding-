// C++ program to find integer having maximum number 
// of prime factor in first N natural numbers 
#include<bits/stdc++.h> 

using namespace std; 

// Return smallest number having maximum prime factors. 
int maxPrimefactorNum(int N) 
{ 
	bool arr[N + 5]; 
	memset(arr, true, sizeof(arr)); 

	// Sieve of eratosthenes 
	for (int i = 3; i*i <= N; i += 2) 
	{ 
		if (arr[i]) 
			for (int j = i*i; j <= N; j+=i) 
				arr[j] = false; 
	} 

	// Storing prime numbers. 
	vector<int> prime; 
	prime.push_back(2); 

	for(int i = 3; i <= N; i += 2) 
		if(arr[i]) 
			prime.push_back(i); 

	// Generating number having maximum prime factors. 
	int i = 0, ans = 1; 
	while (ans*prime[i] <= N && i < prime.size()) 
	{ 
		ans *= prime[i]; 
		i++; 
	} 

	return ans; 
} 

// Driven Program 
int main() 
{ 
	int N = 40; 
	cout << maxPrimefactorNum(N) << endl; 
	return 0; 
} 
