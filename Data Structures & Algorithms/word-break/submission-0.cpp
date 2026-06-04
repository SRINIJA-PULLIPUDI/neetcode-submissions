class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        dp[s.size()] = 1;
        sort(wordDict.begin(),wordDict.end(),comp);
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<wordDict.size();j++){
                if(s.size()-i >= wordDict[j].size()){
                    string sub = s.substr(i,wordDict[j].size());
                    if(sub==wordDict[j]){
                        if(dp[i+wordDict[j].size()]==1) dp[i] = 1;
                    }
                }
                else break;
            }
        }
        return dp[0];
    }
};
