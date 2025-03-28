#include <iostream>
#include <string>

#include "pair.hpp"
#include "date.hpp"
#include "vector.hpp"
#include "sort.hpp"


int main()
{
    unsigned long long value;

    std::string strBuf;
    
    TKeyValuePair<TDate, unsigned long long> pairBuf;    

    TVector< TKeyValuePair<TDate, unsigned long long> > vector;    // Вектор пар "ключ-значение"

    // while (std::cin >> strBuf >> value) {
    //     TDate dateBuf(strBuf);
    //     pairBuf.key = dateBuf;
    //     pairBuf.value = value;

    //     vector.PushBack(pairBuf);
    // }
    
    
    
    return 0;
}
