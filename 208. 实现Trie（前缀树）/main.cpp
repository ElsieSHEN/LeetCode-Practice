class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
/* memset 函数：char型初始化函数 */
/* void *memset(void *s, int ch, size_t n);
 * 函数功能：将s所指向的某一块内存中的前n个字节的内容全部设置为ch指定的ASCII值，
 * 第一个值为指定的内存地址，块的大小由第三个参数指定，
 * 这个函数通常为申请新内存做初始化工作，其返回值为指向s的指针，
 * 它是对较大的结构体或数组进行清零操作的一种最快方法。
 * memset(结构体/数组名 , 用于替换的ASCII码对应字符 , 前n个字符 );
 * memset(结构体/数组名 , "用于替换的字符“ , 前n个字符 );
 */

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c: word) {
            if (node->next[c-'a'] == NULL) {
                node->next[c-'a'] = new Trie();
            } 
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c: word) {
            node = node->next[c-'a'];
            if (node == NULL) return false;
        }
        return node->isEnd == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c: prefix) {
            node = node->next[c-'a'];
            if (node == NULL) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */