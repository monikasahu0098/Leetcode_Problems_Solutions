class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,char>mp;
        unordered_set<char>st;
        for(int i=0;i<s.size();i++){
            int c1=s[i],c2=t[i];
            if(mp.count(c1)){
                if(mp[c1] != c2) return false;
            }else{
                if(st.count(c2)) return false;
                mp[c1]=c2;
                st.insert(c2);
            }
        }
        return true;
    }
};