class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n=s.size();
        vector<int>lastIdx(26,0);
        vector<bool>seen(26,false);

        for(int i=0;i<n;i++){
            char ch=s[i];
            lastIdx[ch-'a']=i;
        }
        for(int i=0;i<n;i++){
            char c=s[i];
            int index=c-'a';
            
            if(seen[index]==true){
                continue;
            }
            while(ans.size()>0 && ans.back()>c && lastIdx[ans.back()-'a']>i){
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(c);
            seen[index]=true;
        }
        return ans;
    }
};