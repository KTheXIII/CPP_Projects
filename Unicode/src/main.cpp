#include <iostream>
#include <array>
#include <cstdint>
#include <string>

// clang-format off
constexpr auto UTF8_BYTE_SIZE = 4;

void unicodeToUTF8(const uint32_t& code,
                   std::array<uint8_t, UTF8_BYTE_SIZE>& codes) {
    // Leading sequence for different byte size
    constexpr uint8_t LEAD_1BYTE = 0b00000000;  // 0x00
    constexpr uint8_t LEAD_2BYTE = 0b11000000;  // 0xC0
    constexpr uint8_t LEAD_3BYTE = 0b11100000;  // 0xE0
    constexpr uint8_t LEAD_4BYTE = 0b11110000;  // 0xF0
    constexpr uint8_t LEAD_REST  = 0b10000000;  // 0x80

    // Max character count for different byte size
    constexpr uint32_t MAX_CHAR_1BYTE = 0x0000007F;  // MAX 127     CHARACTERS WITH 1 BYTE
    constexpr uint32_t MAX_CHAR_2BYTE = 0x00000800;  // MAX 2048    CHARACTERS WITH 2 BYTE
    constexpr uint32_t MAX_CHAR_3BYTE = 0x00010000;  // MAX 65536   CHARACTERS WITH 3 BYTE
    constexpr uint32_t MAX_CHAR_4BYTE = 0x00200000;  // MAX 2097152 CHARACTERS WITH 4 BYTE

    constexpr uint8_t FILTER_1BYTE    = 0b01111111;
    constexpr uint8_t FILTER_2BYTE    = 0b00011111;
    constexpr uint8_t FILTER_3BYTE    = 0b00001111;
    constexpr uint8_t FILTER_4BYTE    = 0b00000111;
    constexpr uint8_t FILTER_REST     = 0b00111111;

    // Initialise the element with zero
    codes[0] = codes[1] = codes[2] = codes[3] = 0x00;

    if (code <= MAX_CHAR_1BYTE) {
        codes[3] = FILTER_1BYTE & code;
    } else if (code <= MAX_CHAR_2BYTE) {
        codes[2] = LEAD_2BYTE | (FILTER_2BYTE & (code >> 6));
        codes[3] = LEAD_REST  | (FILTER_REST  & (code >> 0));
    } else if (code <= MAX_CHAR_3BYTE) {
        codes[1] = LEAD_3BYTE | (FILTER_3BYTE & (code >> 12));
        codes[2] = LEAD_REST  | (FILTER_REST  & (code >> 6));
        codes[3] = LEAD_REST  | (FILTER_REST  & (code >> 0));
    } else if (code <= MAX_CHAR_4BYTE) {
        codes[0] = LEAD_4BYTE | (FILTER_4BYTE & (code >> 18));
        codes[1] = LEAD_REST  | (FILTER_REST  & (code >> 12));
        codes[2] = LEAD_REST  | (FILTER_REST  & (code >> 6));
        codes[3] = LEAD_REST  | (FILTER_REST  & (code >> 0));
    }
}
// clang-format on

void printUnicode(const std::wstring& text) {
    std::array<uint8_t, UTF8_BYTE_SIZE> codes;
    for (int32_t i = 0; i < text.length(); i++) {
        unicodeToUTF8(text[i], codes);
        for (auto&& code : codes)
            if (code != 0x00) std::cout << code;
    }
}

int main(int argc, char const* argv[]) {
    std::cout << "Hello, Unicode to utf-8 decoder\n";
    printUnicode(L"Rocket 🚀\n");
    printUnicode(L"Desert 🏜\n");
    printUnicode(L"Plane 🛩\n");
    printUnicode(L"Mountain 🗻\n");
    return 0;
}
