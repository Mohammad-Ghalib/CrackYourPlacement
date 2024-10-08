class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        int top=0, down=n-1;
        
        while(top < down){
            if(M[top][down]) top++;
            else if(M[down][top]) down--;
            else{
                top++;
                down--;
            }
        }
        
        if(top > down) return -1;
        
        for(int i=0; i<n; i++){
            if(i==top) continue;
            if(!M[i][top] || M[top][i]) return -1; 
        }
        
        return top;
    }
};