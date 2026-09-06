class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> farestPoint;
        for(int i =0; i<s.size(); i++){
            farestPoint[s[i]] = i;
        }

        vector<int> res;
        int size =0, end =0;

        for(int i =0; i<s.size(); i++){
            end = max(end,farestPoint[s[i]]);
            size++;

            if( i == end){
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};
