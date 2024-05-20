#include "Iter.h"

void strOut() {
    List<char> str;
    str.add('i');
    str.add('m');
    str.add(' ');
    str.add('s');
    str.add('t');
    str.add('r');

    for (auto i = str.begin(); i != str.end(); i++) {
        std::cout << *i << std::endl;
    }
}