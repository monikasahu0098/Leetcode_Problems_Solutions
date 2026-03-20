class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();           
        int n=matrix[0].size();         
        vector<int>ans;
        int srow=0,erow=m-1;
        int scol=0,ecol=n-1;

        while(srow<=erow && scol<=ecol){
            //top most
            for(int j=scol ;j<=ecol;j++){
                ans.push_back(matrix[srow][j]);
            }
            //right
            for(int i=srow+1;i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
            }
            //bottom
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }

            //left
            for(int i=erow-1;i>srow;i--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }

            srow++; erow--;scol++;ecol--;
        }

        return ans;
    }
};