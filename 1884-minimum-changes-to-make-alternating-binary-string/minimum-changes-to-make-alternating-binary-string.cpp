class Solution {
public:
    int minOperations(string s) {
        int start_zero=0;
        int start_one=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='0'){
                    start_one++;
                }else{
                    start_zero++;
                }
            }else{
                if(s[i]=='1'){
                    start_one++;
                }else{
                    start_zero++;
                }
            }
        }
        return min(start_zero,start_one);
    }
};