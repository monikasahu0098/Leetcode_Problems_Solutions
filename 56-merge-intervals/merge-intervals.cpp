class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            if(!result.empty() && end<=result.back()[1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<=end){
                    end=max(end,intervals[j][1]);
                }else{
                    break;
                }
            }
            result.push_back({st,end});
        }
        return result;
    }
};