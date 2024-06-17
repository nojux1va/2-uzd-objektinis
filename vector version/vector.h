#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>
#include <limits>
#include <initializer_list>

template <typename T>
class Vector {
private:
    T* data = nullptr;
    size_t capacity_ = 0;
    size_t length = 0;
    size_t reallocations;

public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;

    // Constructor
    Vector() : data(nullptr), capacity_(0), length(0) {}

    Vector(std::initializer_list<T> init) : data(nullptr), capacity_(0), length(0) {
        reserve(init.size());
        for (const T& value : init) {
            push_back(value);
        }
    }

    // Copy constructor
    Vector(const Vector& other) : data(nullptr), capacity_(0), length(0) {
        reserve(other.length);
        for (size_t i = 0; i < other.length; ++i) {
            push_back(other.data[i]);
        }
    }

    // Move constructor
    Vector(Vector&& other) noexcept : data(other.data), capacity_(other.capacity_), length(other.length) {
        other.data = nullptr;
        other.capacity_ = 0;
        other.length = 0;
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            data = nullptr;
            capacity_ = 0;
            length = 0;
            reserve(other.length);
            for (size_t i = 0; i < other.length; ++i) {
                push_back(other.data[i]);
            }
        }
        return *this;
    }

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            capacity_ = other.capacity_;
            length = other.length;
            other.data = nullptr;
            other.capacity_ = 0;
            other.length = 0;
        }
        return *this;
    }

    size_t size() const {
        return length;
    }

    size_t max_size() const {
        return std::numeric_limits<size_t>::max() / sizeof(T);
    }

    size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return length == 0;
    }

    void reserve(size_t new_capacity) {
            if (new_capacity <= capacity_) {
                return;
            }
            ++reallocations; // Increment reallocations count
            T* new_data = new T[new_capacity];
            std::copy(data, data + length, new_data);
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        }

    void resize(size_t new_size, const T& value = T()) {
        if (new_size > length) {
            reserve(new_size);
            std::fill(data + length, data + new_size, value);
        }
        length = new_size;
    }

    void shrink_to_fit() {
        if (length < capacity_) {
            T* new_data = new T[length];
            std::copy(data, data + length, new_data);
            delete[] data;
            data = new_data;
            capacity_ = length;
        }
    }

    // Element access
    reference operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const_reference operator[](size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    reference at(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const_reference at(size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    reference front() {
        if (length == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }

    const_reference front() const {
        if (length == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }

    reference back() {
        if (length == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[length - 1];
    }

    const_reference back() const {
        if (length == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[length - 1];
    }

    // Modifiers
    void push_back(const T& value) {
        if (length >= capacity_) {
            reserve((capacity_ == 0) ? 1 : capacity_ * 2);
        }
        data[length++] = value;
    }

    void pop_back() {
        if (length == 0) {
            throw std::out_of_range("Vector is empty");
        }
        --length;
    }

    iterator erase(iterator position) {
        if (position < data || position >= data + length) {
            throw std::out_of_range("Iterator out of range");
        }
        std::copy(position + 1, data + length, position);
        --length;
        return position;
    }

    iterator erase(iterator first, iterator last) {
        if (first < data || first >= data + length || last < data || last > data + length || first > last) {
            throw std::out_of_range("Iterator out of range");
        }
        std::copy(last, data + length, first);
        length -= last - first;
        return first;
    }

    void clear() {
        length = 0;
    }

    // Iterators
    iterator begin() {
        return data;
    }

    const_iterator begin() const {
        return data;
    }

    iterator end() {
        return data + length;
    }

    const_iterator end() const {
        return data + length;
    }

    Vector(T* data, const size_t& capacity_, const size_t& length)
        : data(data), capacity_(capacity_), length(length)
    {
    }

    bool operator==(const Vector& other) const
    {
        return false;
    }

    // Function to get the number of reallocations
    size_t getReallocationCount() const {
        return reallocations;
    }
};

#endif // VECTOR_H