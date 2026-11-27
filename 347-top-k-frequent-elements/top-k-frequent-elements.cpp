class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;

        for(int n:nums){
            mp[n]++;
        }
        vector<pair<int,int>>vec(mp.begin(),mp.end());

        sort(vec.begin(),vec.end(),[](const pair<int,int>&a, const pair<int,int>&b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
        
    }
};