class DisjointSet{
    vector<int> parent, size;
    
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulpU = findParent(u), ulpV = findParent(v);
        if(ulpU == ulpV) return;
        
        if(size[ulpU] < size[ulpV]){
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
        else{
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};

class Solution {
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int,int>>> edges;
        
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int node = i, adjNode = it[0], wt = it[1];
                edges.push_back({wt, {node, adjNode}});
            }
        }        
        sort(edges.begin(), edges.end());
        
        int mstWt=0;
        
        DisjointSet ds(V);
        
        for(auto it: edges){
            int wt = it.first, u = it.second.first, v = it.second.second;
            if(ds.findParent(u) != ds.findParent(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
    }
};