class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool isDuplicate=false; 
        sort(nums.begin(),nums.end());           //4
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                isDuplicate=true;
                break;
            }
        }
        return isDuplicate;
    }
};