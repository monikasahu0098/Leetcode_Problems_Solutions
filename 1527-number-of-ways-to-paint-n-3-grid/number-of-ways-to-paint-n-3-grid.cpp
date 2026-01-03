class Solution {
public:
    int numOfWays(int n) {
        const int MOD=1e9+7;
        long long three=6;
        long long two=6;
        for(int i=2;i<=n;i++){
            long long new_three=(2*three+2*two)%MOD;
            long long new_two=(2*three+3*two)%MOD;

            three=new_three;
            two=new_two;
        }
        return (three+two)%MOD;

    }
};