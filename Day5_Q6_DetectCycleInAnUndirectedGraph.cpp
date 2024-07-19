class Solution {
  public:

    bool detectCycle(int src, vector<int> adj[], vector<int>& vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first, parent = q.front().second;
            q.pop();
            vis[node] = 1;
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push({it, node});
                }
                else if(it != parent) return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};