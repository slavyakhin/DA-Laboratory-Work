#pragma once

const int COUNT_SIZE = 10;

void RadixSort(TVector< TKeyValuePair<TDate, unsigned long long> >& vector) {
    int prefSumCountArray[COUNT_SIZE];  // index for next element with this digit at the place
    TVector< TKeyValuePair<TDate, unsigned long long> > tmpVector(vector.Size());

    // key[] = {y, y, y, y, m, m, d, d}
    for (int digitOffset = DATE_SIZE - 1; digitOffset >= 0; --digitOffset) {

        for (int i = 0; i < COUNT_SIZE; ++i) {      // init auxiliary arrays with zeros
            prefSumCountArray[i] = 0;
        }
        for (int i = 0; i < vector.Size(); ++i) {   // Counting keys with same digit
            ++prefSumCountArray[vector[i].key[digitOffset] - '0'];
        }
        for (int i = 1; i < COUNT_SIZE; ++i) {      // Prefix sum for index of beginning of a series of same keys
            prefSumCountArray[i] += prefSumCountArray[i - 1];
        }
        for (int i = vector.Size() - 1; i >= 0; --i) {   // Forming result
            tmpVector[prefSumCountArray[vector[i].key[digitOffset] - '0'] - 1] = vector[i];
            --prefSumCountArray[vector[i].key[digitOffset] - '0'];
        }
        for (int i = 0; i < vector.Size(); ++i) {   // Result
            vector[i] = tmpVector[i];
        }
    }
}
