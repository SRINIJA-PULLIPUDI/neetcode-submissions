class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return 0;
        set<string> st;
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }
        while(!q.empty()){
            string s = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++){
                string k = s;
                for(int j=0;j<26;j++){
                    if(('a'+j)!=k[i]) k[i] = 'a'+j;
                    if(k==endWord) return dist+2;
                    if(st.find(k)!=st.end()) {
                        q.push({k,dist+1});
                        st.erase(k);
                    }
                }
            }
        }
        return 0;
    }
};
