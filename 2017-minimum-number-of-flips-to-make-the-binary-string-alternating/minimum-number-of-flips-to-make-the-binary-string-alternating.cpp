class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        s= (s+s);

        string s1,s2;
        for(int i=0;i<2*n;i++){
            s1+=(i%2==1 ? '0' :'1'); //10101010......
            s2+=(i%2==1 ? '1' : '0');  //01010101......
        }
        int result=INT_MAX;
        int f1=0;
        int f2=0;
        int i=0;
        int j=0;

        while(j<2*n){
            if(s[j] != s1[j]){
                f1++;
            }
            if(s[j] != s2[j]){
                f2++;
            }
            if(j-i+1>n){     //shrink the window from left
                if(s[i] != s1[i]){
                    f1--;
                }
                if(s[i] != s2[i]){
                    f2--;
                }
                i++;
            }
            if(j-i+1 ==n){
                result=min({result,f1,f2});
            }
            j++;
        }
        return result;

    }
};