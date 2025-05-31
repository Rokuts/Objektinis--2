#include "vektorius.h"

template <typename T>
inline Vektorius<T>::Vektorius()
    :data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
Vektorius<T>::Vektorius(size_t n, const T &value)
    : data_(n ? new T[n] : nullptr), size_(n), capacity_(n) {
    std::fill(data_, data_ + n, value);
}

template <typename T>
Vektorius<T>::Vektorius(const Vektorius &other)
    : data_(other.size_ ? new T[other.size_] : nullptr), size_(other.size_), capacity_(other.size_) {
    std::copy(other.data_, other.data_ + other.size_, data_);
}

template <typename T>
Vektorius<T>::Vektorius(Vektorius &&other) noexcept
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

template <typename T>
Vektorius<T> &Vektorius<T>::operator=(const Vektorius<T> &other)
{
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.size_;
        data_ = size_ ? new T[size_] : nullptr;
        std::copy(other.data_, other.data_ + size_, data_);
    }
    return *this;
}

template <typename T>
Vektorius<T> &Vektorius<T>::operator=(Vektorius<T> &&other) noexcept
{
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

template <typename T>
Vektorius<T>::~Vektorius()
{
}

template <typename T>
void Vektorius<T>::push_back(const T &value)
{
}

template <typename T>
void Vektorius<T>::pop_back()
{
}

template <typename T>
T &Vektorius<T>::operator[](size_t idx)
{  
}

template <typename T>
const T &Vektorius<T>::operator[](size_t idx) const
{
}

template <typename T>
T &Vektorius<T>::at(size_t idx)
{
}

template <typename T>
const T &Vektorius<T>::at(size_t idx) const
{
}

template <typename T>
size_t Vektorius<T>::size() const
{
}

template <typename T>
size_t Vektorius<T>::capacity() const
{
}

template <typename T>
bool Vektorius<T>::empty() const
{
}

template <typename T>
void Vektorius<T>::clear()
{
}

template <typename T>
T *Vektorius<T>::begin()
{
}

template <typename T>
const T *Vektorius<T>::begin() const
{
}

template <typename T>
T *Vektorius<T>::end()
{
}

template <typename T>
const T *Vektorius<T>::end() const
{
}

