class Solution {
public:

    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string ans;
        backtrack(n, ans, 0, 0);
        return res;
    }

    void backtrack(int n, string ans, int openB, int closeB){
        if(openB == n && openB == closeB){
            res.push_back(ans);
            return;
        }

        if(openB < n){
            ans += '(';
            backtrack(n, ans, openB+1, closeB);
            ans.pop_back();
        }
        if(closeB< openB){
            ans+=')';
            backtrack(n, ans, openB, closeB+1);
            ans.pop_back();
        }
    }
};
