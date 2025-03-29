#pragma once

template<typename TKey, typename TValue>
struct TKeyValuePair
{
    TKey key;
    TValue value;

    TKeyValuePair() = default;

    bool operator <(const TKeyValuePair& other) const;
};

template<typename TKey, typename TValue>
bool TKeyValuePair<TKey, TValue>::operator <(const TKeyValuePair& other) const {
        return this->key < other.key;
}
