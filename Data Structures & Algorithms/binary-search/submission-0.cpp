class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=-1,r=nums.size();
        while((r-l)>1){
            int mid = (l+r)/2;
            if(nums[mid]<=target) l=mid;
            else r=mid;
        }
        // cout<<l<<" "<<r<<endl;
        if(l==-1 and nums[r]==target) return r;
        if(l==-1) return -1;
        if(r==nums.size() and nums[l]==target) return l; 
        if(r==nums.size()) return -1;
        if(nums[l]==target) return l;
        return -1;
    }
};
