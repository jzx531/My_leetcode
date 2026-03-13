/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
public:
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        TrieNode() : isEnd(false) {
            memset(children, 0, sizeof(children));
        }
    };
    
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
    bool dfs(TrieNode* node, string word, int index) {
        if (index == word.length()) {
            return node->isEnd;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    if (dfs(node->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        } 
        else {
            return node->children[word[index] - 'a'] && dfs(node->children[word[index] - 'a'], word, index + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

