 
void dfs( vector<int> adj[],int V,int x,stack<int> &store,bool *visted){
    visted[x]=true;
    for(int i:adj[x]){
        if(!visted[i]){
            dfs(adj,V,i,store,visted);
        }
    }
    store.push(x);
}

int* topoSort(int V, vector<int> adj[])
{
    int *ans=new int[V];
    bool *visted=new bool[V];
    for(int i=0;i<V;i++){
        visted[i]=false;
    }
    stack<int> store;
    for(int i=0;i<V;i++){
       if(!visted[i]){
           dfs(adj,V,i,store,visted);
       } 
    }
    int pos=0;
    while(!store.empty()){
        ans[pos]=store.top();
        store.pop();
        pos++;
    }
    return ans;
       
}
