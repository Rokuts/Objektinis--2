#pragma once
#include <cstddef>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Vektorius {
    T* data_;
    size_t size_;
    size_t capacity_;
public:
    Vektorius();
    Vektorius(size_t n, const T& value = T());
    Vektorius(const Vektorius& other);
    Vektorius(Vektorius&& other) noexcept;
    Vektorius& operator=(const Vektorius& other);
    Vektorius& operator=(Vektorius&& other) noexcept;
    ~Vektorius();

    void push_back(const T& value);
    void pop_back();
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
    T& at(size_t idx);
    const T& at(size_t idx) const;
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void clear();

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
    // ...pridėkite daugiau funkcijų pagal poreikį...
};

