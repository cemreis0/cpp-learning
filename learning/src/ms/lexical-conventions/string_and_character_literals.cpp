// src/ms/lexical-conventions/string_and_character_literals.cpp

#include <iostream>
using namespace std;

int main()
{
    #include <string>
    using namespace std::string_literals; // enables s-suffix for std::string literals

    // Character literals
    auto c0 = 'A';      // char
    auto c1 = u8'A';    // char
    auto c2 = L'A';     // wchar_t
    auto c3 = u'A';     // char16_t
    auto c4 = U'A';     // char32_t

    // Multicharacter literals
    auto m0 = 'abcd';   // int, value 0x61626364

    // String literals
    auto so = "hello";      // const char*
    auto s1 = u8"hello";    // const char* before C++20, encoded as UTF-8,
                            // const char8_t* in C++20
    auto s2 = L"hello";     // const wchar_t*
    auto s3 = u"hello";     // const char16_t*, encoded as UTF-16
    auto s4 = U"hello";     // const char32_t*, encoded as UTF-32

    // Raw string literals containing unescaped \ and "
    auto R0 =   R"("Hello \ world")"; // const char*
    auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
                                      // const char8_t* in C++20
    auto R2 =  LR"("Hello \ world")"; // const wchar_t*
    auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
    auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

    // Combining string literals with standard s-suffix
    auto S0 =   "hello"s; // std::string
    auto S1 = u8"hello"s; // std::string before C++20, std::u8string in C++20
    auto S2 =  L"hello"s; // std::wstring
    auto S3 =  u"hello"s; // std::u16string
    auto S4 =  U"hello"s; // std::u32string

    // Combining raw string literals with standard s-suffix
    auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
                                       // std::u8string in C++20
    auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
    auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
    auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32

    // Escape sequences
    char newline = '\n';
    char tab = '\t';
    char backspace = '\b';
    // The backslash character (\) is a line-continuation character when it's placed at the end of a line. Type \\ for the character literal.
    char backslash = '\\';
    char nullChar = '\0';

    // String literals
    // Narrow string literals
    const char *narrow = "abcd";
    // represents the string: yes\no
    const char *escaped = "yes\\no";

    // UTF-8 encoded strings
    // Before C++20
    const char* str1 = u8"Hello World";
    const char* str2 = u8"\U0001F607 is O:-)";
    // C++20 and later
    const char8_t* u8str1 = u8"Hello World";
    const char8_t* u8str2 = u8"\U0001F607 is O:-)";

    // Wide string literals
    const wchar_t* wide = L"zyxw";
    const wchar_t* newline = L"hello\ngoodbye";

    // char16_t and char32_t (C++11)
    auto s3 = u"hello"; // const char16_t*
    auto s4 = U"hello"; // const char32_t*

    // Raw string literals (C++11)
    // represents the string: An unescaped \ character
    const char* raw_narrow = R"(An unescaped \ character)";
    const wchar_t*  raw_wide  = LR"(An unescaped \ character)";
    const char*     raw_utf8a = u8R"(An unescaped \ character)"; // Before C++20
    const char8_t*  raw_utf8b = u8R"(An unescaped \ character)"; // C++20
    const char16_t* raw_utf16 = uR"(An unescaped \ character)";
    const char32_t* raw_utf32 = UR"(An unescaped \ character)";

    

    return 0;
}