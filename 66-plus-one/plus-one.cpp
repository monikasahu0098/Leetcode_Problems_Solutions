class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=0;
        int sum;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                sum=digits[i]+1;
            }else{
                sum=digits[i]+carry;
            }
            
            if(sum>9){
                sum=sum%10;
                carry=1;
            }else{
                carry=0;
            }
            ans.push_back(sum);
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};