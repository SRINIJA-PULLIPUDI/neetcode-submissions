class Solution {
public:
    bool checkValidString(string s) {
        if(s[0]==')') return false;
        stack<int> stars;
        stack<pair<char,int>> braces;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') braces.push({'(',i});
            else if(s[i]==')'){
                if(!braces.empty()) braces.pop();
                else if(!stars.empty()){
                    if(stars.top()<i) stars.pop();
                    else return false;
                }else return false;
            }else if(s[i]=='*') stars.push(i);
        }
        if(braces.empty()) return true;
        while(!braces.empty()){
            if(stars.empty()) return false;
            if(stars.top()>(braces.top().second)){
                stars.pop();
                braces.pop();
            }else return false;
        }
        return true;
    }
};
