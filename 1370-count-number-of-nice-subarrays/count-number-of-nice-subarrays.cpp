class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;

        int oddCnt=0;

        int ans=0;
        for(int i=0;i<n;i++){
            oddCnt+= (nums[i]%2);
            int prev=oddCnt-k;

            if(mp.find(prev) != mp.end()){
                ans+= mp[prev];
            }
            mp[oddCnt]++;
        }
        return ans;
    }
};