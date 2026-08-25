class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for( int t =1 ; t<1000 ; t++){
            
            if(mp.find(k*t)==mp.end()){
                return k*t;
            }
            
        }
        return -1;
    }
};