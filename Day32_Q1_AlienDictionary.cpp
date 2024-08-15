class Solution{
    public:

    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        int inDegree[K] = {0};
        
        for(int i=0; i<K; i++){     
            for(int j=0; j<adj[i].size(); j++){
                inDegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<K; i++){
            if(!inDegree[i]) q.push(i);
        }
        
        string order="";
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order += char(node + 97);
            
            for(auto it: adj[node]){
                inDegree[it]--;
                if(!inDegree[it]) q.push(it);
            }
        }

        return order;
    }
};