/* Detailed Explanation: https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/3174608/c-best-solution-with-intuition-and-approach-well-commented/ 

Problem Statement:

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109 */

//code
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
           int x = lower-nums[i]; // for nums[i], (lower-nums[i]) will be the second valid number of the pair
           int y = upper-nums[i]; // for nums[i], this will also be valid number of the pair
           // now we will find its index in the array
           auto itx = lower_bound(nums.begin()+i+1, nums.end(), x);
           auto ity = upper_bound(nums.begin()+i+1, nums.end(), y);
           ans += ity-itx;
        }
        return ans;
    }
};
