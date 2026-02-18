class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>find(26,false);
        
        for(char c:sentence){
            find[c-'a']=true;
        }
        for(int i=0;i<26;i++){
            if(!find[i]){
                return false;
            }
        }
        return true;
    }
};