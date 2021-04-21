
#ifndef dshashtable_h
#define dshashtable_h

#include <vector>
#include <iostream>
#include <algorithm>

#define DEBUG true
#define DEBUG2 true

template <typename K, typename V>
class hash_table {

private:
  struct Entry {
    K key;
    V value;
    Entry(K k, V v):key(k), value(v) {}
  };

  std::vector<Entry>* table = nullptr;
  int num_elements = 0;
  int table_size = 0;
public:
  hash_table() {
    table_size = 100;
    table = new std::vector<Entry>[table_size];
  }

  void insert(const K& theKey, const V& theValue){
    Entry e(theKey, theValue);
    auto hash_value = std::hash<K>{}(theKey);
    int location = hash_value % table_size;
    if(DEBUG) std::cout << theKey << ": " 
                        << hash_value << std::endl;
    table[location].push_back(e);
  }

  V& get_value(const K& theKey){
    auto location = std::hash<K>{}(theKey) % table_size;
    for(auto &c : table[location]) {
      if(c.key == theKey)
        return c.value;
    }
  }

};

#endif