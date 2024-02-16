#include <cstring>
#include <iostream>
#include "../includes/string.h"
#include "../includes/myexception.h"

using utility::String;

// String Class implementation of all function definations
char& String::operator[](unsigned int index)
{
    try {
        if (index >= stringSize) {
            throw StringException("Error :: Invalid Index !!!\n");
        }
        return stringBuffer[index];
    }
    catch (StringException e) {
        e.what();
        char a{};
        return a;
    }
    
}

int String::length() {
    return stringSize;
}

void String::tolowercase() {
    for (unsigned int i = 0; i < stringSize; i++) {
        stringBuffer[i] = tolower(stringBuffer[i]);
    }
}

void String::touppercase() {
    for (unsigned int i = 0; i < stringSize; i++) {
        stringBuffer[i] = toupper(stringBuffer[i]);
    }
}

bool String::equal(const String& str) {

    if (stringSize != str.stringSize) {

        return false;
    }
    unsigned int i = 0;
    while (i < str.stringSize) {
        if (stringBuffer[i] != str.stringBuffer[i])
            return false;
        ++i;
    }
    return true;

}

String String::operator+(const String& str) {

    int len = stringSize + str.stringSize;

    auto concate = std::make_unique<char[]>(len + 1);

    memcpy(concate.get(), stringBuffer.get(), stringSize);
    memcpy(concate.get() + stringSize, str.stringBuffer.get(), str.stringSize);

    concate[len] = '\0';

    String ans{ concate.get() };

    return ans;
}

void String::subStr(unsigned int start, unsigned int end) {

    try {
        if (start >= 0 && end < stringSize && start < end) {

            auto size = ((end - start) + 1);
            auto substr = new char[size + 1];
            auto i = 0;
            while (start <= end) {

                substr[i] = stringBuffer[start];
                ++start;
                ++i;

            }
            substr[size] = '\0';
            std::cout << substr;
            delete[] substr;
        }
        else {
            throw StringException("Error :: Invalid Index!!!\n");
        }
    }
    catch (StringException e) {
        e.what();
    }

}


String String::intToString(int num) {

    auto temp{ num };
    auto count{ 0 };
    if (temp < 0) {
        ++count;
        temp = -temp;
    }
    while (temp > 0) {
        temp = temp / 10;
        count++;
    }

    auto* newBuffer = new char[count + 1];

    if (num < 0) {
        newBuffer[0] = '-';
        num = -num;
    }

    auto i{ count - 1 };
    while (num > 0) {
        newBuffer[i] = num % 10 + '0';
        num = num / 10;
        --i;
    }
    newBuffer[count] = '\0';


    String result{ newBuffer };

    delete[] newBuffer;

    return result;
}

std::ostream& utility::operator<<(std::ostream& stream, const String& string) {
    stream << string.stringBuffer;
    return stream;
}



//bool String::lessThan(const String& str) {
//    if (stringSize < str.stringSize)
//        return true;
//    return false;
//}
//bool String::lessThanequall(const String& str) {
//    if (stringSize <= str.stringSize)
//        return true;
//    return false;
//}
//bool String::greaterThan(const String& str) {
//    if (stringSize > str.stringSize)
//        return true;
//    return false;
//}
//bool String::greaterThanequall(const String& str) {
//    if (stringSize >= str.stringSize)
//        return true;
//    return false;
//}

