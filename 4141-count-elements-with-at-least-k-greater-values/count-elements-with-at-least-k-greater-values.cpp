class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            return n;
        }
        int ans=0;

        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            int val=nums[i];
            int j=i;
            while(j<n && nums[j]==val){
                j++;
            }
            int freq=j-i;
            int greater=n-j;
            if(greater>=k){
                ans+=freq;
            }
            i=j;
        }
        return ans;

    }
};