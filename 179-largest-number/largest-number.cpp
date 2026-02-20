class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        string ans="";
        sort(nums.begin(),nums.end(),[](int& a,int& b){
            string s1=to_string(a);
            string s2=to_string(b);
            if(s1+s2>s2+s1){
                return true;
            }else{
                return false;
            }
        });
        if(nums[0]==0){
            return "0";
        }
        for(int &num:nums){
            ans+=to_string(num);
        }

        return ans; 
    }
};