class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        int mineven  = INT_MAX;
        int maxodd = 0;
        for(auto it:mp){
            if(it.second%2==0){
                mineven = min(mineven,it.second);
            }
            else{
                maxodd = max(maxodd,it.second);
            }
        } 
        if(mineven==INT_MAX){
            mineven = 0;
        }
        return maxodd-mineven;
    }
};