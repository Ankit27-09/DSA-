// Question Link -> https://leetcode.com/problems/lru-cache/submissions/1813041831/

// First approach is by taking the vector of pairs so this gives the TLE
#include <iostream>
#include <vector>

using namespace std;

/*
    ⚙️ LRUCache (Least Recently Used Cache) — Simple Implementation Using Vector

    🔹 Concept:
      - Cache stores key-value pairs.
      - The most recently used (MRU) element should stay at the end.
      - The least recently used (LRU) element should be at the front.
      - When capacity is full and a new key is added → remove the LRU (front element).

    🧠 Operations:
      1. get(key) → return value if key exists, else -1.
         - Move the accessed element to the end (since it becomes MRU).

      2. put(key, value) → insert or update the key.
         - If key exists → update value and move to end.
         - If key doesn’t exist → add new pair at end.
         - If cache is full → remove front (LRU) before inserting new.
*/

class LRUCache {
public:
    vector<pair<int, int>> cache;  // Stores {key, value} pairs
    int n;  // Maximum capacity of cache

    // Constructor to set the cache capacity
    LRUCache(int capacity) {
        n = capacity;        
    }
    
    /*
        🔹 get(key):
        - Search for the key in the cache.
        - If found:
            • Store its value.
            • Remove the key-value pair from current position.
            • Push it to the end → marking it as "most recently used".
            • Return its value.
        - If not found → return -1.
    */
    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int val = cache[i].second;

                // Move this (key, value) to the end → MRU position
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i); // remove from old position
                cache.push_back(temp);          // insert at end

                return val; // return the value found
            }
        }
        // Key not found
        return -1;
    }
    
    /*
        🔹 put(key, value):
        - First check if the key already exists:
            • If yes → remove the old pair and insert new {key, value} at end.
        - If not and cache is full:
            • Remove front element (LRU).
        - Then add new {key, value} pair at end (MRU).
    */
    void put(int key, int value) {
        // Step 1: If key already exists, update it
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                // Remove old entry
                cache.erase(cache.begin() + i);
                // Insert updated key-value at the end (MRU)
                cache.push_back({key, value});
                return;
            }
        }

        // Step 2: If cache is full, remove LRU (front element)
        if (cache.size() == n) {
            cache.erase(cache.begin()); // remove the least recently used
        }

        // Step 3: Insert new {key, value} at end (MRU)
        cache.push_back({key, value});
    }
};

/*
    🧩 Example Usage:

    int main() {
        LRUCache lru(2); // cache capacity = 2

        lru.put(1, 10); // cache = [(1,10)]
        lru.put(2, 20); // cache = [(1,10), (2,20)]

        cout << lru.get(1) << endl; // Output: 10
        // cache after get(1) = [(2,20), (1,10)]  → 1 becomes MRU

        lru.put(3, 30); // cache full → removes (2,20)
        // cache = [(1,10), (3,30)]

        cout << lru.get(2) << endl; // Output: -1 (2 removed earlier)
        cout << lru.get(3) << endl; // Output: 30

        return 0;
    }

    ✅ Output:
    10
    -1
    30
*/

/*
    ⚡ Complexity Analysis:
    - get() → O(n) because we search linearly in vector.
    - put() → O(n) because we may erase or search linearly.
    - Space → O(n) for storing up to 'capacity' elements.

    ⚠️ Note:
    This vector-based version is simple and great for learning,
    but not optimal for large capacity caches.
    The efficient version (O(1)) uses:
      → unordered_map + list (doubly linked list)
    to track order and values.
*/


// 2. Approach is the optimized one using deque and unordered_map
// This approach gives the O(1) time complexity for both get and put operations

#include <iostream>
#include <list>
#include <map>
using namespace std;

/*
    ⚙️ LRUCache Implementation (O(1) using list + map)

    🔹 Components:
      1. list<int> dll → stores keys in order of usage
         - front = most recently used (MRU)
         - back  = least recently used (LRU)

      2. map<int, pair<list<int>::iterator, int>> mp
         - maps key → {iterator in dll, value}

    🔹 Goal:
      - get(key): return value if key exists; move it to front (MRU)
      - put(key, value): insert/update value; if full, evict LRU key
*/

class LRUCache {
public:
    list<int> dll; // stores keys (front = MRU, back = LRU)
    map<int, pair<list<int>::iterator, int>> mp; // key → {iterator in list, value}
    int capacity;  // maximum allowed size

    // Constructor to set cache capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    /*
        🔹 Helper: move the given key to front (mark as most recently used)
        Steps:
        1. Erase key's current position from the list.
        2. Push it to the front (MRU).
        3. Update its iterator in the map.
    */
    void moveToFront(int key) {
        dll.erase(mp[key].first);   // remove from old position
        dll.push_front(key);        // move to front (most recently used)
        mp[key].first = dll.begin(); // update iterator in map
    }
    
    /*
        🔹 get(key):
        - If key not found → return -1.
        - If found:
            1. Move it to front (MRU)
            2. Return its value
    */
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; // key not found
        }
        moveToFront(key);           // mark as recently used
        return mp[key].second;      // return stored value
    }

    /*
        🔹 put(key, value):
        1. If key exists:
            • Update its value.
            • Move it to front (MRU).
        2. If key doesn’t exist:
            • If cache is full, evict least recently used (back of list).
            • Insert new key at front.
            • Add to map with iterator and value.
    */
    void put(int key, int value) {
        // Case 1: Key already exists → update + move to front
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            moveToFront(key);
            return;
        }

        // Case 2: If cache full → remove LRU (back)
        if (dll.size() == capacity) {
            int lruKey = dll.back();  // key to be deleted
            dll.pop_back();           // remove from list
            mp.erase(lruKey);         // remove from map
        }

        // Case 3: Insert new key at front (MRU)
        dll.push_front(key);
        mp[key] = {dll.begin(), value};
    }
};

/*
    🧩 Example Usage:

    int main() {
        LRUCache lru(2); // Cache capacity = 2

        lru.put(1, 10); // cache = [1]
        lru.put(2, 20); // cache = [2, 1]
        cout << lru.get(1) << endl; // Output: 10 → cache = [1, 2]

        lru.put(3, 30); // Cache full → evicts 2 → cache = [3, 1]

        cout << lru.get(2) << endl; // Output: -1 (2 was evicted)
        cout << lru.get(3) << endl; // Output: 30
        cout << lru.get(1) << endl; // Output: 10

        return 0;
    }

    ✅ Output:
    10
    -1
    30
    10
*/

/*
    ⚡ Complexity Analysis:
    - get() → O(1)
    - put() → O(1)
    - Space → O(capacity)

    📘 Summary:
    - list maintains usage order (MRU ↔ LRU)
    - map provides O(1) lookup of key and its list iterator
    - Together they form an efficient LRU cache
*/
