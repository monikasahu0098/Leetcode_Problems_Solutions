class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>result;

        int n=changed.size();
        if(n%2 != 0){
            return {};
        }
        sort(changed.begin(),changed.end());
        unordered_map<int,int>m;
        for(int &n:changed){
            m[n]++;
        }
        for(int &n:changed){
            int dbl=2*n;
            if(m[n]==0){
                continue;
            }
            if(m.find(dbl)==m.end() || m[dbl]==0){
                return {};
            }
            result.push_back(n);
            m[n]--;
            m[dbl]--;
        }
        return result;
    }
};