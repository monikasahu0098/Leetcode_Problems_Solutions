class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        for(int i=0;i<n;i++){
            int j=i;
            while(j+1<n && nums[j] != nums[j+1]){
                j++;
            }
            long long size=j-i+1;
            result+=size*(size+1)/2;

            i=j;
        }
        return result;

    }
};