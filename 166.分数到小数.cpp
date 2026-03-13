/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    
    string result;
    
    // Determine the sign
    if ((numerator < 0) ^ (denominator < 0)) {
        result += '-';
    }
    
    // Convert to absolute values to simplify division
    long num = abs(static_cast<long>(numerator));
    long den = abs(static_cast<long>(denominator));
    
    // Integer part
    result += to_string(num / den);
    long remainder = num % den;
    if (remainder == 0) {
        return result;
    }
    
    // Fractional part
    result += '.';
    unordered_map<long, int> remainderPositions;
    while (remainder != 0) {
        if (remainderPositions.find(remainder) != remainderPositions.end()) {
            // Insert parentheses around the repeating part
            result.insert(remainderPositions[remainder], "(");
            result += ')';
            break;
        }
        remainderPositions[remainder] = result.size();
        remainder *= 10;
        result += to_string(remainder / den);
        remainder %= den;
    }
    
    return result;
}
};
// @lc code=end

