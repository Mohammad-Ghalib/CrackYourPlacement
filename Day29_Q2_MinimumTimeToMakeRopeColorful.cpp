class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0, temp=0, j;

        for(int i=1; i<colors.size(); i++){

            if(colors[i] == colors[i-1]){
                temp = neededTime[i-1];
                ans += neededTime[i-1];
                j=i;
                while(j<colors.size() && colors[i-1] == colors[j]){
                    temp = max(temp, neededTime[j]);
                    ans += neededTime[j];
                    j++;
                }
                i=j;
                ans -= temp;
            }
        }

        return ans;
    }
};