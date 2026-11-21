class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        double result=INT_MIN;

        int i=0;
        int j=k-1;
        while(j<n){
            double sum=(i==0)? nums[j] : nums[j]-nums[i-1];

            result=max(result,sum/k);
            i++;
            j++;
        }
        return result;

    }
};