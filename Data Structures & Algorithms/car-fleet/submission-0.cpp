class Solution {
public:
static bool comp(pair<int,int>& a, pair<int,int>& b){
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<speed.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),comp);
        stack<double> st;
        for(int i=0;i<v.size();i++){
            double speed = (target-v[i].first)/(v[i].second*1.0);
            if(st.empty()) st.push(speed);
            else{
                if(speed>st.top()) st.push(speed);
            }
        }
        return st.size();
    }
};
