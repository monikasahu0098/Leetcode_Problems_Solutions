class Solution {
public:
    bool check(int k,int i,int j,int threshold,vector<vector<int>>&prefix){
        int m=prefix.size()-1;
        int n=prefix[0].size()-1;
        if(i+k-1>m || j+k-1>n){
            return false;
        }
        int sum=prefix[i+k-1][j+k-1]-prefix[i+k-1][j-1]-prefix[i-1][j+k-1]+prefix[i-1][j-1];

        return sum<=threshold;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        int maxi=0;
        vector<vector<int>>prefix(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=mat[i-1][j-1];
                prefix[i][j]+=prefix[i-1][j];
                prefix[i][j]+=prefix[i][j-1];
                prefix[i][j]-=prefix[i-1][j-1];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int low=0;
                int high=min(m-i+1,n-j+1);
                while(low<=high){
                    int mid=(low+high)/2;
                    if(check(mid,i,j,threshold,prefix)){
                        low=mid+1;
                        maxi=max(maxi,mid);
                    }else{
                        high=mid-1;
                    }
                }
            }
        }
        return maxi;
    }
};