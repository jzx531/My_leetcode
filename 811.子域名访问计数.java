/*
 * @lc app=leetcode.cn id=811 lang=java
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> res = new ArrayList<String>();
        Map<String, Integer> counts = new HashMap<String, Integer>();
        for (String cpdomain : cpdomains) {
            String[] parts = cpdomain.split(" ");
            int count = Integer.parseInt(parts[0]);
            String domain = parts[1];
            String[] subdomains = domain.split("\\.");
            for (int i = 0; i < subdomains.length; i++) {
                String subdomain = subdomains[i];
                // String key = subdomain + (i == subdomains.length - 1? "" : "." + domain);
                String key = subdomain;
                
                for(int j = i+1; j < subdomains.length; j++)
                {
                    key += "." + subdomains[j];
                }

                counts.put(key, counts.getOrDefault(key, 0) + count);
            }
        }
        for (String key : counts.keySet()) {
            res.add(counts.get(key) + " " + key);
        }
        return res;
    }
}
// @lc code=end

