class Solution {
public:
    bool isPalindrome(string s) {
        string r = "";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' and s[i]<='z') r+=s[i];
            else if(s[i]>='A' and s[i]<='Z') r+=(s[i]+32);
            else if(s[i]>='0' and s[i]<='9') r+=s[i];
        }
        s = r;
        reverse(s.begin(),s.end());
        if(s==r) return true;
        return false;
    }
};
