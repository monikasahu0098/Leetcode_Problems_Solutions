class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        string result="";
        int carry=0;
        while(i>=0 || j>=0){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            carry=(sum>1)? 1:0;

            if(sum%2==0){
                result+=to_string(0);
            }else{
                result+=to_string(1);
            }
        }
        if(carry){
            result+=to_string(carry);
        }

        reverse(result.begin(),result.end());
        return result;
    }
};