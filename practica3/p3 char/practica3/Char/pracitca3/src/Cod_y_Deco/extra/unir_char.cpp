#include "../../../hdr/extra/unir_char.h"

char* unir_char(const char* text1, const char* text2) {
    unsigned long long letters1 = count_letters(text1);
    unsigned long long letters2 = count_letters(text2);

    if(letters1 == 0) return nullptr;

    unsigned long long i{};
    char* final = new char[letters1 + letters2 + 1];
    for(; i < letters1; ++i) {
        final[i] = text1[i];
    }
    for(unsigned long long j{}; j < letters2; ++j, ++i) {
        final[i] = text2[j];
    }
    final[i] = '\0';
    return final;
}

unsigned long long count_letters(const char* text) {
    unsigned long long count{};
    while(text[count] != '\0') {
        ++count;
    }
    return count;
}
