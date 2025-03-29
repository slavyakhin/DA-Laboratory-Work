#pragma once

#include <string>

const int DATE_SIZE = 8;

class TDate
{
private:
    std::string strDate;
    unsigned long int date; // For bitwise approach and operator <
    char digits[DATE_SIZE];
public:
    TDate() = default;
    TDate(const std::string& str);
    bool operator <(const TDate& other) const;
    char operator [](int index);

    std::string GetDateStr() const;
};

TDate::TDate(const std::string& str) {
    this->strDate = str;
    int i = 0;
    int length = str.size();


    // Parsing DD.MM.YYYY string to ulint
    std::string curStr;
    unsigned long int uliTemp = 0;
    for (; i < length && str[i] != '.'; ++i) {
        curStr += str[i];
        
    }

    uliTemp = std::stoi(curStr);
    this->date |= uliTemp; // first 5 bits are for day (2^5 == 32 > 31)
    ++i;


    curStr = "";
    for (; i < length && str[i] != '.'; ++i) {
        curStr += str[i];
    }
    uliTemp= std::stoi(curStr);
    this->date |= (uliTemp << 5); // 6-9 bits are for month (2^4 == 16 > 12)
    ++i;

    curStr = "";
    for (; i < length && str[i] != '.'; ++i) {
        curStr += str[i];
    }
    uliTemp = std::stoi(curStr);
    this->date |= (uliTemp << 9); // 10-23 bits are for year (2^14 == 16384 > 9999)


    // Parsing DD.MM.YYYY string to digits[DATE_SIZE] = {d, d, m, m, y, y, y, y}
    for (int i = 0; i < DATE_SIZE; ++i) {
        digits[i] = '0';
    }
    int posStrEnd = 0;
    // DD
    for (; posStrEnd < length && str[posStrEnd] != '.'; ++posStrEnd);
    for (int posDig = 1, posStr = posStrEnd - 1; posDig >= 0 && posStr >= 0; --posDig, --posStr) {
        digits[posDig] = str[posStr];
    }
    ++posStrEnd;

    // MM
    for (; posStrEnd < length && str[posStrEnd] != '.'; ++posStrEnd);
    for (int posDig = 3, posStr = posStrEnd - 1; posDig > 1 && str[posStr] != '.'; --posDig, --posStr) {
        digits[posDig] = str[posStr];
    }
    ++posStrEnd;

    // YYYY
    posStrEnd = length;
    for (int posDig = 7, posStr = posStrEnd - 1; posDig > 3 && str[posStr] != '.'; --posDig, --posStr) {
        digits[posDig] = str[posStr];
    }
}

bool TDate::operator <(const TDate& other) const {
    return this->date < other.date;
}

char TDate::operator [](int index) {
    return this->digits[index];
}

std::string TDate::GetDateStr() const {
    return this->strDate;
}

std::ostream& operator <<(std::ostream& os, const TDate& date) {
    return os << date.GetDateStr();
}
