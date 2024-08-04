typedef pair<int, int> pi;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if(nums.size() == k) return nums;
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> ans;
        map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};