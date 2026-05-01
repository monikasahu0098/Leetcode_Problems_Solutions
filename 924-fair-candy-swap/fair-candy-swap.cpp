class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA=0;
        int sumB=0;
        for(int x:aliceSizes){
            sumA += x;
        }
        for(int x:bobSizes){
            sumB += x;
        }
        int diff=(sumB-sumA)/2;
        unordered_set<int>s(bobSizes.begin(),bobSizes.end());

        for(int a:aliceSizes)
            if(s.count(a + diff))
                return {a, a + diff};

        return {};
    }
};