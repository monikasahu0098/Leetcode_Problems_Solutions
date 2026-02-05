class Solution {
public:
    // vector<int> constructTransformedArray(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>result(n,0);
    //     for(int i=0;i<n;i++){
    //         if(nums[i]>0){
    //             int right=nums[i]%n;
    //             result[i]=nums[(i+right)%n];
    //         }else if(nums[i]<0){
    //             int left=abs(nums[i]%n);
    //             result[i]=nums[(i-left+n)%n];
    //         }else{
    //             result[i]=nums[i];
    //         }
    //     }
    //     return result;
    // }
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            int shift=nums[i]%n;
            int newIdx=(i+shift)%n;
            if(newIdx<0){
                newIdx=(newIdx+n)%n;
            }
            result[i]=nums[newIdx];
        }
        return result;
    }
};