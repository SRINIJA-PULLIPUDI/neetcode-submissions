class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<int> dp(s.size()+1,0);
        dp[s.size()] = 1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0') dp[i] = 0;
            else{
                dp[i] = dp[i+1];
                if(i!=s.size()-1){
                    if(s[i]=='1' or (s[i]=='2' and s[i+1]<='6')) dp[i]+=dp[i+2];
                }
            }
        }return dp[0];
    }
};
