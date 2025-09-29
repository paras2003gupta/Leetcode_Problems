class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto& s : strs) {
            // Create a frequency count key for 26 lowercase letters
            int count[26] = {0};
            for (char c : s)
                count[c - 'a']++;
            
            // Build a unique string key from frequency count
            string key;
            for (int i = 0; i < 26; ++i) {
                key += '#';
                key += to_string(count[i]);
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& pair : mp)

            ans.push_back(std::move(pair.second));

        return ans;
    }
};
