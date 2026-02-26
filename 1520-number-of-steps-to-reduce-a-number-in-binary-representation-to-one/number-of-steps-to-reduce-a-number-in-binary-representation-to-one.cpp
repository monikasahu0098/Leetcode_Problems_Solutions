class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int carry=0;

        for(int i=s.length()-1;i>0;i--){
            if((s[i]-'0'+carry)%2==0){
                ans+=1;
            }else{
                ans+=2;
                carry=1;
            }
        }
        return ans+carry;
    }
};