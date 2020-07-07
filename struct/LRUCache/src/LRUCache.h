#include <cstddef>
#include <list>
#include <unordered_map>

template <typename K, typename V>
class LRUCache
{
public:
   
    typedef typename std::list<V>::iterator Iterator;

    LRUCache(size_t maxSize)
        : m_maxSize(maxSize) {}

    void insert(const K &key, const V &value)
    {
        if (auto it = m_access.find(key); it != m_access.end())
        {
            m_values.erase(it->second);
        }
        m_values.push_front(value);
        m_access.insert({key, m_values.begin()});
    }

    Iterator get(const K &key)
    {
        if (auto it = m_access.find(key); it != m_access.end())
        {
            auto value = *it->second;
            m_values.erase(it->second);
            m_values.push_front(value);
            m_access[key] = m_values.begin();
            return m_values.begin();
        }
        return m_values.end();
    }

    Iterator begin()
    {
        return m_values.begin();
    }

    Iterator end()
    {
        return m_values.end();
    }

private:
    const size_t m_maxSize;
    // most recent elements at front
    std::list<V> m_values;
    std::unordered_map<K, Iterator> m_access;
};
