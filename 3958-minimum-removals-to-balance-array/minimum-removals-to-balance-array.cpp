class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int l=0;
        int maxSize=1;

        for(int r=0;r<n;r++){
            while((long long)nums[r]>(long long)nums[l]*k){
                l++;
            }
            maxSize=max(maxSize,r-l+1);
        }
       
        return n-maxSize;
    }
};