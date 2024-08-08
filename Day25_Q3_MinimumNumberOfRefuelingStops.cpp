class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(), curr = startFuel, i = 0, result = 0;
        priority_queue<int> pq; 

        while(curr < target) { 
            while(i < n && curr >= stations[i][0]) {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()) return -1;
            
            int dist = pq.top();
            pq.pop();
            
            curr += dist;
            result++;
        }
        
        return result;
        
    }
};