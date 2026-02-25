class Solution {
public:
    bool allCapital(string &s){
        for(char ch:s){
            if(ch<'A' || ch>'Z'){
                return false;
            }
        }
        return true;
    }
    bool allSmall(string &s){
        for(char ch:s){
            if(ch<'a' || ch>'z'){
                return false;
            } 
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        string substr=word.substr(1);
        if(allCapital(word) || allSmall(word) || allSmall(substr)){
            return true;
        }
        return false;
    }
};