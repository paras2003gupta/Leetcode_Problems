class Solution {
public:
    int rob(vector<int>& arr) {
         int n = arr.size();
            if(n==0){
                return 0;
            }
            if(n==1){
                return arr[0];
            }
            int prev0 = 0;
            int prev1 = arr[0];
            
            for (int i = 2; i <=n; i++) {
                int curr = max(prev1,arr[i-1]+prev0);
                prev0=prev1;
                prev1=curr;
            }
            return max(prev0,prev1) ;
            }
};