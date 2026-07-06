class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(int i=0;i<adj[node].size();i++){
                if(wt+adj[node][i].second < dist[adj[node][i].first]){
                    dist[adj[node][i].first] = wt+adj[node][i].second;
                    pq.push({dist[adj[node][i].first], adj[node][i].first});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
