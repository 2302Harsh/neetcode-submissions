class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA =0;

        for(int i=0; i<=heights.size(); i++){
            while(!st.empty() && (i==heights.size() || heights[st.top()]>=heights[i])){
                int h = heights[st.top()];
                st.pop();
                int w;

                if(st.empty()) w = i;
                else w = i-st.top()-1;

                maxA = max(maxA, h*w);
            }

            st.push(i);
        }
        return maxA;
    }
};
