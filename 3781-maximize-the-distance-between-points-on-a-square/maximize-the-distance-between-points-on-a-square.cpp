class Solution {
public:
   bool can(vector<long long>&b,int n,int k,long long d,long long per){
    for(int i=0;i<n;i++){
        int cnt=1,idx=i;
        long long last=b[i];

        while(cnt<k){
            int j=lower_bound(b.begin()+idx+1,b.begin()+i+n,last+d)-b.begin();
            if(j>=i+n)break;
            cnt++;
            last=b[j];
            idx=j;
        }

        // check circular condition
        if(cnt==k && per-(last-b[i])>=d) return true;
    }
    return false;
}

int maxDistance(int side,vector<vector<int>>&points,int k){
    vector<long long>a;
    long long per=4LL*side;

    for(auto&p:points){
        int x=p[0],y=p[1];
        if(x==0)a.push_back(y);
        else if(y==side)a.push_back(side+x);
        else if(x==side)a.push_back(2LL*side+(side-y));
        else a.push_back(3LL*side+(side-x));
    }

    sort(a.begin(),a.end());

    int n=a.size();
    vector<long long>b=a;
    for(auto x:a) b.push_back(x+per);

    long long l=0,r=2LL*side,ans=0;

    while(l<=r){
        long long mid=(l+r)/2;
        if(can(b,n,k,mid,per)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return ans;
}
};