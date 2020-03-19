#include </Users/piyush/Desktop/CP/bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
 
void dfs(int start, vector<int>* edges, bool* visited, stack<int> &finished)
{
	visited[start] = true;
	for(int i = 0; i < edges[start].size(); i++)
	{
		if(!visited[edges[start][i]])
			dfs(edges[start][i],edges,visited,finished);
	}
	finished.push(start);
}
void dfs2(int start, vector<int>* edges, bool* visited)
{
	visited[start] = true;
	for(int i = 0; i < edges[start].size(); i++)
	{
		if(!visited[edges[start][i]])
			dfs2(edges[start][i],edges,visited);
	}
}
int solve(vector<int>* edges, int n)
{
	bool *visited = new bool[n]();
	stack<int> finished;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
			dfs(i,edges,visited,finished);
	}
	int output = 0;
	for(int i = 0; i < n; i++)
		visited[i] = false;
	while(finished.size()!=0)
	{
		int ele = finished.top();
		finished.pop();
		if(!visited[ele])
		{
			dfs2(ele,edges,visited);
			output++;
		}
	}
	delete[] visited;
	return output;
}
 
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	
		int n;
		cin >> n;
		vector<int>* edges = new vector<int>[n];
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int j, k;
			cin >> j >> k;
			edges[j - 1].push_back(k - 1);
//		edges[k - 1].push_back(j - 1);
		}
		cout << solve(edges,n)<<"\n";
		delete[] edges;
	}
	return 0;
}