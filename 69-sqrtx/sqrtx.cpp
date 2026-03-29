class Solution {
public:
    int mySqrt(int n) {
        if(n==0) return 0;
        int l=1;
        int ans;
        int h=n;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(mid*mid<=n){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;

    }
};