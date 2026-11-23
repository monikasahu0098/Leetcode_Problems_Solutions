class Solution {
public:
    int findLeftIdx(vector<int>&nums,int target,int n){
        int leftMost=-1;
        int st=0;
        int end=n-1;

        while(st<=end){
            int mid=st+(end-st)/2;

            if(target==nums[mid]){
                leftMost=mid;
                end=mid-1;
            }else if(target>nums[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return leftMost;
    }
    int findRightIdx(vector<int>&nums,int target,int n){
        int rightMost=-1;
        int st=0;
        int end=n-1;

        while(st<=end){
            int mid=st+(end-st)/2;

            if(target==nums[mid]){
                rightMost=mid;
                st=mid+1;
            }else if(target>nums[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int leftMost=findLeftIdx(nums,target,n);
        int rightMost=findRightIdx(nums,target,n);

        return {leftMost,rightMost};
    }
};



// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int>result;
//         int n=nums.size();
//         if(n==0) return {-1,-1};
//         for(int i=0;i<n;i++){
//             if(nums[i]==target){
//                 result.push_back(i);
//                 break;
//             }
//         }
//         for(int i=n-1;i>=0;i--){
//             if(nums[i]==target){
//                 result.push_back(i);
//                 break;
//             }
//         }
//         if(!result.empty()){
//             return result;
//         }else{
//             return {-1,-1};
//         }
//     }
// };