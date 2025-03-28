#pragma once

template<typename TKey, typename TValue>
struct TKeyValuePair
{
    TKey key;
    TValue value;

    TKeyValuePair();

    bool operator <(const TKeyValuePair& other) const;
};

template<typename TKey, typename TValue>
TKeyValuePair<TKey, TValue>::TKeyValuePair() {
        std::cout << "pair constructor" << std::endl;
}

template<typename TKey, typename TValue>
bool TKeyValuePair<TKey, TValue>::operator <(const TKeyValuePair& other) const {
        return this->key < other.key;
}
