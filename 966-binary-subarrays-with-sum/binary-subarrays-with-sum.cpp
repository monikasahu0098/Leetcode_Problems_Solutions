class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;

        for(int i=0;i<n;i++){
            sum +=nums[i];
            int need=sum-goal;

            if(mp.find(need) != mp.end()){
                cnt+=mp[need];
            }
            mp[sum]++;
        }
        return cnt;
    }
};