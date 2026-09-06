class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<string>> dp(s.size()+1,vector<string>(s.size()+1));

        for(int i=0; i<=s.size(); i++) dp[i][0] = "";
        for(int j=0; j<=s.size(); j++) dp[0][j] = "";

        string s2 = s;
        reverse(s2.begin(), s2.end());

        int len = 0;
        string str = "";

        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=s.size(); j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + s[i-1];
                    if(len < dp[i][j].size()){
                        int original_start_index = i - dp[i][j].size();
                        int reversed_end_index = s.size() - j;
                        if (original_start_index == reversed_end_index) {
                            len = dp[i][j].size();
                            str = dp[i][j];
                        }
                    }
                }
                else{
                    dp[i][j] = "";
                }
            }
        }

        if (str == "" && s.size() > 0) return s.substr(0, 1);
        return str;
    }
};
