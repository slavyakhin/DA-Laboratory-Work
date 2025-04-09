#pragma once

const int INIT_CAPACITY = 1;

template<typename T>
class TVector
{
private:
    int size;
    int capacity; // max_length before reallocate
    T* dataPtr;

public:
    // Constructors
    TVector();
    TVector(const int size);
    TVector(const int size, T initValue);

    TVector(const TVector& other);
    TVector& operator =(const TVector& other);

    TVector(TVector&& other);
    TVector& operator =(TVector&& other);

    // Destructor
    ~TVector();

    // RandomAccessIterator for std::stable_sort
    struct Iterator {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;


        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator* () const { return *m_ptr; }
        pointer operator-> () { return m_ptr; }

        Iterator& operator++ () { m_ptr++; return *this; }
        Iterator operator++ (int) { Iterator tmp = *this; ++(*this); return tmp; }

        Iterator& operator-- () { m_ptr--; return *this; }
        Iterator operator-- (int) { Iterator tmp = *this; --(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

        friend bool operator< (const Iterator& a, const Iterator& b) { return a.m_ptr < b.m_ptr; };
        friend bool operator> (const Iterator& a, const Iterator& b) { return a.m_ptr > b.m_ptr; };
        friend bool operator<= (const Iterator& a, const Iterator& b) { return a.m_ptr <= b.m_ptr; };
        friend bool operator>= (const Iterator& a, const Iterator& b) { return a.m_ptr >= b.m_ptr; };

        Iterator operator+ (const int n) const { Iterator result(m_ptr + n); return result; }
        Iterator& operator+= (const int n) { this->m_ptr += n; return *this; }
        Iterator operator- (const int n) const { Iterator result(m_ptr - n); return result; }
        Iterator& operator-= (const int n) { this->m_ptr -= n; return *this; }

        difference_type operator- (const Iterator& other) const { return m_ptr - other.m_ptr; }

        Iterator& operator[](difference_type n) const {Iterator result(m_ptr + n); return result; }

    private:
        pointer m_ptr;
    };

    Iterator begin() {
        return Iterator(&dataPtr[0]);
    }
    Iterator end() {
        return Iterator(&dataPtr[this->size]);
    }

    int Size(); // Returns length
    bool Empty(); // length == 0
    T& operator [](const int index);
    void PushBack(const T& element); // Returns 0 in case of failure
    T PopBack(); // Removes last element and returns it
};

template<typename T>
TVector<T>::TVector() {
    this->size = 0;
    this->capacity = INIT_CAPACITY;
    this->dataPtr = new T[INIT_CAPACITY];
}

template<typename T>
TVector<T>::TVector(const int size) {
    this->size = size;
    this->capacity = size;
    this->dataPtr = new T[size];;
}

template<typename T>
TVector<T>::TVector(const int size, T initValue) {
    this->dataPtr = new T[size];
    this->size = size;
    this->capacity = size;
    for (int i = 0; i < this->size; ++i) {
        this->dataPtr[i] = initValue;
    }
}

template<typename T>
TVector<T>::TVector(const TVector& other) {
    this->dataPtr = new T[other.size];
    this->size = other.size;
    this->capacity = other.capacity;
    for (int i = 0; i < this->size; ++i) {
        this->dataPtr[i] = other[i];
    }
}

template<typename T>
TVector<T>& TVector<T>::operator =(const TVector& other) {
    this->dataPtr = new T[other.size];
    this->size = other.size;
    this->capacity = other.capacity;
    for (int i = 0; i < this->size; ++i) {
        this->dataPtr[i] = other[i];
    }
    return *this;
}
//
template<typename T>
TVector<T>::TVector(TVector&& other) {
    this->dataPtr = other.dataPtr;
    this->size = other.size;
    this->capacity = other.capacity;

    other.dataPtr = new T[INIT_CAPACITY];
    other.size = 0;
    other.capacity = INIT_CAPACITY;
}

template<typename T>
TVector<T>& TVector<T>::operator =(TVector&& other) {
    if (this != &other) {
        delete[] this->dataPtr;
        
        this->dataPtr = other.dataPtr;
        this->size = other.size;
        this->capacity = other.capacity;
    
        other.dataPtr = new T[INIT_CAPACITY];
        other.size = 0;
        other.capacity = INIT_CAPACITY;
    }
    return *this;
}

template<typename T>
TVector<T>::~TVector() {
    delete[] this->dataPtr;
}

template<typename T>
int TVector<T>::Size() {
    return this->size;
}

template<typename T>
bool TVector<T>::Empty() {
    return this->size == 0;
}

template<typename T>
T& TVector<T>::operator [](const int index) {
    return this->dataPtr[index];
}

template<typename T>
void TVector<T>::PushBack(const T& element) {
    // Reallocate, double capacity
    if (this->size == this->capacity) {
        this->capacity *= 2;
        T* newDataPtr = new T[this->capacity];
        for (int i = 0; i < this->size; ++i) {
            newDataPtr[i] = this->dataPtr[i];
        }
        delete[] this->dataPtr;
        this->dataPtr = newDataPtr;
    }
    this->dataPtr[this->size] = element;
    ++(this->size);
}

template<typename T>
T TVector<T>::PopBack() {
    if (!this->Empty()) {
        return this->dataPtr[(this-size)--];
    }
}
