class Solution {
public:
    bool scoreBalance(string s) {
        int score[26]={0};
        for(char ch='a'; ch<='z';ch++){
            score[ch-'a']=(ch-'a')+1;
        }
        int sum=0;
        for(char ch:s){
            sum+=score[ch-'a'];
        }
        if(sum%2 != 0) return false;

        int prefixSum=0;
        for(int i=0;i<s.length()-1;i++){
            prefixSum+=score[s[i]-'a'];

            if(prefixSum==(sum/2)){
                return true;
            }
        }
        return false;
    }
};