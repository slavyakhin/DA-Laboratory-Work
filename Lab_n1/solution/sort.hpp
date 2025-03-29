#pragma once

const int COUNT_SIZE = 10;

void RadixSort(TVector< TKeyValuePair<TDate, unsigned long long> >& vector) {
    int countArray[COUNT_SIZE];
    int prefSumCountArray[COUNT_SIZE];  // index for next element with this digit at the place
    TVector< TKeyValuePair<TDate, unsigned long long> > tmpVector(vector.Size());

    for (int digitOffset = DATE_SIZE - 1; digitOffset >= 0; --digitOffset) {

        for (int i = 0; i < COUNT_SIZE; ++i) {      // init auxiliary arrays with zeros
            countArray[i] = 0;
            prefSumCountArray[i] = 0;
        }
        for (int i = 0; i < vector.Size(); ++i) {   // Counting keys with same digit
            ++countArray[vector[i].key[digitOffset] - '0'];
        }
        prefSumCountArray[0] = 0;
        for (int i = 1; i < COUNT_SIZE; ++i) {      // Prefix sum for index of beginning of a series of same keys
            prefSumCountArray[i] = prefSumCountArray[i - 1] + countArray[i - 1];
        }
        for (int i = 0; i < vector.Size(); ++i) {   // Forming result
            tmpVector[prefSumCountArray[vector[i].key[digitOffset] - '0']] = vector[i];
            ++prefSumCountArray[vector[i].key[digitOffset] - '0'];
        }
        for (int i = 0; i < vector.Size(); ++i) {   // Fixing result
            vector[i] = tmpVector[i];
        }
    }
}