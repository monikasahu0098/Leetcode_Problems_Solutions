class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size()==0){
            return "";
        }
        string ans="";
        vector<string>specials;
        int st=0;
        int sum=0;
        for(int i=0;i<s.length();i++){
            sum+= (s[i]=='1')? +1 :-1;
            if(sum==0){
                string inner=s.substr(st+1,i-st-1);
                specials.push_back("1"+makeLargestSpecial(inner)+"0");
                st=i+1;
            }
        }
        sort(specials.begin(),specials.end(),greater<string>());
        for(string &str:specials){
            ans+=str;
        }
        return ans;

    }
};