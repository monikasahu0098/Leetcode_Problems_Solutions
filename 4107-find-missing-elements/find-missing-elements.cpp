class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>result;
        for(int i=1;i<nums.size();i++){
            int gap=nums[i]-nums[i-1];
            if(gap>1){
                for(int j=1;j<gap;j++){
                    result.push_back(nums[i-1]+j);
                }
            }
        }
        return result;
    }
};