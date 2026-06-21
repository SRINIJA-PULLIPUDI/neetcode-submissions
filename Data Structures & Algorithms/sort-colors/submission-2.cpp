class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,k=nums.size()-1;
        for(int j=0;j<nums.size();j++){
            if(j>k) break;
            // if(i==j) continue;
            if(nums[j]!=1) {
                if(nums[j]==0){
                    swap(nums[i],nums[j]);
                    i++;
                }else{
                    swap(nums[j],nums[k]);
                    j--;
                    k--;
                }
            }
            // if(nums[j]!=1){
            //     if(nums[j]==0){
            //         swap(nums[i],nums[j]);
            //         i++;
            //     }else{
            //         swap(nums[j],nums[k]);
            //         k--;
            //     }
            // }
        }
    }
};