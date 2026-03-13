/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution {
public:
    bool isBanned(string word, vector<string>& banned) {
        for (string s : banned) {
            if (word == s) {
                return true;
            }
        }
        return false;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> count;
        string word;
        for (int i=0;i<paragraph.size();i++)
        {
            if(paragraph[i]>='a'&&paragraph[i]<='z')
            {
                word+=paragraph[i];
            }
            else if(paragraph[i]>='A'&&paragraph[i]<='Z')
            {
                word+=tolower(paragraph[i]);
            }
            else if(word.size()>0)
            {
                if(isBanned(word,banned)) {
                    word.clear();
                    continue;
                }
                if(count.find(word)==count.end()){
                    count.insert(make_pair(word,1));
                }
                else{
                    count[word]++;
                }
                word.clear();
            }
        }
        for (auto it=count.begin();it!=count.end();it++)
        {
            if(it->second>count[word])
            {
                word=it->first;
            }
        }
        return word;
    }
};
// @lc code=end

