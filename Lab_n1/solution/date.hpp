#pragma once

#include <string>

const int DATE_SIZE = 8;

class TDate
{
private:
    std::string strDate;
    char digits[DATE_SIZE];
public:
    TDate() = default;
    TDate(const std::string& str);
    char operator [](int index);

    std::string GetDateStr() const;
};

TDate::TDate(const std::string& str) {
    this->strDate = str;
    int length = str.size();

    // Parsing DD.MM.YYYY string to digits[DATE_SIZE] = {y, y, y, y, m, m, d, d}
    for (int i = 0; i < DATE_SIZE; ++i) {
        digits[i] = '0';
    }
    int posStrEnd = 0;
    // DD
    for (; posStrEnd < length && str[posStrEnd] != '.'; ++posStrEnd);
    for (int posDig = 7, posStr = posStrEnd - 1; posDig > 5 && posStr >= 0; --posDig, --posStr) {
        digits[posDig] = str[posStr];
    }
    ++posStrEnd;

    // MM
    for (; posStrEnd < length && str[posStrEnd] != '.'; ++posStrEnd);
    for (int posDig = 5, posStr = posStrEnd - 1; posDig > 3 && str[posStr] != '.'; --posDig, --posStr) {
        digits[posDig] = str[posStr];
    }
    ++posStrEnd;

    // YYYY
    posStrEnd = length;
    for (int posDig = 3, posStr = posStrEnd - 1; posDig >= 0 && str[posStr] != '.'; --posDig, --posStr) {
        digits[posDig] = str[posStr];
    }
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
