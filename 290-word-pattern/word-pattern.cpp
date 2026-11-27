class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string>words;

        string word;

        while(ss>>word){
            words.push_back(word);
        }
        if(pattern.size() != words.size()) return false;

        unordered_map<char,string>mp;
        unordered_set<string>st;

        for(int i=0;i<words.size();i++){
            char c=pattern[i];
            string word=words[i];

            if(mp.count(c)){
                if(mp[c] != word) return false;
            }else{
                if(st.count(word)) return false;
                mp[c]=word;
                st.insert(word);

            }

        }
        return true;
    }
};