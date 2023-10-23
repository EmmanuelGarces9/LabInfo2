#include "../../../hdr/extra/printInfoArray.h"

template <typename T>
void printArray(T* array, const unsigned long long tam, const bool newLine) {
    for(unsigned long long i{}; i < tam; i++) {
        cout << array[i];
        if(newLine) {
            cout << '\n';
        }
    }
}
