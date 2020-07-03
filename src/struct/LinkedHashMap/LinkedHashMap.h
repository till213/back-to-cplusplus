#pragma once

#include <list>
#include <unordered_map>
using namespace std;

/*!
 * A hashmap which keeps track of the insertion order.
 */
template <class K, class V>
class LinkedHashMap
{

public:
    LinkedHashMap(){};
    ~LinkedHashMap(){};

    /**
     * Iterator for the LinkedHashMap collection.
     */
    typedef typename list<V>::const_iterator Iterator;

    /**
     * Inserts the \c value associated with \c key.
     */
    void insert(const K &key, const V &value)
    {
        auto it = m_access.find(key);
        if (it != m_access.end())
        {
            m_values.erase(it->second);
        }
        m_values.push_front(value);
        m_access.insert(make_pair(key, m_values.begin()));
    }

    /**
     * Returns the #Iterator pointing to the value 
     * associated with \c key.
     * 
     * @param key
     *        the key of the value
     * @return an #Iterator pointing to the value,
     *         or #end() if value does not exist
     */
    Iterator get(const K &key) const
    {
        const auto it = m_access.find(key);
        if (it != m_access.end())
        {
            return it->second;
        }
        return m_values.end();
    }

    /**
     * Returns whether a value associated with \c key exists in the collection.
     * 
     * @param key
     *        the key of the value
     * @return \c true if the value exists; \c false else
     */
    bool contains(const K &key) const
    {
        return m_access.find(key) != m_access.cend();
    }

    /**
     * Removes the value associated with \c key from the collection.
     * 
     * @param key
     *        the key of the value to be removed
     */
    void remove(const K &key)
    {
        auto it = m_access.find(key);
        if (it != m_access.end()) {
            m_values.erase(it->second);
            m_access.erase(it);
        }
    }

    /**
     * Returns the begin #Iterator.
     * 
     * @see end()
     * @return the #Iterator which points to the first element
     */
    Iterator begin() const {
        return m_values.begin();
    }

    /**
     * Returns the end #Iterator.
     * 
     * @return the #Iterator which points one past the last element
     */
    Iterator end() const {
        return m_values.end();
    }

    /**
     * Returns the constant begin #Iterator.
     * 
     * @see cend()
     * @return the constant #Iterator which points to the first element
     */
    Iterator cbegin() const {
        return m_values.cbegin();
    }

    /**
     * Returns the constant end #Iterator.
     * 
     * @return the constant #Iterator which points one past the last element
     */
    Iterator cend() const {
        return m_values.cend();
    }

private:
    list<V> m_values;
    unordered_map<K, Iterator> m_access;
};