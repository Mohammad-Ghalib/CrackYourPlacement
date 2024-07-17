class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size(), c=0;
        int sc = 0, ec = m-1, sr = 0, er = n-1;
        vector<int> ans;
        
        
        while((sc<=ec) && (sr<=er)){
            if(c%4 == 0){
                int k = sc;
                for(; sc<=ec; sc++){
                    ans.push_back(matrix[sr][sc]);
                }
                
                sc = k;
                sr++;
            }
            else if(c%4 == 1){
                int k = sr;
                for(; sr<=er; sr++){
                    ans.push_back(matrix[sr][ec]);
                }
                
                sr = k;
                ec--;
            }
            else if(c%4 == 2){
                int k = ec;
                for(; ec>=sc; ec--){
                    ans.push_back(matrix[er][ec]);
                }
                ec = k;
                er--;
            }
            else{
                int k = er;
                for(; er>=sr; er--){
                    ans.push_back(matrix[er][sc]);
                }
                er = k;
                sc++;
            }
            
            c++;
            
        }
        
        return ans;
             
    }
};