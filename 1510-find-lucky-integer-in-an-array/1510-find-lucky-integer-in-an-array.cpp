class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>vec(501,0);
        for(auto it:arr){
            vec[it]++;
        }
        int maxi = *max_element(arr.begin(),arr.end());
        int ans = -1;
        for(int i = 1;i<=maxi; i++){
            if(vec[i]==i){
                ans = i;
            }
        }
        return ans;
    }
};