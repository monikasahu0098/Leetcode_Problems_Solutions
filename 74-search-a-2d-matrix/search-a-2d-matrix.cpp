class Solution {
public:
    
        // int n=matrix.size();
        // int m=matrix[0].size();
        // int low=0;
        // int high=n*m-1;
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     int row=mid/m;
        //     int col=mid%m;
        //     if(matrix[row][col]==target){
        //         return true;
        //     }else if(matrix[row][col]<target){
        //         low=mid+1;
        //     }else{
        //         high=mid-1;
        //     }
        // }
        // return false;
    bool searchInrow(vector<vector<int>>mat,int target,int row){
        int n=mat[0].size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(target==mat[row][mid]){
                return true;
            }else if(target<mat[row][mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return false;
    }


    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int stRow=0;
        int endRow=m-1;
        while(stRow<=endRow){
            int midRow=stRow+(endRow-stRow)/2;
            if(target>=matrix[midRow][0] && target<=matrix[midRow][n-1]){
                return searchInrow(matrix,target,midRow);
            }else if(target>=matrix[midRow][n-1]){
                stRow=midRow+1;
            }else{
                endRow=midRow-1;
            }
        }
        return false;
    }
};