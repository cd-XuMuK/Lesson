#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <utility>

using namespace std;


int my_div(int num, int diver) {
    if ((num < 0) && (num % diver))
        return num / diver - 1;
    else
        return num / diver;
}


int my_mod(int num, int diver) {
    if ((num < 0) && (num % diver))
        return num % diver + diver;
    else
        return num % diver;
}


class BigNumber {
private:
    vector<int> chunks;
    int sign;

    static const int BASE = 2;

    static const int BASE10 = 100;


    BigNumber _plus(BigNumber& a);
    BigNumber _minus(BigNumber& a);

    void _normalizationSigns();
    void _normalizationChunks();
    void _resize(int newsize);

public:

    BigNumber operator + (BigNumber& num);

    friend ostream& operator << (ostream& os, BigNumber& num);

    int getBASE() {
        return this->BASE;
    }


    BigNumber(string str) {
        int i;
        if (BASE != 1) {

            for (i = str.size() - BASE; i >= BASE - 1; i -= BASE) {
                chunks.push_back(stoi(str.substr(i, BASE)));
            }
        }
        else {
            for (i = str.size() - BASE; i >= BASE; i -= BASE) {
                chunks.push_back(stoi(str.substr(i, BASE)));
            }
        }

        if (str[0] == '-') {
            sign = -1;
            if (i + BASE - 1 != 0) {
                chunks.push_back(stoi(str.substr(1, i + BASE - 1)));
            }
        }
        else {
            sign = 1;
            chunks.push_back(stoi(str.substr(0, i + BASE)));
        }
    }


    BigNumber() {
        sign = 1;
    }
};

void BigNumber::_resize(int newSize) {
    chunks.resize(newSize);
}


void BigNumber::_normalizationChunks() {
    int over = 0;
    for (int i = 0; i < chunks.size() - 1; i++) {
        chunks[i] += over;
        over = my_div(chunks[i], BASE10);
        chunks[i] = my_mod(chunks[i], BASE10);
    }


    chunks[chunks.size() - 1] += over;

    if (chunks[chunks.size() - 1] / BASE10) {
        over = my_div(chunks[chunks.size() - 1], BASE10);
        chunks[chunks.size() - 1] = my_mod(chunks[chunks.size() - 1], BASE10);
        chunks.push_back(over);
    }
    return;
}


void BigNumber::_normalizationSigns() {

    if (chunks[chunks.size() - 1] < 0) {
        sign = -sign;
        chunks[0] = BASE10 - chunks[0];
        for (int i = 1; i < chunks.size(); i++) {
            chunks[i] = (BASE10 - chunks[i] - 1) % BASE10;
        }
    }

    int i = chunks.size() - 1;
    while (chunks[i] == 0) {
        if (i == 0) {
            sign = 1;
            return;
        }
        chunks.pop_back();
        i--;
    }
    return;
}


BigNumber BigNumber::_plus(BigNumber& num) {
    BigNumber res;
    res.sign = this->sign;
    for (int i = 0; i < this->chunks.size(); i++) {
        res.chunks.push_back(this->chunks[i] + num.chunks[i]);
    }
    return res;
}


BigNumber BigNumber::_minus(BigNumber& num) {
    BigNumber res;
    res.sign = this->sign;
    for (int i = 0; i < this->chunks.size(); i++) {
        res.chunks.push_back(this->chunks[i] - num.chunks[i]);
    }
    return res;
}


BigNumber BigNumber::operator + (BigNumber& num) {
    BigNumber res;

    if (this->chunks.size() > num.chunks.size()) {
        num._resize(chunks.size());
    }
    else {
        (*this)._resize(num.chunks.size());
    }

    if (sign == num.sign) {
        res = (*this)._plus(num);
    }
    else {
        res = (*this)._minus(num);
    }

    res._normalizationChunks();
    return res;
}

ostream& operator << (ostream& os, BigNumber& num) {
    num._normalizationSigns();
    if (num.sign == -1) {
        os << '-';
    }
    os << num.chunks[num.chunks.size() - 1];
    for (int i = num.chunks.size() - 2; i >= 0; i--) {
        os << setw(num.getBASE()) << setfill('0') << num.chunks[i];
    }
    return os;
}

int main() {
    BigNumber n1("-200000000000000000000000000000000000000000000000000000000000010");
    BigNumber n2("-20");
    BigNumber n3 = n1 + n2;
    cout << n3 << endl;
    return 0;
}