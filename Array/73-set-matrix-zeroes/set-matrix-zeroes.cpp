class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> roww(rows,0);
        vector<int> coll(cols,0);

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    roww[i]++;
                    coll[j]++;
                }

            }
        }

        for(int i=0;i<rows;i++){
            if(roww[i]!=0){
                for(int j=0;j<cols;j++){
                    matrix[i][j] *=0;
                }
            }
        }

        for(int i=0;i<cols;i++){
            if(coll[i]!=0){
                for(int j=0;j<rows;j++){
                    matrix[j][i] *=0;
                }
            }
        }
        
    }
};