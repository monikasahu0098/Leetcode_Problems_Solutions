// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         if(n==0){
//             return 0;
//         }
//         sort(nums.begin(),nums.end());
//         int cur=1;
//         int longest=1;

//         for(int i=1;i<n;i++){
//             if(nums[i]==nums[i-1]){
//                 continue;
//             }else if(nums[i]==nums[i-1]+1){
//                 cur++;
//             }else{
//                 longest=max(longest,cur);
//                 cur=1;
//             }
//         }
//         return max(longest,cur);
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;

        for(int i:s){
            if(s.find(i-1) == s.end()){
                int curNum=i;
                int curLen=1;

                while(s.find(curNum+1) != s.end()){
                    curNum++;
                    curLen++;
                }

                longest=max(longest,curLen);
            }
        }
        return longest;
        
    }
};
