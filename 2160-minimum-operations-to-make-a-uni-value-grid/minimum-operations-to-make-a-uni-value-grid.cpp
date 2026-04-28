class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;
        for(auto &r:grid)
            for(int v:r){
                a.push_back(v);
            }
        int rem=a[0] % x;
        for(int v:a)
            if(v%x!=rem){
                return -1;
            }
        sort(a.begin(),a.end());
        int mid=a[a.size()/2];
        int ops = 0;

        for(int v:a){
            ops+= abs(v-mid)/x;
        }
        return ops;
    }
};