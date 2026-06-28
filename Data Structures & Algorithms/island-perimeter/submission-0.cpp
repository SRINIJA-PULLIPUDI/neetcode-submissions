class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res=0;
        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int indI = row[k]+i, indJ = j+col[k];
                        if(indI>=0 and indI<grid.size() and indJ>=0 and indJ<grid[0].size()){
                            if(grid[indI][indJ]==0) res++;
                        }else{
                            res++;
                        }
                    }
                }
            }
        }return res;
    }
};