class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int n=s.size();
        int prevCnt=0;
        int currCnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                currCnt++;
            }else{
                ans+=min(currCnt,prevCnt);
                prevCnt=currCnt;
                currCnt=1;
            }
        }
        return ans+min(currCnt,prevCnt);
    }
};