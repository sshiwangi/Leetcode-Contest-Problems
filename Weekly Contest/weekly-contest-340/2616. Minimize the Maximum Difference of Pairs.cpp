/* Problem link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
Solution Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/3396252/simple-binary-search-solution-with-comments-easy-to-understand/

You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs.

Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
Example 2:

Input: nums = [4,2,1,2], p = 1
Output: 0
Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= p <= (nums.length)/2 */

//code
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end()); //sort the array
        int n = nums.size(); 
//the minimum possible answer will be 0 and the maximum possible answer will be the difference of maximum and minimum numbers
        int left = 0, right = nums[n - 1] - nums[0];
//do simple binary searching here
        while (left < right) {
// we will assume mid to be our answer that is the maximum possible difference
            int mid = (left + right) / 2;
            int k = 0; //to count number of pairs
            for (int i = 1; i < n; ++i) {
                if (nums[i] - nums[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
//if the number of pairs is greater than p, then it means there are enough pairs on the left side that are less than mid value, so we don't need to check on the right side as we if mid value satisfies our condition then numbers greater than this will also satisfy this condition. So try to find more optimal solution in the left hand side only.
            if (k >= p) 
                right = mid;
            else
                left = mid + 1; //otherwise check in the right hand side
        }
        return left;
    
    }
};
