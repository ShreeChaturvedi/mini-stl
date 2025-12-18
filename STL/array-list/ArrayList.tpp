#include "ArrayList.h"

#include <stdexcept>
#include <algorithm>

inline constexpr std::size_t DEFAULT_CAPACITY = 16;

template <typename T>
ArrayList<T>::ArrayList() : ArrayList(DEFAULT_CAPACITY) {}

template <typename T>
ArrayList<T>::ArrayList(std::size_t initial_capacity)
    : m_size(0), m_capacity(initial_capacity), m_array(new T[m_capacity]) {}

template <typename T>
ArrayList<T>::ArrayList(std::size_t length, T value)
    : m_size(length), m_capacity(length), m_array(new T[m_capacity]) {
    for (std::size_t pos = 0; pos < length; ++pos) m_array[pos] = value;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& other) : m_size(other.m_size),
    m_capacity(other.m_capacity) {
    m_array = new T[m_capacity];
    for (std::size_t pos = 0; pos < m_size; ++pos)
        m_array[pos] = other.m_array[pos];
}

template <typename T>
ArrayList<T>::ArrayList(ArrayList&& other) : m_size(other.m_size), 
    m_capacity(other.m_capacity) {
    m_array = other.m_array;
    
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_array = nullptr;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] m_array;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other) {
    if (this == &other) return *this;
    m_size = other.m_size;

    if (m_size > m_capacity) {
        T* new_array = new T[m_size];
        std::swap(m_array, new_array);
        // almost forgot but we don't do memory leaks around here :)
        delete[] new_array;
        m_capacity = m_size;
    }

    for (std::size_t pos = 0; pos < m_size; ++pos)
        m_array[pos] = other.m_array[pos];

    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList<T>&& other) noexcept {
    if (this == &other) return *this;

    delete[] m_array;

    m_array = other.m_array;
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    other.m_size = 0;
    other.m_capacity = 0;
    other.m_array = nullptr;

    return *this;
}

template <typename T>
void ArrayList<T>::add(const T& element) {
    ensureCapacity();
    m_array[m_size++] = element;
}

template <typename T>
T ArrayList<T>::remove(std::size_t index) {
    if (index >= m_size) 
        throw std::out_of_range("Index out of range");
    T element = m_array[index];
    --m_size;
    for (std::size_t pos = index; pos < m_size; ++pos)
        m_array[pos] = m_array[pos + 1];
    return element;
}

template <typename T>
void ArrayList<T>::insert(std::size_t index, T element) {
    if (index > m_size)
        throw std::out_of_range("Index out of range");
    ensureCapacity();
    ++m_size;
    for (std::size_t pos = m_size; pos > index; --pos)
        m_array[pos] = m_array[pos - 1];
    m_array[index] = element;
}

template <typename T>
T& ArrayList<T>::operator[](std::size_t index) {
    if (index >= m_size) 
        throw std::out_of_range("Index out of range");
    return m_array[index];
}

template <typename T>
const T& ArrayList<T>::operator[](std::size_t index) const {
    if (index >= m_size) 
        throw std::out_of_range("Index out of range");
    return m_array[index];
}

template <typename T>
void ArrayList<T>::reserve(std::size_t capacity) {
    if (m_capacity >= capacity) return;
    m_capacity = capacity;
    T* new_array = copyArray();
    std::swap(new_array, m_array);
    delete[] new_array;
}

template <typename T>
void ArrayList<T>::ensureCapacity() {
    if (m_size < m_capacity) return;
    m_capacity += m_capacity >> 1;
    T* new_array = copyArray();
    std::swap(new_array, m_array);
    delete[] new_array;
}

template <typename T>
T* ArrayList<T>::copyArray() {
    T* new_array = new T[m_capacity];
    for (std::size_t pos = 0; pos < m_size; ++pos)
        new_array[pos] = m_array[pos];
    return new_array;
}

template <typename T>
std::size_t ArrayList<T>::size() const noexcept {
    return m_size;
}
