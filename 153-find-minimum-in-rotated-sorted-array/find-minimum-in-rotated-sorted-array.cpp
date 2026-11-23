class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=1e9;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
        }
        return mini;
    }
};