class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int l=0;
        int r=n-1;

        while(l<r){
            int mid=l+(r-l)/2;

            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return nums[r];
    }
};



// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int mini=1e9;
//         for(int i=0;i<nums.size();i++){
//             mini=min(mini,nums[i]);
//         }
//         return mini;
//     }
// };