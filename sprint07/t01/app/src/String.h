#pragma once

#include "BasicString.h"

class String : public CBL::BasicString<char> {
 public:
    using CBL::BasicString<char>::operator=;
    String() : CBL::BasicString<char>() {}
    String(const String& str) : CBL::BasicString<char>(str) {}
    String(const String& str, size_t pos, size_t len = npos) : CBL::BasicString<char>(str, pos, npos) {}
    explicit String(const char *str) : CBL::BasicString<char>(str) {}
    String(const char *str, size_t n) : CBL::BasicString<char>(str, n) {}
    String(size_t n, char c) : CBL::BasicString<char>(n, c) {}
    String(iterator first, iterator last) : CBL::BasicString<char>(first, last) {}
    size_t find(const String& str, size_t pos = 0) const {
        if (pos > m_size)
            return npos;
        for (size_t i = pos; i < m_size; ++i)
            if (strncmp(m_buffer + i, str.c_str(), str.length()) == 0)
            return i;
        return npos;
    }
    size_t find(const String* str, size_t pos = 0) const {
        if (str != nullptr)
            return find(*str, pos);
        return npos;
    }
    size_t find(char c, size_t pos= 0) const {
        if (pos > m_size)
            return npos;
        for (size_t i = pos; i < m_size; ++i)
            if (m_buffer[i] == c)
                return i;
        return npos;
    }

    size_t rfind(const String& str, size_t pos = 0) const {
        if (pos > m_size)
            return npos;
        for (size_t i = pos; i > 0; ++i)
            if (strncmp(m_buffer + i, str.c_str(), str.length()) == 0)
                return i;
        return npos;
    }
    size_t rfind(const String* str, size_t pos = 0) const {
        if (str != nullptr)
            return rfind(*str, pos);
        return npos;
    }
    size_t rfind(char c, size_t pos = 0) const {
        if (pos > m_size || pos < 0)
            return npos;
        for (size_t i = pos; i >= 0; --i) {
            if (m_buffer[i] == c)
                return i;
        }
        return npos;
    }
    int compare(const BasicString<char> &str) const override {
        return strcmp(m_buffer, str.c_str());
    }
    int compare(const char *str) override {
        return strcmp(m_buffer, str);
    }
};

