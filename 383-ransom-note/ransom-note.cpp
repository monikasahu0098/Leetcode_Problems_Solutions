class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26]={0};
        for(char &ch:magazine){
            arr[ch-'a']++;
        }
        for(char &c:ransomNote){
            if(arr[c-'a']==0){
                return false;
            }
            arr[c-'a']--;
        }
        return true;
    }
};