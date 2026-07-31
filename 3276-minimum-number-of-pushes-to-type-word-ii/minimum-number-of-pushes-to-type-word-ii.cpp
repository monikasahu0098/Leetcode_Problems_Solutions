class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;

        unordered_map<char,int>mp;
        for(char ch:word){
            mp[ch]++;
        }
        vector<int>freq;

        for(auto &it:mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());

        for(int i=0;i<freq.size();i++){
            ans+=(freq[i]*((i/8)+1));
        }
        return ans;
    }
};