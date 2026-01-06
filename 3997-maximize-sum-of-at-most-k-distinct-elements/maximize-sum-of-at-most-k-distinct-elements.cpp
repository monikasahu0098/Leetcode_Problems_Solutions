class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int>result;
        sort(nums.begin(),nums.end(),greater<int>());

        for(int i=0;i<nums.size();i++){
            if(result.empty() || nums[i] != result.back()){
                result.push_back(nums[i]);
            }
            if(result.size()==k) break;
        }
        return result;
    }
};