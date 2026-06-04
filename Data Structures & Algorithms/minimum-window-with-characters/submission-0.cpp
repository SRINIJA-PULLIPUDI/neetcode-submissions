class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        unordered_map<char,int> mp2;
        int i=0,j=0,c=0,start=0,end=0;
        int mini = INT_MAX;
        while(j<s.size()){
            mp2[s[j]]++;
            if(mp.count(s[j]) and mp[s[j]] == mp2[s[j]]){
                c++;
            }
            while(c==mp.size()){
                if((j-i+1)<mini){
                    cout<<j<<" "<<i<<endl;
                    mini = (j-i+1);
                    start = i;
                    end = j;
                }
                mp2[s[i]]--;
                if(mp.count(s[i]) and mp2[s[i]]<mp[s[i]]){
                    c--;
                }
                i++;
            }
            j++;
        }
        string res="";
        if(mini==INT_MAX) return "";
        for(int i=start;i<=end;i++){
            res+=s[i];
        }
        return res;
    }
};
