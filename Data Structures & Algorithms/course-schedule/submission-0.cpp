class Solution {
public:
bool dfs(int node, vector<vector<int>>& adj,  vector<int>& vis, vector<int>& path){
    for(int i=0;i<adj[node].size();i++){
        if(!vis[adj[node][i]]){
            vis[adj[node][i]] = 1;
            path[adj[node][i]] = 1;
            bool r = dfs(adj[node][i],adj,vis,path);
            if(r==false) return false;
        }else{
            if(path[adj[node][i]]) return false;
        }
        path[adj[node][i]]=0;
    }return true;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses);
        vector<int> path(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                vis[i]=1;
                path[i]=1;
                bool r = dfs(i,adj,vis,path);
                if(r==false) return false;
                path[i]=0;
            }
        }return true;
    }
};
