/* Problem Link: https://leetcode.com/contest/biweekly-contest-89/problems/number-of-valid-clock-times/

2437. Number of Valid Clock Times

You are given a string of length 5 called time, representing the current time on a digital clock in the format "hh:mm". 
The earliest possible time is "00:00" and the latest possible time is "23:59".

In the string time, the digits represented by the ? symbol are unknown, and must be replaced with a digit from 0 to 9.

Return an integer answer, the number of valid clock times that can be created by replacing every ? with a digit from 0 to 9.

 
Example 1:

Input: time = "?5:00"
Output: 2
Explanation: We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". 
Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.
Example 2:

Input: time = "0?:0?"
Output: 100
Explanation: Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.
Example 3:

Input: time = "??:??"
Output: 1440
Explanation: There are 24 possible choices for the hours, and 60 possible choices for the minutes. In total, we have 24 * 60 = 1440 choices.
 

Constraints:

time is a valid string of length 5 in the format "hh:mm".
"00" <= hh <= "23"
"00" <= mm <= "59"
Some of the digits might be replaced with '?' and need to be replaced with digits from 0 to 9. */

//code

class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        
        if(time[3] == '?')ans = ans * 6; //third place will have 6 choices
        if(time[4] == '?')ans = ans * 10; // fourth place will have 10 choices
        
        if(time[0] == '?' && time[1] == '?')ans = ans * 24; // if both hh are ??, we will have 24 choices
        else{
            if(time[1] == '?'){ // if second is ? and first is not, we will again have two choices
                if(time[0] == '2')ans = ans * 4; //if first is 2, then 2nd will have 4 choices that is 0,1,2,3
                else ans = ans * 10; // otherwise we will have 10 choices to fill up the 2nd place
            }
            if(time[0] == '?'){ // if first is ? and 2nd is not, then we will have 2 choices
                if(time[1] < '4')ans = ans * 3; // if 2nd is less than 4, we can fill first with 0,1,2 that is we have 3 choices
                else ans = ans * 2; // if 2nd is greater than 4, we can only fill first with 0,1 that is we have 2 choices.
            }
            
        }
        return ans;


    }
};
