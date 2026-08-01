class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res=0, i=0, j=n-1,lm=height[0], rm=height[n-1];
        while(i<=j){
            if(lm<rm){
                if((lm-height[i])>0){
                    res+=(lm-height[i]);
                }
                lm = max(lm,height[i]);
                i++;
            }else{
                if(rm-height[j]>0){
                    res+=(rm-height[j]);
                }
                rm = max(rm,height[j]);
                j--;
            }
        }
        return res;
    }
};
