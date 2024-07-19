class Solution {
  public:
    
    bool detectCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(detectCycle(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }
        
        pathVis[node] = 0; 
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0), pathVis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis, pathVis)) return true;
            }
        }
        
        return false;
    }
};