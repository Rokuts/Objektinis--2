#include "vektorius.h"

template <typename T>
inline Vektorius<T>::Vektorius()
{
}

template <typename T>
Vektorius<T>::Vektorius(size_t n, const T &value)
{
}

template <typename T>
Vektorius<T>::Vektorius(const Vektorius &other)
{
}

template <typename T>
Vektorius<T>::Vektorius(Vektorius &&other) noexcept
{
}

template <typename T>
Vektorius<T> &Vektorius<T>::operator=(const Vektorius<T> &other)
{
    // TODO: insert return statement here
}

template <typename T>
Vektorius<T> &Vektorius<T>::operator=(Vektorius<T> &&other) noexcept
{
    // TODO: insert return statement here
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

