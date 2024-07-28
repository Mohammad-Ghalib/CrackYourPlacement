class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int possible=0;

        for(int i=0; i<n; i++){
            cost[i] = gas[i] - cost[i];
            possible += cost[i];
        }

        if(possible < 0) return -1;

        int gasLeft=0, in=0;

        for(int i=0; i<n; i++){
            gasLeft += cost[i];
            if(gasLeft < 0){
                gasLeft = 0;
                in=(i+1)%n;
            }
        }

        return in;
    }
};