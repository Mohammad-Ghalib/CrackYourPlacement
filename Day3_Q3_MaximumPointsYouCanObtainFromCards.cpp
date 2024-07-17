class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0, sum=0;
        for(int i=0; i<k; i++) ans += cardPoints[i];

        sum = ans;

        for(int i=k-1, j=cardPoints.size()-1; i>=0; i--,j--){
            sum -= cardPoints[i];
            sum += cardPoints[j];

            ans = max(ans,sum);
        }

        return ans;
    }
};