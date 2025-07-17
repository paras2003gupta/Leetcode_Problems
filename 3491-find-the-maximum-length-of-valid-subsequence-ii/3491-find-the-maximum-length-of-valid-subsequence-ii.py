from typing import List

class Solution:
  def maximumLength(self, nums: List[int], k: int) -> int:
    """
    Finds the maximum length of a valid subsequence using dynamic programming.

    The state dp[i][j] stores the length of the longest valid subsequence
    ending with remainder i, whose previous element had remainder j.
    """
    if not nums:
      return 0
      
    # dp[ending_rem][previous_rem]
    dp = [[0] * k for _ in range(k)]
    max_len = 0
    
    # O(n * k)
    for num in nums:
      r_curr = num % k
      for r_prev in range(k):
        # A sequence ending in r_prev (with r_curr before it) can be
        # extended by the current number (with remainder r_curr).
        # The new sequence ends in r_curr, with r_prev before it.
        dp[r_curr][r_prev] = dp[r_prev][r_curr] + 1
      
    # The result is the maximum value in the entire dp table.
    for r1 in range(k):
      for r2 in range(k):
        max_len = max(max_len, dp[r1][r2])
        
    return max_len