class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n_s = s.length();
        int n_p = p.length();
        vector<int>result;
        // Edge case: if p is longer than s, no anagrams can exist
        if (n_p > n_s) return result;
        
        // Two frequency arrays of size 26
        std::vector<int> p_counts(26, 0);
        std::vector<int> s_counts(26, 0);
        
        // Initialize the count for p and the first window of s
        for (int i = 0; i < n_p; i++) {
            p_counts[p[i] - 'a']++;
            s_counts[s[i] - 'a']++;
        }
        
        // Check the very first window
        if (p_counts == s_counts) {
            result.push_back(0);
        }
        
        // Slide the window across string s
        for (int i = n_p; i < n_s; i++) {
            // Add the new character on the right
            s_counts[s[i] - 'a']++;
            // Remove the old character from the left
            s_counts[s[i - n_p] - 'a']--;
            
            // Check if the current window matches p's frequency map
            if (p_counts == s_counts) {
                result.push_back(i - n_p + 1); // Starting index of the window
            }
        }
        
        return result;
    }
    
};