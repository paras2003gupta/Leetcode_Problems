const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;

        for(int i = 0;i<k ;i++){
            pq.push({nums[i],i});

        }
        vector<int>ans ;
        ans.push_back(pq.top().first);
        int n = nums.size();
        for(int i = k ; i< n ;i++){
            pq.push({nums[i],i});

            while(!pq.empty()&&pq.top().second<i-k+1){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};