class Solution {
public:

    string solve(int n, string ones[], string tens[], string thousands[]) {
        if (n < 20) 
            return ones[n];
        if (n < 100) 
            return tens[n / 10] + solve(n % 10, ones, tens, thousands);
        if (n < 1000) 
            return solve(n / 100, ones, tens, thousands) + " Hundred" + solve(n % 100, ones, tens, thousands);
        for (int i = 3; i >= 0; i--) {
            if (n >= pow(1000, i)) {
                return solve(n / pow(1000, i), ones, tens, thousands) + thousands[i] + solve(n % (int)pow(1000, i), ones, tens, thousands);
            }
        }
        return "";
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        string thousands[4] = {"", " Thousand", " Million", " Billion"};

        return solve(num, ones, tens, thousands).substr(1);
    }
};