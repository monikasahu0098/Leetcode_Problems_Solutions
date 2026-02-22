class Solution {
public:
    string makeGood(string s) {
        string ans="";

        for(int i=0;i<s.length();i++){
            if(!ans.empty() && (ans.back()+32==s[i] || ans.back()-32==s[i])){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};