class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<int>mst;
        int n = nums.size();
        for(int i = 0;i<k ; i++){
            mst.insert(nums[i]);
        }
        ans.push_back(*mst.rbegin());
        for(int i = k ; i<n ; i++){
            auto j = mst.find(nums[i-k]);
            if(j!=mst.end()){
                mst.erase(j);
            }
            mst.insert(nums[i]);

            ans.push_back(*mst.rbegin());
        }
        return ans;
    }
};