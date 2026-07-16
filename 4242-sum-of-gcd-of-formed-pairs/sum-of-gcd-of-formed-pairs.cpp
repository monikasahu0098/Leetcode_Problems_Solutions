class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        long long result=0;
        int max=0;

        for(int &x:nums){
            max=::max(max,x);
            x=__gcd(max,x);
        }


        ranges::sort(nums);
        for(int i=0, j=nums.size()-1;i<j;i++, j--){
            result+=__gcd(nums[i],nums[j]);
        }
        return result;
    }
};