class Solution {
public:
    string multiply(string num1, string num2) {

        long i = stol(num1);
        long y = stol(num2);

        if(i ==0 || y == 0) return "0";

        
        string ans = to_string(i*y);
        return ans;
    }
};
