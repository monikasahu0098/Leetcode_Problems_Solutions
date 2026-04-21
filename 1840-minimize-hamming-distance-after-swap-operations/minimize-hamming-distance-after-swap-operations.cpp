class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        function<int(int)>find=[&](int x){
            return parent[x]== x? x : parent[x]=find(parent[x]);
        };

        auto unite=[&](int a,int b){
            int pa=find(a);
            int pb=find(b);
            if(pa != pb){
                parent[pa]=pb;
            }
        };

        for(auto& e:allowedSwaps){
            unite(e[0],e[1]);
        }

        unordered_map<int,unordered_map<int,int>>mp;

        for(int i=0;i<n;i++){
            mp[find(i)][source[i]]++;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int p=find(i);
            if(mp[p][target[i]]>0)mp[p][target[i]]--;
            else ans++;
        }
        return ans;
        
    }
};