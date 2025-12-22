class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26]={0};
        for(char& ch:s){
            count[ch-'a']++;
        }
        for(char &ch:t){
            count[ch-'a']--;
            if(count[ch-'a']<0){
                return ch;
            }
        }
        return ' ';
    }
};