/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 */

// @lc code=start
class Solution {
public:
int daysBetweenDates(string date1, string date2) {
    int y1 = stoi(date1.substr(0, 4)), m1 = stoi(date1.substr(5, 2)), d1 = stoi(date1.substr(8, 2));
    int y2 = stoi(date2.substr(0, 4)), m2 = stoi(date2.substr(5, 2)), d2 = stoi(date2.substr(8, 2));
    return abs(daysFrom1970(y1, m1, d1) - daysFrom1970(y2, m2, d2));
}

int daysFrom1970(int year, int month, int day) {
    int total = 0;
    for (int y = 1970; y < year; y++) {
        total += isLeap(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        total += daysInMonth(year, m);
    }
    total += day;
    return total;
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    if (month == 2) return isLeap(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}
};
// @lc code=end

