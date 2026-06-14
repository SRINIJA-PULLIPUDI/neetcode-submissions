class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    res++;
                    vis[i][j] = 1;
                    q.push({i,j});
                }
                while(!q.empty()){
                    int l=q.front().first, r = q.front().second;
                    q.pop();
                    if(l>0 and grid[l-1][r]=='1' and !vis[l-1][r]){
                        vis[l-1][r] = 1;
                        q.push({l-1,r});
                    }if(l<grid.size()-1 and grid[l+1][r]=='1' and !vis[l+1][r]){
                        vis[l+1][r] = 1;
                        q.push({l+1,r});
                    }if(r>0 and grid[l][r-1]=='1' and !vis[l][r-1]){
                        vis[l][r-1] = 1;
                        q.push({l,r-1});
                    }if(r<grid[0].size()-1 and grid[l][r+1]=='1' and !vis[l][r+1]){
                        vis[l][r+1] = 1;
                        q.push({l,r+1});
                    }
                }
            }
        }return res;
    }
};
