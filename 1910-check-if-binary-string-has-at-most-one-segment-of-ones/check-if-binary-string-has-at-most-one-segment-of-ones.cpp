class Solution {
public:
    bool checkOnesSegment(string s) {
        int count=1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1' && s[i-1]=='0'){
                count++;
            }
            if(count>1){
                return false;
            }
        }
        return true;
    }
};