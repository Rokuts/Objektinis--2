#include "vektorius.h"

template <typename T>
void Vektorius<T>::ensure_capacity(size_t min_capacity)
{   
    if (capacity_ >= min_capacity) return;
    size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
    while (new_capacity < min_capacity) {
        new_capacity *= 2;
    }
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

template <typename T>
inline Vektorius<T>::Vektorius()
    : data_(nullptr), size_(0), capacity_(0) {}

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
    delete[] data_;
}

template <typename T>
void Vektorius<T>::push_back(const T &value)
{
    ensure_capacity(size_ + 1);
    data_[size_] = value;
   
}

template <typename T>
void Vektorius<T>::pop_back()
{
    if (size_ == 0) throw std::out_of_range("Vektorius is empty");
    --size_;
}

template <typename T>
T &Vektorius<T>::operator[](size_t idx)
{  
    return data_[idx];
}

template <typename T>
const T &Vektorius<T>::operator[](size_t idx) const
{
    return data_[idx];
}

template <typename T>
T &Vektorius<T>::at(size_t idx)
{
    if (idx >= size_) throw std::out_of_range("Index out of range");
    return data_[idx];
}

template <typename T>
const T &Vektorius<T>::at(size_t idx) const
{
    if (idx >= size_) throw std::out_of_range("Index out of range");
    return data_[idx];
}

template <typename T>
size_t Vektorius<T>::size() const
{
    return size_;
}

template <typename T>
size_t Vektorius<T>::capacity() const
{
    return capacity_;
}

template <typename T>
bool Vektorius<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
void Vektorius<T>::clear()
{
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;

}

template <typename T>
T *Vektorius<T>::begin()
{
    return data_;
}

template <typename T>
const T *Vektorius<T>::begin() const
{
    return data_;
}

template <typename T>
T *Vektorius<T>::end()
{
    return data_ + size_;
}

template <typename T>
const T *Vektorius<T>::end() const
{
    return data_ + size_;
}

