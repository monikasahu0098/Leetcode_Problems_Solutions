class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int n= nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }else if(nums[i]+nums[j]<target){
                i++;
            }else if(nums[i]+nums[j]>target){
                j--;
            }
        }
        return result;
    }
};