class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long result =0 ;
        vector<unordered_map<long long,long long>>mp(n);
        for(int i = 0 ;i< n ; i++){
            for(int j = 0 ; j<i ; j++){
                long long diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);

                long long count_at_j = (it==mp[i].end())?0:it->second;

                mp[i][diff]+=count_at_j+1;
                result +=count_at_j;
            }

        }
        return result;
    }
};