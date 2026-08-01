class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n%2==0){
            return true;
        }
        vector<int>vec(nums);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                vec[j]=max(nums[i]-vec[j],nums[j]-vec[j-1]);
            }
        }
        return vec[n-1]>=0;
    }
};