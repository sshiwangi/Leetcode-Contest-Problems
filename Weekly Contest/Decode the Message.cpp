/*
You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
Align the substitution table with the regular English alphabet.
Each letter in message is then substituted using the table.
Spaces ' ' are transformed to themselves.
For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').

Example 1:

Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
Output: "this is a secret"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

Constraints:

26 <= key.length <= 2000
key consists of lowercase English letters and ' '.
key contains every letter in the English alphabet ('a' to 'z') at least once.
1 <= message.length <= 2000
message consists of lowercase English letters and ' '.

*/

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> subsValue;
        unordered_map<char,int> mp;
        // ASCII value of a
        int temp = 97;
        for(int i = 0; i<key.length(); i++){
            if(key[i] == ' ') continue;
            if(!mp[key[i]]){// if the character is not present in map insert it
                mp[key[i]]++;
                // put key character and the alphabet charecters in the subsValue
                subsValue[key[i]] = temp;
                temp++;
            }
        }
        string ans;
        for(int i = 0; i<message.length(); i++){
            // if the char is alphabet
            if(isalpha(message[i])){
                ans+= subsValue[message[i]];
            }
            else if(message[i] == ' '){
                ans.push_back(' ');
            }
            
        }
        return ans;
        
    }
};
