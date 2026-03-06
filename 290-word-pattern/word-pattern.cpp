class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string>words;
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        if(pattern.size() != words.size()){
            return false;
        }
        unordered_map<char,string>mp;
        unordered_set<string>st;

        for(int i=0;i<pattern.size();i++){
            char p=pattern[i];
            string w=words[i];

            if(mp.count(p)){
                if(mp[p] != w){
                    return false;
                }
            }else{
                if(st.count(w)) return false;
                mp[p]=w;
                st.insert(w);
            }
        }
        return true;
    }
};