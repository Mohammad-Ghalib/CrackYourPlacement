class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), c0=1;

        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0) c0 = 0;
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=m-1; i>=0; i--){      
            for(int j=n-1; j>0; j--){
                if(!matrix[0][j] || !matrix[i][0]){
                    matrix[i][j] = 0;
                }
            }
            if(c0 == 0) matrix[i][0] = 0;
        }
    }
};