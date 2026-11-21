class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        
        int n1=s.length();
        int n2=p.length();
        if(n1<n2) return v;

        int freq[26]={0};
        int check[26]={0};

        for(char ch:p){
            freq[ch-'a']++;
        }
        for(int i=0;i<n1;i++){
            check[s[i]-'a']++;

            if(i>=n2){
                check[s[i-n2]-'a']--;
            }
            if(i>=n2-1 && equal(freq,freq+26,check)){
                v.push_back(i-n2+1);
            }
        }
        return v;
    }
};