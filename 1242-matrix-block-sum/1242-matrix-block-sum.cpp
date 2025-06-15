class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(); 
        int n = mat[0].size();

        for(int i = 1;i<m ; i++){
            mat[i][0] = mat[i-1][0]+mat[i][0];
        }
        for(int i = 1;i<n ; i++){
            mat[0][i] = mat[0][i-1]+mat[0][i];
        }
        for(int i= 1 ; i< m ; i++){
            for(int j = 1; j<n ; j++){
                mat[i][j] = mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]+mat[i][j];
            }
        }
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i = 0;i<m ; i++){
            for(int j = 0 ; j< n ;j++){
               int a =  i-k>=0?i-k:0;
               int b = j-k>=0?j-k:0;
               int c = i+k<m?i+k:m-1;
               int d = j+k<n?j+k:n-1;

               int total = mat[c][d];
                if (a > 0) total -= mat[a-1][d];
                if (b > 0) total -= mat[c][b-1];
                if (a > 0 && b > 0) total += mat[a-1][b-1];
                ans[i][j] = total;
            }
        }
        return ans;
    }
};