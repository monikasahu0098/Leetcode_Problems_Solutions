class Solution {
public:
    bool isBalanced(vector<int>&f){
        int same=0;
        for(int i=0;i<26;i++){
            if(f[i]==0)  continue;
            if(same==0){
                same=f[i];
            }else if(f[i] != same){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            vector<int>f(26,0);
            for(int j=i;j<n;j++){
                f[s[j]-'a']++;

                if(isBalanced(f)){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
        
    }
};