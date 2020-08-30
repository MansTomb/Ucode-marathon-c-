#pragma once

#include <iostream>
#include <utility>
#include <cstring>

namespace CBL {
template<class T>
class BasicString {
 public:
    using iterator = T *;
    static const size_t npos = -1ul;
    BasicString() : m_size(0), m_buffer(new T[0]) {}
    BasicString(const BasicString<T> &str) : m_size(str.m_size) {
        m_buffer = new T[m_size + 1];
        std::copy(str.m_buffer, str.m_buffer + str.m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(const BasicString<T> &str, size_t pos, size_t len = npos) : m_size(str.m_size - pos) {
        m_buffer = new T[m_size - pos + 1];
        std::copy(str.m_buffer + pos, str.m_buffer + str.m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    explicit BasicString(const T *str) : m_size(std::char_traits<T>::length(str)){
        m_buffer = new T[m_size + 1];
        std::copy(str, str + m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(const T *str, size_t n) : m_size(n) {
        m_buffer = new T[m_size + 1];
        std::copy(str, str + m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(size_t n, T c) : m_size(n) {
        m_buffer = new T[m_size + 1];
        memset(m_buffer, c, m_size);
        m_buffer[m_size] = '\0';
    }
    BasicString(iterator first, iterator last) {
        m_size = std::distance(first, last);
        m_buffer = new T[m_size + 1];
        auto it = first;
        for (size_t i = 0; i < m_size && it != last; ++i, ++it) {
            m_buffer[i] = *it;
        }
        m_buffer[m_size] = '\0';
    }
    virtual~BasicString() {
        delete[] m_buffer;
    }

    iterator begin() const {
        return &(*m_buffer);
    }
    iterator end() const {
        return &(*(m_buffer + m_size));
    }

    size_t length() const {
        return m_size;
    }

    T& operator[](size_t index) const {
        return m_buffer[index];
    }
    T& at(size_t index) const {
        if (index >= 0 && index < m_size)
            return m_buffer[index];
        else
            throw std::out_of_range("BasicString: out of range");
    }
    T& back() const {
        return m_buffer[m_size - 1];
    }
    T& front() const {
        return m_buffer[0];
    }

    BasicString<T>& operator=(const BasicString<T>& str) {
        delete[] m_buffer;
        m_size = str.m_size;
        m_buffer = new T[m_size + 1];
        std::copy(str.m_buffer, str.m_buffer + str.m_size, m_buffer);
        m_buffer[m_size] = '\0';
        return *this;
    }
    BasicString<T>& operator=(const T* str) {
        delete[] m_buffer;
        m_size = std::char_traits<T>::length(str);
        m_buffer = new T[m_size + 1];
        std::copy(str, str + m_size, m_buffer);
        m_buffer[m_size] = '\0';
        return *this;
    }
    BasicString<T>& operator=(const T c) {
        delete[] m_buffer;
        m_size = 1;
        m_buffer = new T[m_size + 1];
        memset(m_buffer, c, 1);
        m_buffer[m_size] = '\0';
        return *this;
    }

    BasicString<T>& operator+=(const BasicString<T>& str) {
        this->append(str);
        return *this;
    }
    BasicString<T>& operator+=(const T* str) {
        this->append(str);
        return *this;
    }
    BasicString<T>& operator+=(const T c) {
        this->append(1, c);
        return *this;
    }

    void append(const BasicString<T>& str) {
        T* ptr = new T[m_size + str.m_size + 1];
        std::copy(m_buffer, m_buffer + m_size, ptr);
        std::copy(str.m_buffer, str.m_buffer + str.m_size, ptr + m_size);
        delete[] m_buffer;
        m_size += str.m_size;
        m_buffer = ptr;
        m_buffer[m_size] = '\0';
    }
    void append(const T* str) {
        T* ptr = new T[m_size + std::char_traits<T>::length(str) + 1];
        std::copy(m_buffer, m_buffer + m_size, ptr);
        std::copy(str, str + std::char_traits<T>::length(str), ptr + m_size);
        delete[] m_buffer;
        m_size += std::char_traits<T>::length(str);
        m_buffer = ptr;
        m_buffer[m_size] = '\0';
    }
    void append(const T* str, size_t n) {
        T* ptr = new T[m_size + n + 1];
        std::copy(m_buffer, m_buffer + m_size, ptr);
        std::copy(str, str + n, ptr + m_size);
        delete[] m_buffer;
        m_size += n;
        m_buffer = ptr;
        m_buffer[m_size] = '\0';
    }
    void append(size_t n, T c) {
        T* ptr = new T[m_size + n + 1];
        std::copy(m_buffer, m_buffer + m_size, ptr);
        delete[] m_buffer;
        m_buffer = ptr;
        memset(ptr + m_size, c, n);
        m_size += n;
        m_buffer[m_size] = '\0';
    }
    void append(iterator first, iterator last) {
        T* ptr = new T[m_size + std::distance(first, last) + 1];
        std::copy(m_buffer, m_buffer + m_size, ptr);
        std::copy(first, last, ptr + m_size);
        delete[] m_buffer;
        m_size += std::distance(first, last);
        m_buffer = ptr;
        m_buffer[m_size] = '\0';
    }

    void swap(BasicString<T>& str) {
        std::swap(m_buffer, str.m_buffer);
    }

    const T* c_str() const {
        return m_buffer;
    }
    virtual int compare(const BasicString<T>& str) const {
        return std::char_traits<T>::compare(m_buffer, str.m_buffer, m_size);
    }
    virtual int compare(const T* str) {
        return std::char_traits<T>::compare(m_buffer, str, m_size);
    }
 protected:
    size_t m_size{0};
    T* m_buffer{nullptr};
};
}

template<class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return lhs += rhs;
}
template<class T>
CBL::BasicString<T> operator+(const T* lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}
template<class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T* rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}
template<class T>
CBL::BasicString<T> operator+(const T lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}
template<class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}
template<class T>
bool operator==(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !lhs.compare(rhs);
}
template<class T>
bool operator==(const T* lhs, const CBL::BasicString<T>& rhs) {
    rhs.compare(lhs);
}
template<class T>
bool operator==(const CBL::BasicString<T>& lhs, const T* rhs) {
    return lhs.compare(rhs);
}
template<class T>
bool operator!=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}
template<class T>
bool operator!=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}
template<class T>
bool operator!=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs == rhs);
}
template<class T>
bool operator<(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template<class T>
bool operator<(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !std::lexicographical_compare(lhs, lhs + strlen(lhs), rhs.begin(), rhs.end());
}
template<class T>
bool operator<(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !std::lexicographical_compare(lhs, lhs + strlen(lhs), rhs, rhs + strlen(rhs));
}
template<class T>
bool operator<=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return lhs < rhs || lhs == rhs;
}
template<class T>
bool operator<=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return lhs < rhs || lhs == rhs;
}
template<class T>
bool operator<=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return lhs < rhs || lhs == rhs;
}
template<class T>
bool operator>(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs || lhs == rhs);
}
template<class T>
bool operator>(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs || lhs == rhs);
}
template<class T>
bool operator>(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs < rhs || lhs == rhs);
}
template<class T>
bool operator>=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}
template<class T>
bool operator>=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}
template<class T>
bool operator>=(const CBL::BasicString<T>& lhs, const T*  rhs) {
    return !(lhs < rhs);
}
