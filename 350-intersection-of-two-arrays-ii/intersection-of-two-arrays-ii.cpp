class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int>freq;
        for(int &n:nums1){
            freq[n]++;
        }
        for(int &m:nums2){
            if(freq[m]>0){
                result.push_back(m);
                freq[m]--;
            }
        }
        return result;
    }
};