class Solution {
public:
    int hammingWeight(int n) {
        string bin="";
        while(n>0){
            int rem=n%2;
            bin=to_string(rem)+bin;
            n=n/2;
        }
        int ans=0;
        for(char ch:bin){
            if(ch=='1'){
                ans++;
            }
        }
        return ans;
    }
};