class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int area = 0;
        while(i<j){
            int x = (j-i)*min(height[i],height[j]);
            area = max(x, area);
            if(height[i]<=height[j]){
                i++;
            }else j--;
        }
        return area;
    }
};
