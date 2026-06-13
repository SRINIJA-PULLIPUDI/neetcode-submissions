class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        queue<pair<int,int>> q;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(board[i][board[0].size()-1]=='O'){
                q.push({i,board[0].size()-1});
                vis[i][board[0].size()-1] = 1;
            }
        }for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i] = 1;
            }
            if(board[board.size()-1][i]=='O'){
                q.push({board.size()-1,i});
                vis[board.size()-1][i] = 1;
            }
        }
        while(!q.empty()){
            int indI = q.front().first,indJ = q.front().second;
            q.pop();
            if(indI>0 and vis[indI-1][indJ]==0 and board[indI-1][indJ]=='O'){
                q.push({indI-1,indJ});
                vis[indI-1][indJ]=1;
            }
            if(indI<board.size()-1 and vis[indI+1][indJ]==0 and board[indI+1][indJ]=='O'){
                q.push({indI+1,indJ});
                vis[indI+1][indJ]=1;
            }
            if(indJ>0 and vis[indI][indJ-1]==0 and board[indI][indJ-1]=='O'){
                q.push({indI,indJ-1});
                vis[indI][indJ-1]=1;
            }
            if(indJ<board[0].size()-1 and vis[indI][indJ+1]==0 and board[indI][indJ+1]=='O'){
                q.push({indI,indJ+1});
                vis[indI][indJ+1]=1;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(vis[i][j]==0 and board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
