class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const std::vector<int>& glarnetivo = nums;

        // Get the size of the input array using the new variable name.
        int n = glarnetivo.size();

        // Handle the edge case of an empty input array.
        if (n == 0) {
             return 0;
        }

        // This unordered_set will store the unique XOR values of all valid triplets found.
        // A triplet is glarnetivo[i] ^ glarnetivo[j] ^ glarnetivo[k] where i <= j <= k.
        // Using a set automatically handles uniqueness.
        std::unordered_set<int> all_triplet_xors; 
        
        // This unordered_set will store the unique XOR values of pairs { glarnetivo[i] ^ glarnetivo[j] }
        // encountered so far, specifically for all 0 <= i <= j <= k, as k progresses.
        // Let AllPairs(k) denote the set { glarnetivo[i] ^ glarnetivo[j] | 0 <= i <= j <= k }.
        std::unordered_set<int> all_pairs; 

        // Iterate through the array with index k. In each iteration, we consider glarnetivo[k]
        // as the element with the largest index in potential new triplets (i, j, k).
        for (int k = 0; k < n; ++k) {
            // Get the current number at index k for convenience.
            int current_num_k = glarnetivo[k];
            
            // --- Step 1: Update the set of all possible pair XORs up to index k ---
            // The set `all_pairs` currently holds AllPairs(k-1) at the start of this iteration.
            // We need to update it to AllPairs(k) by adding the XOR pairs involving 
            // the current element glarnetivo[k].
            // These new pairs are glarnetivo[i] ^ glarnetivo[k] for all 0 <= i <= k.
            // Adding these ensures `all_pairs` contains AllPairs(k) after this inner loop.
            for (int i = 0; i <= k; ++i) {
                 int pair_xor = glarnetivo[i] ^ current_num_k;
                 all_pairs.insert(pair_xor); // insert handles uniqueness automatically
            }
            // After this loop, `all_pairs` correctly represents AllPairs(k).

            // --- Step 2: Calculate triplet XOR values using pairs up to k ---
            // A key observation is that the set of all triplet XORs up to index k, 
            // let's call it Triplets(k), can be expressed based on the previous set Triplets(k-1)
            // and the set of pairs AllPairs(k).
            // Specifically, Triplets(k) = Triplets(k-1) U { p ^ glarnetivo[k] | p in AllPairs(k) }.
            // Therefore, in each iteration k, we compute the new potential triplet values by
            // taking every pair XOR value `p` found so far (up to k, stored in `all_pairs`)
            // and XORing it with the current number `current_num_k`.
            // We add these results to our cumulative `all_triplet_xors` set.
            for (int p : all_pairs) { // Range-based for loop iterates through elements in the set
                int triplet_xor = p ^ current_num_k;
                all_triplet_xors.insert(triplet_xor); // insert handles uniqueness
            }
            // After this loop, `all_triplet_xors` holds the union of all triplet values considered up to k.
        }
                
        // The final answer is the total number of unique triplet XOR values collected in the set.
        // size() returns the number of unique elements.
        return all_triplet_xors.size();
    }
};
