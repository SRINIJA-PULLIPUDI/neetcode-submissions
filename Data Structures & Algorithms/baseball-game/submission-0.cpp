class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                string k = st.top();
                st.pop();
                string l = st.top();
                st.push(k);
                st.push(to_string(stoi(k)+stoi(l)));
            }else if(operations[i]=="C") st.pop();
            else if(operations[i]=="D"){
                string l = st.top();
                string k = to_string(stoi(l)*2);
                st.push(k);
            }else{
                st.push(operations[i]);
            }
        }
        int res=0;
        while(!st.empty()){
            res+=(stoi(st.top()));
            st.pop();
        }
        return res;
    }
};