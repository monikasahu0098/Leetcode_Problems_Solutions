class Solution {
public:
    string generate(string &word){
        int arr[26]={0};
        for(char &ch:word){
            arr[ch-'a']++;
        }
        string newString="";
        for(int i=0;i<26;i++){
            int freq=arr[i];

            if(freq>0){
                newString+=string(freq,i+'a');
            }
        }
        return newString;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       /* vector<vector<string>> result;
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string temp=s;
            sort(begin(temp),end(temp));

            mp[temp].push_back(s);
        }
        for(auto &it:mp){
            result.push_back(it.second);
        }
        return result;
        */

        vector<vector<string>>result;
        int n=strs.size();

        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string word=s;
            string newWord=generate(word);
            mp[newWord].push_back(word);
        }
        for(auto &it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};