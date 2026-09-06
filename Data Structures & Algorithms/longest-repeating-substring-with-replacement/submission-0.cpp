class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);

        int maxf = 0;
        int maxl = 0;
        int left = 0, right=0;

        while(right<s.length()){
            freq[s[right]-'A']++;

            maxf = max(maxf,freq[s[right]-'A']);

            while((right-left+1)-maxf > k){
                freq[s[left]-'A']--;
                left++;
            }

            maxl = max(maxl,(right-left+1));
            right++;
        }

        return maxl;
    }
};
