/*  Minimum Amount of Time to Fill Cups
You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, 
or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, 
and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.

Example 1:

Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.

Constraints
amount.length == 3
0 <= amount[i] <= 100  */

// code

class Solution {
    int count = 0;
public:
    // we will always decrement from 2 maximum cups and when they become 0, we will empty the last cup in single move
    void solve(vector<int>&a){
        // sort the array
        sort(a.begin(),a.end());
        
        // base case when no of cups are 0
        if(a[0] == 0 && a[1]==0 && a[2]==0){
            return;
        }
        // decrement from last two elemets
        if(a[1] && a[2]){
            a[1]--;
            a[2]--;
            count++;
        }
        else{
            // when we'll reach here we will only be left with one cup that is the last one, why last one cause we are continuosly sorting the elements so the elements that are 0 lie in 0 and 1 index while the element which is non zero lies in the last index
            count += a[2]; // empty remaining cups in one move and add the no.of cups emptied in our answer
            a[2] = 0;
        }
        solve(a);
    }
    int fillCups(vector<int>& amount) {
        solve(amount);
        return count;
    }
};
