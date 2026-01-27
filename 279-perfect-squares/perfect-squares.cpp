class Solution {
public:
    int arr[10001];
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(arr[n]!=-1){
            return arr[n];
        }
        int minCount=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int result=1+solve(n-i*i);
            minCount=min(minCount,result);
        }
        return arr[n]=minCount;
    }
    int numSquares(int n) {
        memset(arr,-1,sizeof(arr));
        return solve(n);
    }
};