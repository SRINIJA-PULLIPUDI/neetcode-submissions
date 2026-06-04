class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max(nums[0]+nums[2],nums[1]);
        vector<int> dp(n);
        dp[0] = nums[0], dp[1] = nums[1],dp[2] = nums[2]+dp[0];
        for(int i=3;i<nums.size();i++){
            dp[i] = max(dp[i-2],dp[i-3]) + nums[i];
        }
        int maxi = dp[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi,dp[i]);
        }return maxi;
    }
};
