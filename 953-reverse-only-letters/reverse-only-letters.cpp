class Solution {
public:
    bool isLetter(char c){
        if((c>='a' && c<='z')||(c>='A' && c<='Z')){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(!isLetter(s[left])){
                left++;
            }else if(!isLetter(s[right])){
                right--;
            }else {
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};