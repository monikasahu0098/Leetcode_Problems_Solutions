class Solution {
public:
    
        // int result;
        // int n=nums.size()/2;
        // unordered_map<int,int>m;
        // for(int num:nums){
        //     m[num]++;
        // }
        // for(auto i:m){
        //     if(i.second==n){
        //         result= i.first;
        //     }
        // }
        // return result;
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};