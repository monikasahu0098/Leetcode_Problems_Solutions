// class Solution {
// public:
//     int largestMagicSquare(vector<vector<int>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();

//         vector<vector<int>>rowCumSum(rows,vector<int>(cols));
//         vector<vector<int>>colCumSum(rows,vector<int>(cols));

//         for(int i=0;i<rows;i++){
//             rowCumSum[i][0]=grid[i][0];
//             for(int j=1;j<cols;j++){
//                 rowCumSum[i][j]=rowCumSum[i][j-1]+grid[i][j];
//             }
//         }
//         for(int j=0;j<cols;j++){
//             colCumSum[0][j]=grid[0][j];
//             for(int i=1;i<rows;i++){
//                 colCumSum[i][j]=colCumSum[i-1][j]+grid[i][j];
//             }
//         }

//         for(int side=min(rows,cols);side>=2;side++){

//             for(int i=0;i+side-1<rows;i++){
//                 for(int j=0;j+side-1<cols;j++){
//                     int targetSum=rowCumSum[i][j+side-1]-((j>0) ? rowCumSum[i][j-1] :0) ;

//                     bool isSame=true;

//                     for(int r=i+1;r<i+side;r++){
//                         int rowSum=rowCumSum[r][j+side-1]-((j>0) ? rowCumSum[r][j-1]:0);

//                         if(rowSum!=targetSum){
//                             isSame=false;
//                             break;
//                         }
//                     }

//                     if(!isSame){
//                         continue;
//                     }

//                     for(int c=j+1;c<j+side;c++){
//                         int colSum=colCumSum[i+side-1][c]-((i>0) ? colCumSum[i-1][c]:0);

//                         if(colSum!=targetSum){
//                             isSame=false;
//                             break;
//                         }
//                     }
//                     if(!isSame){
//                         continue;
//                     }

//                     int diag=0;
//                     int antidiag=0;

//                     for(int k=0;k<side;k++){
//                         diag=diag+grid[i+k][j+k];
//                         antidiag=antidiag+grid[i+k][j+side-1-k];
//                     }
//                     if(diag==targetSum && antidiag==targetSum){
//                         return side;
//                     }
//                 }
//             }
//         }
//         return 1;
//     }
// };


class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Prefix sums
        vector<vector<int>> rowCumSum(rows, vector<int>(cols));
        vector<vector<int>> colCumSum(rows, vector<int>(cols));

        // Row prefix sum
        for (int i = 0; i < rows; i++) {
            rowCumSum[i][0] = grid[i][0];
            for (int j = 1; j < cols; j++) {
                rowCumSum[i][j] = rowCumSum[i][j - 1] + grid[i][j];
            }
        }

        // Column prefix sum
        for (int j = 0; j < cols; j++) {
            colCumSum[0][j] = grid[0][j];
            for (int i = 1; i < rows; i++) {
                colCumSum[i][j] = colCumSum[i - 1][j] + grid[i][j];
            }
        }

        // Try larger squares first
        for (int side = min(rows, cols); side >= 2; side--) {
            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {

                    // Target sum (first row of the square)
                    int targetSum =
                        rowCumSum[i][j + side - 1] -
                        (j > 0 ? rowCumSum[i][j - 1] : 0);

                    bool isMagic = true;

                    // Check all rows
                    for (int r = i + 1; r < i + side; r++) {
                        int rowSum =
                            rowCumSum[r][j + side - 1] -
                            (j > 0 ? rowCumSum[r][j - 1] : 0);

                        if (rowSum != targetSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    if (!isMagic) continue;

                    // Check all columns
                    for (int c = j; c < j + side; c++) {
                        int colSum =
                            colCumSum[i + side - 1][c] -
                            (i > 0 ? colCumSum[i - 1][c] : 0);

                        if (colSum != targetSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    if (!isMagic) continue;

                    // Check diagonals
                    int diag = 0, antiDiag = 0;
                    for (int k = 0; k < side; k++) {
                        diag += grid[i + k][j + k];
                        antiDiag += grid[i + k][j + side - 1 - k];
                    }

                    if (diag == targetSum && antiDiag == targetSum) {
                        return side;
                    }
                }
            }
        }

        // At least 1x1 square is always magic
        return 1;
    }
};
