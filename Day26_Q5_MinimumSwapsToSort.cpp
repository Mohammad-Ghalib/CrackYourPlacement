class Solution {
    public:
    
    int minSwaps(vector<int>&nums){

        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end());
        
        int swaps=0;
        
        for(int i=0;i<nums.size();i++){
            if(i!=(v[i].second)){
                swap(v[i],v[v[i].second]);
                swaps++;
                i--;
            }
                
        }
        return swaps;
    }
};