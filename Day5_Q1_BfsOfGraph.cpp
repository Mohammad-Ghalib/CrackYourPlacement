class Solution {
  public:

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0), bfs;
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }
};