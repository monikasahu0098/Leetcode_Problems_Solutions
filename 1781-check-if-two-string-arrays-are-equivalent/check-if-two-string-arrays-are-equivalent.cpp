class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1="";
        for(string str:word1){
            ans1+=str;
        }
        string ans2="";
        for(string str:word2){
            ans2+=str;
        }
        return ans1==ans2;
    }
};