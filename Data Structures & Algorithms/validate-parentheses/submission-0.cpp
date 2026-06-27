class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' or s[i]==']' or s[i]=='}') {
                if(st.empty()) return false;
                if(s[i]==')' and st.top()!='(') return false;
                if(s[i]=='}' and st.top()!='{') return false;
                if(s[i]==']' and st.top()!='[') return false;
                st.pop();
            }else st.push(s[i]);
        }
        if(st.empty()) return true;
        return false;
    }
};
