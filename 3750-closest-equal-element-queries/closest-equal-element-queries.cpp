class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];

            // If only one occurrence
            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // Step 2: find position of q in vec
            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int m = vec.size();

            // previous index (circular)
            int prev = vec[(pos - 1 + m) % m];

            // next index (circular)
            int next = vec[(pos + 1) % m];

            // calculate distances
            int d1 = abs(prev - q);
            int d2 = abs(next - q);

            int dist1 = min(d1, n - d1);
            int dist2 = min(d2, n - d2);

            ans.push_back(min(dist1, dist2));
        }

        return ans;
    }
};