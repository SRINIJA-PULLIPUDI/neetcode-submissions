class Solution {
public:
set<vector<string>> res;
    bool check(vector<vector<int>>& queen, int n, int row, int col){
        for(int i=0;i<n;i++){
            if(queen[row][i]) return false;
            if(queen[i][col]) return false;
        }
        if(col>=row){
            int k=0;
            for(int i=(col-row);i<n;i++){
                if(queen[k++][i]) return false;
            }
        }else{
            int k=0;
            for(int i= (row-col);i<n;i++){
                if(queen[i][k++]) return false;
            }
        }
        if((row+col)<= (n-1)){
            int k = 0;
            for(int i=row+col;i>=0;i--){
                if(queen[k++][i]) return false;
            }
        }else{
            int k = n-1;
            for(int i=(row+col-n+1);i<n;i++){
                if(queen[i][k--]) return false;
            }
        }
        return true;
    }
    void solve(vector<vector<int>> queen, int n, int col, int row, int idx){
        if(idx==col) {
            solve(queen, n, col+1, row, idx);
        }
        if(col == n){
            vector<string> k;
            for(int i=0;i<n;i++){
                string s = "";
                for(int j=0;j<n;j++){
                    if(queen[i][j]) s+='Q';
                    else s+='.';
                }
                k.push_back(s);
            }
            res.insert(k);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(queen, n, i, col)){
                queen[i][col] = 1;
                solve(queen, n, col+1, 0, idx);
                queen[i][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> queen(n,vector<int> (n));
        for(int i=0;i<n;i++){
            queen[0][i] = 1;
            solve(queen,n,0,0,i);
            queen[0][i] = 0;
        }
        return res.size();
    }
};