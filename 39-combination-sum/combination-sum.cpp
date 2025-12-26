class Solution {
public:
    set<vector<int>>s;
    void findCombins(vector<int>&arr,int target,int i,vector<int>&combin,vector<vector<int>>&result){
        if(i==arr.size() || target<0){
            return;
        }
        if(target==0){
            if(s.find(combin) == s.end()){
                result.push_back({combin});
                s.insert({combin});
            }
            return;
        }
        combin.push_back(arr[i]);
        findCombins(arr,target-arr[i],i+1,combin,result);
        findCombins(arr,target-arr[i],i,combin,result);
        combin.pop_back();
        findCombins(arr,target,i+1,combin,result);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>result;
        vector<int>combin;
        findCombins(arr,target,0,combin,result);
        return result;
    }
};