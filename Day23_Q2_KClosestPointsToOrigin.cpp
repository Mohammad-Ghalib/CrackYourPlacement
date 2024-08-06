class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, pair<int,int>>> temp;

        for(int i=0; i<points.size(); i++){
            double x =(double)points[i][0], y =(double)points[i][1];
            double dist = sqrt(x*x + y*y);
            temp.push_back({dist, {x,y}});
        } 

        sort(temp.begin(), temp.end());
        vector<vector<int>> ans;

        for(int i=0; i<k; i++){
            vector<int> tmp;
            tmp.push_back(temp[i].second.first);
            tmp.push_back(temp[i].second.second);
            ans.push_back(tmp);
        }

        return ans;
    }
};