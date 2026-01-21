class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();

        vector<int>result;
        int r=0;
        int c=0;
        bool up=true;

        for(int i=0;i<rows*cols;i++){
            result.push_back(mat[r][c]);

            if(up){
                if(c==cols-1){
                    r++;
                    up=false;
                }else if(r==0){
                    c++;
                    up=false;
                }else{
                    c++;
                    r--;
                }
            }else{
                if(r==rows-1){
                    c++;
                    up=true;
                }else if(c==0){
                    r++;
                    up=true;
                }else{
                    r++;
                    c--;
                }
            }
        }
        return result;
        
    }
};