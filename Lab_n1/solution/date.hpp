#include <string>


class TDate
{
private:
    std::string strDate;
    unsigned long int date;
public:
    TDate() = default;
    TDate(const std::string& str);
    bool operator <(const TDate& other) const;

    std::string GetDateStr() const;
};

TDate::TDate(const std::string& str) {
    this->strDate = str;
    std::string curStr;
    int i = 0;
    int length = str.size();
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
}

bool TDate::operator <(const TDate& other) const {
    return this->date < other.date;
}

std::string TDate::GetDateStr() const {
    return this->strDate;
}

std::ostream& operator <<(std::ostream&os, const TDate& date) {
    return os << date.GetDateStr();
}