#pragma once

#include "BasicString.h"

class WString : public CBL::BasicString<wchar_t> {
 public:
    using CBL::BasicString<wchar_t>::operator=;
    WString() : CBL::BasicString<wchar_t>() {}
    WString(const WString& str) : CBL::BasicString<wchar_t>(str) {}
    WString(const WString& str, size_t pos, size_t len = npos) : CBL::BasicString<wchar_t>(str, pos, npos) {}
    explicit WString(const wchar_t *str) : CBL::BasicString<wchar_t>(str) {}
    WString(const wchar_t *str, size_t n) : CBL::BasicString<wchar_t>(str, n) {}
    WString(size_t n, wchar_t c) : CBL::BasicString<wchar_t>(n, c) {}
    WString(iterator first, iterator last) : CBL::BasicString<wchar_t>(first, last) {}
    size_t find(const WString& str, size_t pos = 0) const {
        if (pos > m_size)
            return npos;
        for (size_t i = pos; i < m_size; ++i)
            if (wcsncmp(m_buffer + i, str.c_str(), str.length()) == 0)
                return i;
        return npos;
    }
    size_t find(const WString* str, size_t pos = 0) const {
        if (str != nullptr)
            return find(*str, pos);
        return npos;
    }
    size_t find(wchar_t c, size_t pos= 0) const {
        if (pos > m_size)
            return npos;
        for (size_t i = pos; i < m_size; ++i)
            if (m_buffer[i] == c)
                return i;
        return npos;
    }

    size_t rfind(const WString& str, size_t pos = 0) const {
        if (pos > m_size)
            return npos;
        for (int i = pos; i > 0; ++i)
            if (wcsncmp(m_buffer + i, str.c_str(), str.length()) == 0)
                return i;
        return npos;
    }
    size_t rfind(const WString* str, size_t pos = 0) const {
        if (str != nullptr)
            return rfind(*str, pos);
        return npos;
    }
    size_t rfind(wchar_t c, size_t pos= 0) const {
        if (pos > m_size && pos < 0)
            return npos;
        for (size_t i = pos; i >= 0; ++i)
            if (m_buffer[i] == c)
                return i;
        return npos;
    }

    int compare(const BasicString<wchar_t> &str) const override {
        return wcscmp(m_buffer, str.c_str());
    }
    int compare(const wchar_t *str) override {
        return wcscmp(m_buffer, str);
    }
};

