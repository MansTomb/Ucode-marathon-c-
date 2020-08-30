#include <string>
#include "src/String.h"
#include "src/WString.h"
#include <vector>
#include <string>

using namespace CBL;

void CheckConstructors() {
    String s;
    String s1("stroka");
    String s2(s1);
    String s3(s1, 2);
    String s4(4, 'c');
    String s5(s1.begin(), s1.end());
    std::cout << "s1: " << s1.c_str() << " length: " << s1.length() << std::endl;
    std::cout << "s2: " << s2.c_str() << " length: " << s2.length() << std::endl;
    std::cout << "s3: " << s3.c_str() << " length: " << s3.length() << std::endl;
    std::cout << "s4: " << s4.c_str() << " length: " << s4.length() << std::endl;
    std::cout << "s5: " << s5.c_str() << " length: " << s5.length() << std::endl;
}

void CheckElementAccsess() {
    String s("Abcdefg");

    std::cout << "Length: " << s.length() << std::endl;
    std::cout << "1 char of: " << s.c_str() << " = " << s[0] << std::endl;
    std::cout << "3 char of: " << s.c_str() << " = " << s.at(2) << std::endl;
    std::cout << "front of: " << s.c_str() << " = " << s.front() << std::endl;
    std::cout << "back of: " << s.c_str() << " = " << s.back() << std::endl;
    try {
        std::cout << "at 123123 of: " << s.c_str() << " = " << s.at(123123) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void CheckModifiers() {
    {
        String s1("Privet");
        String s2 = s1;
        std::cout << "s1(Privet) = s2(" << s2.c_str() << ")" << std::endl;
    }
    {
        const char *ptr = "Prikol";
        String s2;
        s2 = ptr;
        std::cout << "Prikol = s2(" << s2.c_str() << ")" << std::endl;
    }
    {
        String s2;
        s2 = 'a';
        std::cout << "A = s2(" << s2.c_str() << ")" << std::endl;
    }
    {
        String s1("Privet");
        String s2;
        s2 += s1;
        std::cout << "+=: " << "s1(Privet) = s2(" << s2.c_str() << ")" << std::endl;
    }
    {
        const char *ptr = "Prikol";
        String s2;
        s2 += ptr;
        std::cout << "+=: " << "Prikol = s2(" << s2.c_str() << ")" << std::endl;
    }
    {
        String s2;
        s2 += 'a';
        std::cout << "+=: " << "A = s2(" << s2.c_str() << ")" << std::endl;
    }
    {
        String s1("Privet");
        String s2("Poka");
        std::cout << "Swap: s1:" << s1.c_str() << " s2:" << s2.c_str() << std::endl;
        s1.swap(s2);
        std::cout << "After Swap: s1:" << s1.c_str() << " s2:" << s2.c_str() << std::endl;
    }
}

void StringOperations() {
    {
        String s1("Privet");
        String s2("Privet");

        std::cout << "Compare: (Privet == Privet) == " << !s1.compare(s2) << std::endl;
    }
    {
        String s1("Privet");
        String s2("Prive");

        std::cout << "Compare: (Privet == Prive) == " << !s1.compare(s2) << std::endl;
    }
}

void StringFind() {
    String s("This is a string");

    std::cout << "find T in: " << s.c_str() << " == " << s.find('T') << std::endl;
    std::cout << "find i in: " << s.c_str() << " from 4 == " << s.find('i', 4) << std::endl;
    std::cout << "find t in: " << s.c_str() << " == " << s.find('t') << std::endl;
    std::cout << "R FIND" << std::endl;
    std::cout << "find T in: " << s.c_str() << " == " << s.rfind('T', 5) << std::endl;
    std::cout << "find i in: " << s.c_str() << " from 4 == " << s.rfind('i', 4) << std::endl;
    std::cout << "find t in: " << s.c_str() << " == " << s.rfind('t', 12) << std::endl;
}

int main(int argc, char *argv[]) {
    CheckConstructors();
    std::cout << "==================================" << std::endl;
    CheckElementAccsess();
    std::cout << "==================================" << std::endl;
    CheckModifiers();
    std::cout << "==================================" << std::endl;
    StringOperations();
    std::cout << "==================================" << std::endl;
    StringFind();
    return 0;
}
