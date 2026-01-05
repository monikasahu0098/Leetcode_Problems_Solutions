class Solution {
public:
    // bool isPalindrome(string s){
    //     string str=s;
    //     reverse(s.begin(),s.end());

    //     return(s==str);
    // }

    // string ans="";
    //     int n=s.length();
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             string sub=s.substr(i,j-i+1);

    //             if(isPalindrome(sub) && sub.length()>ans.length()){
    //                 ans=s.substr(i,j-i+1);
    //             }
    //         }
    //     }
    //     return ans;

    bool solve(string &s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]){
            return solve(s,i+1,j-1);
        }
        return false;
    }
    string longestPalindrome(string s){
        int n=s.length();
        int maxLen=INT_MIN;
        int sp=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};