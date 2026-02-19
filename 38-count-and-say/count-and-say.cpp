class Solution {
public:
    string countAndSay(int n) {
        string ans="";
        if(n==1){
            return "1";
        }

        string str=countAndSay(n-1);
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            int cnt=1;
            while(i<str.size()-1 && str[i]==str[i+1]){
                cnt++;
                i++;
            }
            ans+= to_string(cnt)+string(1,ch);
        }
        return ans;
    }
};