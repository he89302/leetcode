/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (40.51%)
 * Likes:    16533
 * Dislikes: 724
 * Total Accepted:    1.3M
 * Total Submissions: 3.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 * 
 * 
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * 
 * Example 1:
 * 
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 * 
 * 
 */

// @lc code=start
/*
 * 
 * Think : 
 * used list 儲存目前的順序
 *      map 儲存每個key 對應在list 的begin 順序
 * 
 * get() : 用map 取得當下key 和找到當下key 對應到list 的順序(iterator)；
 *         再使用iterator 更新目前的list，使得key 的iterator 再list 的begin
 * 
 * put() : 分為key 有沒有存在: 如果key 存在了，那就直接更新list 內容
 *                            不存在 : 先考慮目前list size 有無 == capacity 的限制; 
 *                                    有的話，將list back pop & map ease 掉該key後再繼續
 *                            加入put 內容到list 最前面，並且更新map[key] = list::begin()
 * 
*/
class LRUCache {
private:
    int cachCapcity;
    //m_map_iter->first: key, m_map_iter->second: list iterator;
    //caches->first: key, m_list_iter->second: value;
    list<pair<int, int>> caches;
    unordered_map<int, list<pair<int, int>>::iterator> recordCache;
public:
    LRUCache(int capacity) : cachCapcity(capacity) {}
    
    int get(int key) {
        if(!recordCache.count(key))
            return -1;
        //move the node corresponding to key to front
        auto find_iter = recordCache.find(key);
        caches.splice(caches.begin(), caches, find_iter->second);
        return find_iter->second->second;
    }
    
    void put(int key, int value) {
        if(recordCache.find(key) != recordCache.end()) {
            auto find_iter = recordCache.find(key);
            caches.splice(caches.begin(), caches, find_iter->second); //move the node corresponding to key to front
            find_iter->second->second = value;
            return;
        }
        if(recordCache.size() == cachCapcity) {
            int last_recently_used_key = caches.back().first;
            caches.pop_back();
            recordCache.erase(last_recently_used_key);
        }
        caches.emplace_front(key, value);
        recordCache[key] = caches.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

