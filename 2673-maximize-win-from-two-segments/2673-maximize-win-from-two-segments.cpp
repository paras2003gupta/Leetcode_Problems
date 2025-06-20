class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        priority_queue<int>pq;  
        int n = prizePositions.size();
        int sum = 0;
        int j = 0;
        vector<int>ans(n);
        vector<int>suffix(n+1,0);
        for(int i = 0 ; i< n ;i++){
            auto ub = upper_bound(prizePositions.begin(),prizePositions.end(),prizePositions[i]+k);
            ub--;
            int len = (ub-prizePositions.begin()) - i + 1;
            ans[i] = len;
            

        }
        int maxi = INT_MIN;
        for(int i= n-1 ;i>=0; i--){
            maxi = max(maxi,ans[i]);
            suffix[i] = maxi;
        }
        int realans = 0;
        for(int i = 0;i<n ; i++){
            realans = max(realans,ans[i]+suffix[i+ans[i]]);
        }
        return realans;


    }
};