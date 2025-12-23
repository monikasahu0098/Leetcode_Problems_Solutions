class Solution {
public:
    bool isSamefreq(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(char &ch :s1){
            freq[ch-'a']++;
        }

        int windowSize=s1.length();
        for(int i=0;i<s2.length();i++){
            int windowIdx=0;
            int idx=i;
            int winFreq[26]={0};
            while(windowIdx<windowSize && idx<s2.length()){
                winFreq[s2[idx]-'a']++;
                windowIdx++;
                idx++;

            }
            if(isSamefreq(freq,winFreq)){
                return true;
            }
        }
        return false;
    }
};