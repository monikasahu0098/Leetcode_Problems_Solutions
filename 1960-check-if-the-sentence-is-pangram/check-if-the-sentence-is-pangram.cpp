class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>find(26,0);
        
        for(char c:sentence){
            find[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(find[i]==0){
                return false;
            }
        }
        return true;
    }
};