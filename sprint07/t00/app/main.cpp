#include <string>
#include "src/Vector.h"
#include <vector>
#include <cassert>

using namespace CBL;

class Test {
    Test() = delete;
 public:
    Test(int a, double b) {};
};

template<typename T>
void Print(T &container) {
    for (const auto &item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

static bool CheckConstructors() {
    {
        Vector<int> v = {1, 2, 3};
        Vector<int> v1({1, 2, 3});
    }
    {
        Vector<int> v(4);
    }
    {
        Vector<int> v(10, 2);
    }
    {
        Vector<int> v = {1, 2, 3};
        Vector<int> v1(v);
        Vector<int> v2(v.begin(), v.end());
    }
    return true;
}

static bool CheckOperators() {
    {
        Vector<std::string> v(2, "alice");
        Vector<std::string> v1(1, "bob returns");
        std::cout << "OPERATION CHECK" << std::endl;
        std::cout << (v < v1) << std::endl;
        std::cout << "OPERATION CHECK END" << std::endl;
    }
    return true;
}

static bool EraseCheck() {
    {
        std::cout << "ERASE CHECK" << std::endl;
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        std::cout << *v.erase(v.begin(), v.end() - 1) << std::endl;
        Print(v);
        std::cout << "=====================" << std::endl;
        std::cout << *s.erase(s.begin(), s.end() - 1) << std::endl;
        Print(s);
        std::cout << "ERASE CHECK END" << std::endl;
    }
    return true;
}

static bool ClearCheck() {
    {
        std::cout << "CLEAR CHECK" << std::endl;
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        v.clear();
        s.clear();
        std::cout << v.size() << " " << v.capacity() << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << s.size() << " " << s.capacity() << std::endl;
        std::cout << "CLEAR CHECK END" << std::endl;
    }
    return true;
}

static bool PushCheck() {
    {
        std::cout << "PUSH CHECK" << std::endl;
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        s.push_back(1);
        s.push_back(2);
        s.push_back(3);
        Print(v);
        std::cout << "================================" << std::endl;
        Print(s);
        std::cout << "PUSH CHECK END" << std::endl;
    }
    return true;
}

static bool PopCheck() {
    {
        std::cout << "POP CHECK" << std::endl;
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        v.pop_back();
        v.pop_back();
        s.pop_back();
        s.pop_back();
        Print(v);
        std::cout << "================================" << std::endl;
        Print(s);
        std::cout << "POP CHECK END" << std::endl;
    }
    return true;
}

static bool AccsessCheck() {
    {
        std::cout << "ACCSESS CHECK" << std::endl;
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        std::cout << "1:" << v[0] << " 2:" << v.at(1) << std::endl;
        v[0] = 11; v.at(1) = 22;
        std::cout << "1:" << v[0] << " 2:" << v.at(1) << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "1:" << s[0] << " 2:" << s.at(1) << std::endl;
        s[0] = 11; s.at(1) = 22;
        std::cout << "1:" << s[0] << " 2:" << s.at(1) << std::endl;

    }
    {
        std::cout << "CHECK AT EXCEPTION" << std::endl;
        try {
            Vector<int> v({1, 2, 3});
            v.at(123);
        }
        catch (std::exception&e ) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "ACCSESS CHECK END" << std::endl;
    return true;
}

static bool EmptyCheck() {
    {
        std::cout << "EMPTY CHECK" << std::endl;
        Vector<int> v;
        std::vector<int> s;
        std::cout << v.isEmpty() << v.size() << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << s.empty() << s.size() << std::endl;
        std::cout << "EMPTY CHECK END" << std::endl;
    }
    return true;
}

bool ReserveCheck() {
    {
        std::cout << "RESERVE CHECK" << std::endl;
        Vector<int> v;
        std::vector<int> s;
        v.reserve(10);
        s.reserve(10);
        std::cout << v.capacity() << " " << v.size() << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << s.capacity() << " " << s.size() << std::endl;
        std::cout << "RESERVE CHECK END" << std::endl;
    }
    return true;
}

bool ResizeCheck() {
    {
        std::cout << "RESIZE CHECK" << std::endl;
        Vector<int> v;
        std::vector<int> s;
        v.resize(10);
        s.resize(10);
        std::cout << v.capacity() << " " << v.size() << std::endl;
        Print(v);
        std::cout << "================================" << std::endl;
        std::cout << s.capacity() << " " << s.size() << std::endl;
        Print(s);
        std::cout << "RESIZE CHECK END" << std::endl;
    }
    return true;
}

static bool InsertCheck() {
    {
        std::cout << "INSERT CHECK" << std::endl;
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        v.insert(v.begin(), 11);
        v.insert(v.begin() + 2, 22);
        v.insert(v.begin() + 4, 44);
        s.insert(s.begin(), 11);
        s.insert(s.begin() + 2, 22);
        s.insert(s.begin() + 4, 44);
        Print(v);
        std::cout << "================================" << std::endl;
        Print(s);
        std::cout << "INSERT CHECK END" << std::endl;
    }
    return true;
}

int main(int argc, char *argv[]) {
    CheckConstructors();
    CheckOperators();
    EraseCheck();
    ClearCheck();
    PushCheck();
    InsertCheck();
    PopCheck();
    AccsessCheck();
    EmptyCheck();
    ReserveCheck();
    ResizeCheck();
    return 0;
}
