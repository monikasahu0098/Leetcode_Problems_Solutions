class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;

        auto isAlphaNum=[&] (char ch){
            return ((ch>='0' && ch<='9') || (tolower(ch)>='a' && tolower(ch)<='z'));
        };
        while(i<j){
            while(i<j && !isAlphaNum(s[i])) i++;
            while(i<j && !isAlphaNum(s[j])) j--;

            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};