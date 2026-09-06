class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxC = 0;
        int count = 0; 
        unordered_set<char> seen;

        for( int i=0; i<s.length(); i++){
            while(seen.find(s[i]) != seen.end()){
                seen.erase(s[count]);
                count ++;
            }
            seen.insert(s[i]);
            maxC = max(maxC, i-count+1);
        }

        return maxC;
        
    }
};
