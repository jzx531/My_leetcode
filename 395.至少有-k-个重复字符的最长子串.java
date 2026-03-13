/*
 * @lc app=leetcode.cn id=395 lang=java
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
/*
class Solution {
    public int longestSubstring(String s, int k) {
        int n = s.length();
        return dfs(s,0,n-1,k);
    }

    public int dfs(String s,int l,int r,int k){
        int [] count = new int[26];
        for(int i = l;i<=r;i++)
        {
            count[s.charAt(i)-'a']++;
        }

        char split = 0;
        for(int i = 0;i<26;i++)
        {
            if(count[i] < k && count[i] > 0){
                split = (char)(i+'a');
                break;
            }
        }

        if(split ==0){
            return r-l+1;
        }

        int i = l;
        int ret = 0;
        while(i <= r)
        {
            while(i <= r && s.charAt(i) == split)
            {
                ++i;
            }
            if(i > r){
                break;
            }
            int start = i;
            while(i <= r && s.charAt(i) != split )
            {
                ++i;
            }
            ret = Math.max(ret,dfs(s,start,i-1,k));
        }
        return ret;
    }
}
*/
//滑动窗口法
class Solution {
    public int longestSubstring(String s, int k) {
        int ret = 0;
        int n = s.length();
        for (int t = 1; t <= 26; t++) {
            int l = 0, r = 0;
            int[] cnt = new int[26];
            int tot = 0;
            int less = 0;
            while (r < n) {
                cnt[s.charAt(r) - 'a']++;
                if (cnt[s.charAt(r) - 'a'] == 1) {
                    tot++;
                    less++;
                }
                if (cnt[s.charAt(r) - 'a'] == k) {
                    less--;
                }

                while (tot > t) {
                    cnt[s.charAt(l) - 'a']--;
                    if (cnt[s.charAt(l) - 'a'] == k - 1) {
                        less++;
                    }
                    if (cnt[s.charAt(l) - 'a'] == 0) {
                        tot--;
                        less--;
                    }
                    l++;
                }
                if (less == 0) {
                    ret = Math.max(ret, r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }
}

