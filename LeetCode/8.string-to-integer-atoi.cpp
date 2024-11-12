/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (18.11%)
 * Likes:    4838
 * Dislikes: 14087
 * Total Accepted:    1.7M
 * Total Submissions: 9.5M
 * Testcase Example:  '"42"'
 *
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit
 * signed integer.
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * 
 * Whitespace: Ignore any leading whitespace (" ").
 * Signedness: Determine the sign by checking if the next character is '-' or
 * '+', assuming positivity if neither present.
 * Conversion: Read the integer by skipping leading zeros until a non-digit
 * character is encountered or the end of the string is reached. If no digits
 * were read, then the result is 0.
 * Rounding: If the integer is out of the 32-bit signed integer range [-2^31,
 * 2^31 - 1], then round the integer to remain in the range. Specifically,
 * integers less than -2^31 should be rounded to -2^31, and integers greater
 * than 2^31 - 1 should be rounded to 2^31 - 1.
 * 
 * 
 * Return the integer as the final result.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "42"
 * 
 * Output: 42
 * 
 * Explanation:
 * 
 * 
 * The underlined characters are what is read in and the caret is the current
 * reader position.
 * Step 1: "42" (no characters read because there is no leading whitespace)
 * ⁠        ^
 * Step 2: "42" (no characters read because there is neither a '-' nor '+')
 * ⁠        ^
 * Step 3: "42" ("42" is read in)
 * ⁠          ^
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = " -042"
 * 
 * Output: -42
 * 
 * Explanation:
 * 
 * 
 * Step 1: "   -042" (leading whitespace is read and ignored)
 * ⁠           ^
 * Step 2: "   -042" ('-' is read, so the result should be negative)
 * ⁠            ^
 * Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
 * ⁠              ^
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "1337c0d3"
 * 
 * Output: 1337
 * 
 * Explanation:
 * 
 * 
 * Step 1: "1337c0d3" (no characters read because there is no leading
 * whitespace)
 * ⁠        ^
 * Step 2: "1337c0d3" (no characters read because there is neither a '-' nor
 * '+')
 * ⁠        ^
 * Step 3: "1337c0d3" ("1337" is read in; reading stops because the next
 * character is a non-digit)
 * ⁠            ^
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "0-1"
 * 
 * Output: 0
 * 
 * Explanation:
 * 
 * 
 * Step 1: "0-1" (no characters read because there is no leading whitespace)
 * ⁠        ^
 * Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
 * ⁠        ^
 * Step 3: "0-1" ("0" is read in; reading stops because the next character is a
 * non-digit)
 * ⁠         ^
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "words and 987"
 * 
 * Output: 0
 * 
 * Explanation:
 * 
 * Reading stops at the first non-digit character 'w'.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 200
 * s consists of English letters (lower-case and upper-case), digits (0-9), '
 * ', '+', '-', and '.'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int j=0;
        while(j<s.size()){
            if(s[j]==' '){
                s.erase(s.begin());
            }
            else{
                break;
            }
        }
        long long int final = 0;
        int count = 0;
        if(s[0]=='-'){
            if(s[1] == '+' || s[1]=='-'){
                return 0;
            }
            else{
                count++;
                s.erase(s.begin());
            }
        }  
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' && i==0){
                continue;
            }
            
            else if((48 <= s[i]) && (s[i] <= 57)){
                final = (final*10) + (s[i]-48);
                if(count){
                    final = final*-1;
                    if(final<INT_MIN){
                        return INT_MIN;
                    }
                    final = final*-1;
                }
                else{
                    if(final>INT_MAX){
                        return INT_MAX;
                    }
                }

            }
            else{
                break;
            }
        }
        if(count){
            return (final*(-1));
        }
        else{
            return final;
        }

        
    }
};
// @lc code=end

