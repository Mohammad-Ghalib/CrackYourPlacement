class Solution {
public:
    bool validPalindrome(string s) {
        for(int i=0, j=s.size()-1; i<j; i++, j--){
            if(s[i] != s[j]){
                int i2=i+1, j2=j-1;
                while(i2<j && s[i2] == s[j]){
                    i2++; 
                    j--;
                }

                while(i<j2 && s[i] == s[j2]){
                    i++;
                    j2--;
                }

                return (i2>=j) || (i>=j2);
            }
        }
        return true;
    }
};