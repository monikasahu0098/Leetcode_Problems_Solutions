class Solution {
public:
    bool isVowel(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' ||ch=='o' ||ch=='u'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        string s1=s.substr(0,n/2);
        string s2=s.substr(n/2,n/2);

        int count1=0;
        int count2=0;
        for(char ch:s1){
            char c=tolower(ch);
            if(isVowel(c)){
                count1++;
            }
        }
        for(char ch:s2){
            char c=tolower(ch);
            if(isVowel(c)){
                count2++;
            }
        }
        return (count1==count2);

    }
};