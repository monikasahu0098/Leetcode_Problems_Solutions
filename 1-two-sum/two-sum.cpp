class Solution {
public:
    
        // vector<int>result;
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             result.push_back(i);
        //             result.push_back(j);
        //         }
        //     }
        // }
        // return result;
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;            //number,index
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            if(mp.count(need)){
                return {i,mp[need]};       // return {currIdx, preIdx};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};