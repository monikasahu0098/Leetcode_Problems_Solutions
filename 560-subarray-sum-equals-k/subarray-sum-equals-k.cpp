class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    // int subarraySum(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     unordered_map<int,int>mp;
    //     mp.insert({0,1});
    //     int count=0;
    //     int cumSum=0;
    //     for(int i=0;i<n;i++){
    //         cumSum+=nums[i];
    //         int curr=cumSum-k;
    //         if(mp.find(curr) != mp.end()){
    //             count+=mp[curr];
    //         }
    //         mp[cumSum]++;
    //     }
    //     return count; 
    // }
};