class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res={""};
        vector<string> digitToString = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};

        for(char digit: digits){
            vector<string> temp;
            for(string curStr: res){
                for(char c: digitToString[digit - '0']){
                    temp.push_back(curStr+c);
                }
            }
            res = temp;
        }
        return res;
    }
};
