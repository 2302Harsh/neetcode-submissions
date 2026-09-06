class Solution {
public:
    string minWindow(string s, string t) {

        if(s.length()<t.length()) return "";

        unordered_map<char,int> hash;
        for(int i=0; i<t.length(); i++){
            hash[t[i]]++;
        }

        int l=0, r=0;
        int minL = INT_MAX;
        int sIndex = -1;
        int c = 0;

        while(r<s.length()){
            if(hash[s[r]]>0) c++;
            hash[s[r]]--;

            while(c == t.length()){
                if(r-l+1< minL){
                    minL = r-l+1;
                    sIndex = l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0) c--;
                l++;
            }
            r++;
        }

        return sIndex== -1 ? "" : s.substr(sIndex,minL);
    }
};
