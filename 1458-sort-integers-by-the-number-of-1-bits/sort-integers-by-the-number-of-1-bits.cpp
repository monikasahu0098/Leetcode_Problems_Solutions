class Solution {
public:
    // static int countBits(int n){
    //     int count=0;
    //     while(n != 0){
    //         if((n & 1)==1){
    //             count++;
    //         }
    //         n>>=1;
    //     }
    //     return count;
    // }
    // vector<int> sortByBits(vector<int>& arr) {
    //     sort(arr.begin(),arr.end(), [](int &a,int &b){
    //         int countA=countBits(a);
    //         int countB=countBits(b);

    //         if(countA==countB){
    //             return a<b;
    //         }
    //         return countA<countB;

    //     });
    //     return arr;
    // }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [](int &a,int &b){
            int countA=__builtin_popcount(a);
            int countB=__builtin_popcount(b);

            if(countA==countB){
                return a<b;
            }
            return countA<countB;

        });
        return arr;
    }

};