class Solution {
public:
    long long sum(vector<int>& arr){
        long long total=0;
        for(int num:arr){
            if(num%2==0){
                total +=num;
            }
        }
        return total;
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>result;
        int n1=nums.size();
        int n2=queries.size();

        for(auto &q :queries){
            nums[q[1]]+= q[0];
            result.push_back(sum(nums));
        }
        return result;
    }
};