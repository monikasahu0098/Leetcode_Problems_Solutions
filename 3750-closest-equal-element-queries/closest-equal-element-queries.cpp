class Solution{
public:
    vector<int> solveQueries(vector<int>& nums,vector<int>& queries){
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for(int q:queries){
            auto &vec=mp[nums[q]];
            if(vec.size()==1){
                ans.push_back(-1);
                continue;
            }

            int pos=lower_bound(vec.begin(),vec.end(),q)-vec.begin();
            int m=vec.size();

            int prev=vec[(pos-1+m)%m];
            int next=vec[(pos+1)%m];

            int d1=abs(prev-q),d2=abs(next-q);
            ans.push_back(min(min(d1,n-d1),min(d2,n-d2)));
        }
        return ans;
    }
};