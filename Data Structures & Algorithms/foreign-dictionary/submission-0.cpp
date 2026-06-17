class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,set<char>> mp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                 mp[words[i][j]] = {};
            }
        }
        for(int i=0;i<words.size()-1;i++){
            for(int j=0;j<words[i].size();j++){
                if(j<words[i+1].size()){
                    if(words[i][j]!=words[i+1][j]) {
                        
                        mp[words[i][j]].insert(words[i+1][j]);
                        break;
                    }
                }else if(j>=words[i+1].size()) return "";
            }
        }
        unordered_map<char,int> indegree;
        for(auto i:mp){
            indegree[i.first] = 0;
        }
        for(auto i:mp){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        queue<char> q;
        for(auto i:indegree){
            if(i.second==0) {
                q.push(i.first);
                indegree[i.first]--;
            }
        }
        string res="";
        while(!q.empty()){
            char node = q.front();
            q.pop();
            res+=node;
            for(auto i:mp[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    indegree.erase(i);
                } 
            }
        }if(res.size()!=mp.size()) return "";
        return res;
    }
};
