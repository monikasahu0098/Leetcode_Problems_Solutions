class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        unordered_map<int,int>mp;
        mp[0]=-1;

        int sum=0;
        int len=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                sum--;
            }else{
                sum++;
            }
            if(mp.find(sum) != mp.end()){
                len=max(len,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return len;

    }




};

    // int findMaxLength(vector<int>& nums) {
    //     int n = nums.size();

    //     if (n < 2) {
    //         return 0;
    //     }

    //     int len = 0;

    //     for (int i = 0; i < n - 1; i++) {
    //         int cnt0 = 0;
    //         int cnt1 = 0;

    //         if (nums[i] == 0)
    //             cnt0++;
    //         else
    //             cnt1++;

    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[j] == 0)
    //                 cnt0++;
    //             else
    //                 cnt1++;

    //             if (cnt0 == cnt1) {
    //                 len = max(len, j - i + 1);
    //             }
    //         }
    //     }

    //     return len;
    // }