class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;
        int n=intervals.size();
        int st=newInterval[0];
        int end=newInterval[1];

        int i=0;
        while(i<n && intervals[i][1]<st){
            result.push_back(intervals[i]);
            i++;
        }
        
        while(i<n && intervals[i][0]<=end){
            st=min(st,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i++;
        }
        result.push_back({st,end});

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};