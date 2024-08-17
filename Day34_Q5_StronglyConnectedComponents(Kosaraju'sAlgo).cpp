class Solution{
    
    private: 
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                dfs(nbr, adj, vis, st);
            }
        }
        st.push(node);
    }
    
    void dfs(int node, vector<int> adjT[], vector<int>& vis){
        vis[node] = 1;
        for(auto nbr: adjT[node]){
            if(!vis[nbr]){
                dfs(nbr, adjT, vis);
            }
        }
    }
    
	public:
	
    int kosaraju(int V, vector<vector<int>>& adj){
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto nbr: adj[i]){
                adjT[nbr].push_back(i);
            }
        }
        
        int scc=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                dfs(node, adjT, vis);
                scc++;
            }
        }
        
        return scc;
    }
};