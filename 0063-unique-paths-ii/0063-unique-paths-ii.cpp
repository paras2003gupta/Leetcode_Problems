class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size();
        int m = og[0].size();

        vector<int>prev(m,0);
        for(int i = 0 ;i<n ; i++){
            vector<int>temp(m,0);
            for(int j = 0 ;j<m ; j++){
                
                if((i==0&&j==0)&&og[i][j]!=1){
                    temp[j] = 1;
                    continue;
                }
                if(og[i][j]==1){
                    temp[j] = 0;
                    continue;
                }

                if(i>0){
                    temp[j] += prev[j];
                }
                if(j>0){
                    temp[j] += temp[j-1];
                }



            }
            prev = temp;
        }
        return (og[n-1][m-1]==1)?0: prev[m-1];
    }
};