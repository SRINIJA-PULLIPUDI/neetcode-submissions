class Solution {
public:
    int robb(vector<int> nums,int i,int n){
        int rob1=0,rob2=0;
        for(int j=i;j<n;j++){
            int temp = max(rob1+nums[j],rob2);
            rob1 = rob2;
            rob2=temp;
        }return rob2;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        return max(robb(nums,0,nums.size()-1),robb(nums,1,nums.size()));
    }
};
