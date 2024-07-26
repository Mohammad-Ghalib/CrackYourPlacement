class Solution {
public:
    string addBinary(string a, string b) {

        int i=a.size()-1, j=b.size()-1, c=0, sum;
        string ans;
        
        while(i>=0 || j>=0 || c>0){
            sum = 0;
            sum += i>=0? a[i]-'0': 0;
            sum += j>=0? b[j]-'0': 0;
            sum += c;
            if(sum == 0){
                ans += '0';
                c = 0;
            }
            else if(sum == 1){ 
                ans += '1';
                c = 0;
            }
            else if(sum==2){
                ans += '0';
                c = 1;
            }
            else{
                ans += '1';
                c = 1;
            }
            i--, j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};