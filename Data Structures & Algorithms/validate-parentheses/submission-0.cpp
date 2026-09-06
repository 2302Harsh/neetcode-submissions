class Solution {
public:
    bool isValid(string s) {

        stack<char> seen;

        for(int i=0; i<s.length(); i++ ){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                seen.push(s[i]);
            }
            if(s[i]==')'){
                if(!seen.empty() && seen.top()=='(') seen.pop();
                else return false;
            }
            if(s[i]==']'){
                if(!seen.empty() && seen.top()=='[') seen.pop();
                else return false;
            }
            if(s[i]=='}'){
                if(!seen.empty() && seen.top()=='{') seen.pop();
                else return false;
            }
        }

        return seen.empty();
        
    }
};
