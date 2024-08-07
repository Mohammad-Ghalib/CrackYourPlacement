class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i=0, cnt=0;
        if(n == 0) return false;

        while(s[i] == ' ') i++;

        if(s[i] == '+' || s[i] == '-') i++;

        while(isdigit(s[i])) {
            i++;
            cnt++;
        }

        if(s[i] == '.') i++;

        while(isdigit(s[i])) {
            i++;
            cnt++;
        }

        if(cnt == 0) return false;  

        if(s[i] == 'e' || s[i] == 'E') {
            i++;
            if(s[i] == '+' || s[i] == '-') i++;
            if(!isdigit(s[i])) return false;
            while(isdigit(s[i])) i++;
        }
        
        while(s[i] == ' ') i++;
        
        return s[i] == '\0';
    }
};