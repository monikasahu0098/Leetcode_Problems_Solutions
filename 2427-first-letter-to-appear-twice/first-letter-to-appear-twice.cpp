class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[26]={0};
        char ans;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']==2){
                ans=s[i];
                break;
            }
        }
        return ans;
    }
};