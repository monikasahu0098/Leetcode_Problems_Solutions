class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        int n=nums.size();
        if(n==0){
            return {-1,-1};
        }
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                result.push_back(i);
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                result.push_back(i);
                break;
            }
        }
        if(!result.empty()){
            return result;
        }else{
            return {-1,-1};
        }
    }
};