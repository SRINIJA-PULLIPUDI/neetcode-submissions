class Solution {
public:
    void permutations(int i, vector<int> nums, int n, vector<vector<int>>& res){
        if(i==n){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i], nums[j]);
            permutations(i+1, nums, n, res);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permutations(0, nums, nums.size(), res);
        return res;
    }
};
