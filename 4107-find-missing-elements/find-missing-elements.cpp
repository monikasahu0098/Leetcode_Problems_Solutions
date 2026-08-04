class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            int gap=nums[i]-nums[i-1];
            if(gap>1){
                for(int j=1;j<gap;j++){
                    ans.push_back(nums[i-1]+j);
                }
            }
        }
        return ans;
    }
};