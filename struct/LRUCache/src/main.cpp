#include <string>
#include <iostream>

#include "LRUCache.h"

int main() {
    LRUCache<int, std::string> lru(10);

    lru.insert(1, "one");
    lru.insert(2, "two");
    lru.insert(3, "three");

    for (auto value : lru) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;

    std::cout << "key 2: value: " << *lru.get(2) << std::endl;

    for (auto value : lru) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}