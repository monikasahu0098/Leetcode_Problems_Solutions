class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        if(n2<n1) return false;

        int freq[26]={0};
        int check[26]={0};

        for(char ch:s1){
            freq[ch-'a']++;
        }

        for(int i=0;i<n2;i++){
            check[s2[i]-'a']++;

            if(i>=n1) check[s2[i-n1]-'a']--;

            if(i>=n1-1 && equal(freq,freq+26,check)){
                return true;
            }
        }
        return false;
    }
};