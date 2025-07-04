class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> res;  // Ye vector saare duplicate elements ko store karega

        // Array ke har element ko iterate karte hain
        for(int i = 0; i < nums.size(); i++) {
            int t = abs(nums[i]); // current number ka absolute value le rahe hain 
                                  // (kyunki baad mein elements ko negative karenge)

            // Agar nums[t-1] already negative hai, iska matlab t already ek baar aa chuka hai
            if(nums[t - 1] < 0) {
                res.push_back(t);  // Duplicate mil gaya, result vector mein daal do
            }

            // nums[t-1] ko negative kar do taaki pata chale ki ye number visit ho chuka hai
            nums[t - 1] *= -1;
        }

        return res.back();  // Last duplicate ko return kar rahe hain (problem ke hisaab se ek hi duplicate hoga)
    }
};
