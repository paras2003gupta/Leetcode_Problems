class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n  = grid.size();
        int m  = grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1,0));
        if(k==1){
            return ans;
        }
        for(int i = 0; i<n-k+1 ;i++){
            for(int j = 0;j<m-k+1 ; j++){
                vector<int>ele ;
                

                for(int p = i ; p<min(i+k,n) ; p++){
                    for(int q = j ; q<min(j+k,m) ; q++){
                        ele.push_back(grid[p][q]);
                    }
                }
                
                sort(ele.begin(),ele.end());
                int mini = INT_MAX;
                

                for(int l = 0 ; l<ele.size()-1 ; l++){
                    int val = abs(ele[l]-ele[l+1]);
                    if(val==0)continue;
                    mini = min(mini,val);
                }
                if(mini!=INT_MAX)ans[i][j] = mini;



            }
        }
        
        
        
        
        return ans;
        }
};