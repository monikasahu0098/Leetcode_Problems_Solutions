class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>judge(n,0);

        for(int i=0;i<trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];

            judge[u-1]--;
            judge[v-1]++;
        }
        for(int i=0;i<n;i++){
            if(judge[i]==(n-1)){
                return i+1;
            }
        }
        return -1;
    }
};