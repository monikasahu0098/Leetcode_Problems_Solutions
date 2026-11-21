class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();

        vector<int>prefix;
        prefix=nums;
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        int i=0;
        int j=0;
        int len=1e9;

        int curr=0;
        while(j<n){
            curr=(i==0)? prefix[j] : prefix[j]-prefix[i-1];

            if(curr>=target){
                len=min(len,j-i+1);
                i++;
            }else{
                j++;
            }
        }
        return (len==1e9)? 0 : len;
    }

};