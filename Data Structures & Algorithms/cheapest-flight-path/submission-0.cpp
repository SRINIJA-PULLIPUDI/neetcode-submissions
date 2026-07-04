class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int wt = q.front().second.second;
            q.pop();
            if(stops==(k+1)) continue;
            for(int i=0;i<adj[node].size();i++){
                if(dist[adj[node][i].first] > wt + adj[node][i].second){
                    dist[adj[node][i].first] = wt + adj[node][i].second;
                    q.push({stops+1, {adj[node][i].first, dist[adj[node][i].first]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
