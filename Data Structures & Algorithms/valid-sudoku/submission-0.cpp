class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(10,0));
        vector<vector<int>> col(9,vector<int>(10,0));
        vector<vector<int>> grid(9,vector<int>(10,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]>='0' and board[i][j]<='9') {
                    int s = (i/3)*3 + (j/3);
                    row[i][(board[i][j]-'0')] = row[i][(board[i][j]-'0')]+=1;
                    col[j][(board[i][j]-'0')] = col[j][(board[i][j]-'0')]+=1;
                    grid[s][(board[i][j]-'0')] = grid[s][(board[i][j]-'0')]+=1;
                    
                    if(row[i][(board[i][j]-'0')]>1 or col[j][(board[i][j]-'0')]>1 or grid[s][(board[i][j]-'0')]>1) return false;
                }   
            }
        }
        return true;
    }
};
