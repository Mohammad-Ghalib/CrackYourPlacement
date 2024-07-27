class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++){
            bool found = true;
            for(int j=0, k=i; j<needle.size(); j++, k++){
                if(haystack[k] != needle[j]){
                    found = false;
                    break;
                }
            }
            if(found) return i;
        }
        return -1;
    }
};