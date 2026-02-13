class Solution {
public:
    int helper(string &s, char ch1, char ch2){
        int n=s.length();
        unordered_map<int,int>diffMp;
        int maxLen=0;
        int count1=0;
        int count2=0;

        for(int i=0;i<n;i++){
            if(s[i]!=ch1 && s[i]!=ch2){
                diffMp.clear();
                count1=0;
                count2=0;
                continue;
            }
            if(s[i]==ch1){
                count1++;
            }
            if(s[i]==ch2){
                count2++;
            }
            if(count1==count2){
                maxLen=max(maxLen,count1+count2);
            }
            int diff=count1-count2;

            if(diffMp.count(diff)){
                maxLen=max(maxLen,i-diffMp[diff]);
            }else{
                diffMp[diff]=i;
            }
        }
        return maxLen;
    }

    int longestBalanced(string s) {
        int n=s.length();
        int maxLen=0;

        //CASE-I  ("aaaaa")
        int count=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                maxLen=max(maxLen,count);
                count=1;
            }
            
        }
        maxLen=max(maxLen,count);


        //CASE-II ("ababab")
        maxLen=max(maxLen,helper(s,'a','b'));
        maxLen=max(maxLen,helper(s,'a','c'));
        maxLen=max(maxLen,helper(s,'b','c'));


        //CASE-III
        int countA=0;
        int countB=0;
        int countC=0;
        unordered_map<string,int>mp;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                countA++;
            }
            if(s[i]=='b'){
                countB++;
            }
            if(s[i]=='c'){
                countC++;
            }
            if(countA==countB && countA==countC){
                maxLen=max(maxLen, countA+countB+countC);
            }
            int diffAB=countA-countB;
            int diffAC=countA-countC;

            string key=to_string(diffAB)+"_"+to_string(diffAC);

            if(mp.count(key)){
                maxLen=max(maxLen,i-mp[key]);
            }else{
                mp[key]=i;
            }
        }
        return maxLen;
    }


};