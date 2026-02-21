class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();

        if(len1 != len2){
            return false;
        }
        vector<int>f1(26,0);
        vector<int>f2(26,0);

        for(int i=0;i<len1;i++){
            char ch1=word1[i];
            char ch2=word2[i];

            f1[ch1-'a']++;
            f2[ch2-'a']++;
        }

        for(int i=0;i<26;i++){
            if(f1[i] != 0 && f2[i] != 0) continue;
            if(f1[i]==0 && f2[i]==0) continue;

            return false;
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());

        return f1==f2;

    }
};