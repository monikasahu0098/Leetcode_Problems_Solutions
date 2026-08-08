class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        int R=n2-1;
        int C=0;
        vector<int> Right(n1);
        for(int i=n1-1;i>=0;i--){
            Right[i]=C;
            if(R>=0 && word1[i]==word2[R]){
                R--;
                C++;
            }
        }
        vector<int> ans;
        bool changed=false;
        int j=0;
        for(int i=0;i<n1 && j<n2;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!changed && Right[i]>=n2-1-j){
                ans.push_back(i);
                j++;
                changed=true;
            }
        }
        if(j==n2){
            return ans;
        }
        return {};
    }
};