class Solution {
public:
    long long mod_mul(long long a, long long b, long long m) {
        return (a % m) * (b % m) % m;
    }

    long long mod_expo(long long a, long long b, long long m) {
        long long res = 1;
        a = a % m;
        while (b > 0) {
            if (b % 2 == 1)
                res = mod_mul(res, a, m);
            a = mod_mul(a, a, m);
            b /= 2;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        long long ans = 0;

        while (r >= l) {
            while (r >= l && nums[r] > target - nums[l]) {
                r--;
            }
            if (r < l) break;
            int diff = r - l;
            ans = (ans + mod_expo(2, diff, MOD)) % MOD;
            l++;
        }
        return ans;
    }
};
