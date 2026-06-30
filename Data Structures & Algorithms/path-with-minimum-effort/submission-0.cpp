class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};
        while(!pq.empty()){
            int diff = pq.top().first;
            int i = pq.top().second.first,j = pq.top().second.second;
            pq.pop();
            if(i==(heights.size()-1) and j==(heights[0].size()-1)) return diff;
            for(int k=0;k<4;k++){
                int indI = i+row[k], indJ = j+col[k];
                if(indI>=0 and indI<heights.size() and indJ>=0 and indJ<heights[0].size() and
                abs(heights[i][j]-heights[indI][indJ]) < dist[indI][indJ]){
                    int curdiff = abs(heights[i][j]-heights[indI][indJ]);
                    dist[indI][indJ] = abs(heights[i][j]-heights[indI][indJ]);
                    pq.push({max(curdiff, diff), {indI,indJ}});
                }
            }
        }
        return 1;
    }
};