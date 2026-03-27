class Solution {
public:
    vector<int> grayCode(int n) {
        int total=1<<n;
        vector<int>result;
        for(int i=0;i<total;i++){
            int gray=i^(i>>1);
            result.push_back(gray);
        }
        return result;
    }
};