#include "Iter.h"

int main()
{
    List<char> stroka;
    stroka.add('i');
    stroka.add('m');
    stroka.add(' ');
    stroka.add('s');
    stroka.add('t');
    stroka.add('r');

    for (auto i = stroka.begin(); i != stroka.end(); ++i) {
        std::cout << *i << std::endl;
    } // Вызов статической функции strOut из класса Stroka
    return 0;
}
