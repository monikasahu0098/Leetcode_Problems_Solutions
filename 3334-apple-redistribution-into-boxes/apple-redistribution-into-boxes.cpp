class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count=0;
        sort(capacity.begin(),capacity.end(),greater<>());
        int total_apples=0;
        for(int &i:apple){
            total_apples+=i;
        }
        int i=0;
        while(total_apples>0){
            total_apples-=capacity[i];
            count++;
            i++;
        }
        return count;
    }
};