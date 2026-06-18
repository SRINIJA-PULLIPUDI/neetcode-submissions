class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==0) c++;
            }
        }
        if(c==grid.size()*grid[0].size()) return 0;
        int res=-1;
        while(!q.empty()){
            res++;
            int k=q.size();
            for(int l=0;l<k;l++){
                int i=q.front().first, j=q.front().second;
                q.pop();
                if(i>0 and grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j] = 2;
                }if(i<grid.size()-1 and grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j] = 2;
                }if(j>0 and grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1] = 2;
                }if(j<grid[0].size()-1 and grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1] = 2;
                }
            }
        }for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return res;
    }
};
