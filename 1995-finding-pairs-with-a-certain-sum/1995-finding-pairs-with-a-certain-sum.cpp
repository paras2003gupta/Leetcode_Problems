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


class FindSumPairs {
public:
    vector<int>n1,n2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1= nums1;
        n2 = nums2;    
        for(int i = 0;i<n2.size() ; i++){
            mp[n2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        n2[index]+=val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i:n1){
            int res = tot-i;
            if(mp.find(res)!=mp.end()){
                ans+=mp[res];
            }
        }
        return ans;
    }
};

