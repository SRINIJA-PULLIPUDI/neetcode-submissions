class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max({nums[0],nums[1],nums[0]*nums[1]});
        int mini = min(nums[1],nums[1]*nums[0]);
        int maxi = max(nums[1],nums[0]*nums[1]);
        int res = max(mini,maxi);
        // cout<<mini<<endl<<maxi<<endl<<mini<<endl;
        for(int i=2;i<nums.size();i++){
            if(nums[i]==0){
                mini = 1,maxi=1;
            }else{
                int temp = mini;
                mini = min({mini*nums[i],maxi*nums[i],nums[i]});
                maxi = max({maxi*nums[i],temp*nums[i],nums[i]});
            }
            res = max({res,mini,maxi});
            // cout<<nums[i]<<" "<<mini<<" "<<maxi<<" "<<res<<endl;
        }
        return res;
    }
};
