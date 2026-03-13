/*
 * @lc app=leetcode.cn id=468 lang=java
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution {
    public String validIPAddress(String queryIP) {
        if(queryIP.contains(".")){
            String[] parts = queryIP.split("\\.", -1);
            if(parts.length != 4) return "Neither";
            for(String part : parts){
                if(part.length() == 0 || part.length() > 3) return "Neither";
                if(part.charAt(0) == '0' && part.length() > 1) return "Neither";
                for(char c : part.toCharArray()){
                    if(!Character.isDigit(c)) return "Neither";
                }
                int num = Integer.parseInt(part);
                if(num < 0 || num > 255) return "Neither";
            }
            return "IPv4";
        } else if(queryIP.contains(":")){
            String[] parts = queryIP.split(":", -1);
            if(parts.length != 8) return "Neither";
            for(String part : parts){
                if(part.length() == 0 || part.length() > 4) return "Neither";
                for(char c : part.toCharArray()){
                    if(!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) 
                        return "Neither";
                }
            }
            return "IPv6";
        }
        
        return "Neither";
    }
}
// @lc code=end

