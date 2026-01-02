class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int result;
        int n=nums.size()/2;
        unordered_map<int,int>m;
        for(int num:nums){
            m[num]++;
        }
        for(auto i:m){
            if(i.second==n){
                result= i.first;
            }
        }
        return result;
    }
};