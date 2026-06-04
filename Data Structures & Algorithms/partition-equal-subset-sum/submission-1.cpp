class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }if(sum%2) return false;
        unordered_set<int> s = {0};
        for(int i=nums.size()-1;i>=0;i--){
            for(auto j:s){
                if(j+nums[i]<(sum/2)) s.insert(j+nums[i]);
                else if(j+nums[i]==(sum/2)) return true;
            }
        }
        for(auto i:s){
            cout<<i<<" ";
        }
        if(s.contains(sum/2)) return true;
        return false;
    }
};
