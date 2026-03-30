class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mapIndex;
        mapIndex[0]=-1;
        int mod;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            mod=sum%k;
            if(mod<0){
                mod+=k;
            }
            if(mapIndex.find(mod) !=mapIndex.end()){
                if(i-mapIndex[mod]>1) return true;
                
            }else{
                mapIndex[mod]=i;
            }
            
        }
        return false;
    }
};