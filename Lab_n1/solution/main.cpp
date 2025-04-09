#include <iostream>
#include <fstream>
#include <string>

#include "pair.hpp"
#include "date.hpp"
#include "vector.hpp"
#include "sort.hpp"

#include <time.h>

int main()
{
    unsigned long long value;

    std::string strBuf;

    TKeyValuePair<TDate, unsigned long long> pairBuf;    

    TVector< TKeyValuePair<TDate, unsigned long long> > vector;    // Вектор пар "ключ-значение"

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    while (fin >> strBuf >> value) {
        TDate dateBuf(strBuf);
        pairBuf.key = dateBuf;
        pairBuf.value = value;
        
        vector.PushBack(pairBuf);
    }

    clock_t startTime, endTime;
    startTime = clock();
    
    RadixSort(vector);

    endTime = clock();
    std::cout << "RadixSort time: " << (double)(endTime - startTime)/CLOCKS_PER_SEC << '\n';

    for (int i = 0; i < vector.Size(); ++i) {
        fout << vector[i].key.GetDateStr() << '\t' << vector[i].value << '\n';
    }
    
    fin.close();
    fout.close();
    
    return 0;
}

