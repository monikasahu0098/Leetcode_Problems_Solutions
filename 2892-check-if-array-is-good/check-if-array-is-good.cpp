class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        if(nums.size() != n+1){
            return false;
        }
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
        }
        if(freq[n] != 2){
            return false;
        }

        for(int i=1;i<n;i++){
            if(freq[i] != 1){
                return false;
            }
        }
        return true;

    }
};