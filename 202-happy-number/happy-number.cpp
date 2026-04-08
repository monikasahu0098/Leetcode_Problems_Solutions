class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n !=1 && s.find(n)==s.end()){
            s.insert(n);
            int sum=0;
            while(n>0){
                int rem=n%10;
                sum=sum+(rem*rem);
                n=n/10;
            }
            n=sum;
        }
        if(n==1){
            return true;
        }else{
            return false;
        }
    }
};