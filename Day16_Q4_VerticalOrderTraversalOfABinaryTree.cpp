class Solution {
public:

    static bool compare(pair<int, int> p1, pair<int, int> p2){
        if(p1.second < p2.second) return true;
        if(p1.second > p2.second) return false;
        return p1.first < p2.first;
    }
    
    void dfs(TreeNode* root, int level, int height, map<int, vector<pair<int, int>>>& m){
        if(!root) return;
        m[level].push_back({root->val, height});
        
        dfs(root->left, level-1, height+1, m);
        dfs(root->right, level+1, height+1, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<pair<int, int>>> m;
        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(root, 0, 0, m);
        
        for(auto it=m.begin(); it!=m.end(); it++){
            sort(it->second.begin(), it->second.end(), compare);
            for(int i=0; i<it->second.size(); i++){
                temp.push_back(it->second[i].first);
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
        
    }
};