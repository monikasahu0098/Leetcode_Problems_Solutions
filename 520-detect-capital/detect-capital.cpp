class Solution {
public:
    bool check(string &s, char st, char end){
        for(char ch:s){
            if(ch<st || ch>end){
                return false;
            }
        }
        return true;
    }

    
    bool detectCapitalUse(string word) {
        string substr=word.substr(1);
        if(check(word,'A','Z') || check(word,'a','z') || check(substr,'a','z')){
            return true;
        }
        return false;
    }
};