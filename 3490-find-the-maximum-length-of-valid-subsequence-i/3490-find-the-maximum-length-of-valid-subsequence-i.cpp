#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Yeh 4 possible patterns hain jo ek valid subsequence bana sakte hain.
        // {0, 0} -> Saare numbers even (E, E, E...).
        // {0, 1} -> Even aur odd alternate (E, O, E...).
        // {1, 0} -> Odd aur even alternate (O, E, O...).
        // {1, 1} -> Saare numbers odd (O, O, O...).
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        int ans = INT_MIN;

        // Hum har ek pattern (it) ko ek-ek karke check karenge.
        for (auto pattern : patterns) {
            // Har naye pattern ke liye, length count `cnt` ko 0 se shuru karenge.
            int cnt = 0;

            // Ab hum input array `nums` ke har number (num) se guzrenge.
            for (auto num : nums) {
                // Yeh line check karti hai ki kya current number `num` hamare pattern ke hisab se hai.
                // `num % 2` -> current number ki parity (0 ya 1).
                // `it[cnt % 2]` -> pattern ke hisaab se agli required parity.
                // Agar `cnt` 0 hai, toh `it[0]` check hoga. Agar `cnt` 1 hai, toh `it[1]` check hoga, etc.
                if (num % 2 == pattern[cnt % 2]) {
                    // Agar number pattern se match karta hai, toh subsequence ki length (cnt) badha denge.
                    cnt++;
                }
            }
            // Jab ek pattern ke liye poora `nums` array check ho jaaye,
            // toh us pattern se mili length (cnt) ko `ans` se compare karke maximum value store kar lenge.
            ans = max(ans, cnt);
        }
        
        // Saare 4 patterns check karne ke baad, `ans` mein jo sabse badi length hogi, use return kar denge.
        return ans;
    }
};