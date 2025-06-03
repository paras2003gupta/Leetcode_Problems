class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        queue<int>q;
        vector<int>visited(n,0);
        vector<int>hasbox(n,0);
        for(auto it:initialBoxes){
            hasbox[it] = 1;
        }
        int totalCandies = 0;
        bool progress = true;
        while(progress){
            progress = false;
            for(int i = 0;i<n ; i++){
                if(hasbox[i]&&!visited[i]&&status[i]){
                    visited[i] = 1;
                    totalCandies+=candies[i];
                    progress = true;
                    for(int it:keys[i]){
                        status[it] = 1;
                    }
                    for(int it:containedBoxes[i]){
                        hasbox[it] = 1;
                    }
                }
            }
        }
        return totalCandies;
    }
};