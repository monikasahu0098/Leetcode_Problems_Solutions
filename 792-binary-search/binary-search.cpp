class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int st=0;
    //     int end=nums.size()-1;
    //     while(st<=end){
    //         int mid=st+(end-st)/2;
    //         if(nums[mid]==target){
    //             return mid;
    //         }else if(nums[mid]<target){
    //             st=mid+1;
    //         }else{
    //             end=mid-1;
    //         }
    //     }
    //     return -1;
        
    // }
    int binSearch(vector<int>&arr,int tar,int st,int end){
        if(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]==tar) return mid;
            else if(arr[mid]<tar){ 
                return binSearch(arr,tar,mid+1,end);
            }
            else{
                return binSearch(arr,tar,st,mid-1);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binSearch(nums,target,0,nums.size()-1);
    }
};