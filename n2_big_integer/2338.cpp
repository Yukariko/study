#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

class BigInt
{
    vector<int> buf;
    int sign = 1;

    bool greater_than_abs(const BigInt& rhs) const
    {
        auto a = buf;
        auto b = rhs.buf;
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return a > b;
    }

    void normalize()
    {
        int carry = 0;
        for (int i=0; i < buf.size(); i++) {
            buf[i] += carry;
            if (buf[i] < 0) {
                carry = -1;
                buf[i] = 10 + buf[i];
            } else if (buf[i] >= 10) {
                carry = buf[i] / 10;
                buf[i] %= 10;
            } else {
                carry = 0;
            }
        }

        if (carry > 0) {
            buf.push_back(carry);
        }

        while (buf.size() > 1 && buf.back() == 0) {
            buf.pop_back();
        }

        if (buf.size() == 1 && buf[0] == 0 && sign == -1) {
            sign = 1;
        }
    }

public:
    BigInt() { buf.resize(1); }
    BigInt(const string& s) : buf(s.size())
    {
        for (int i=0; i < s.size(); i++) {
            buf[i] = s[i] - '0';
        }
        reverse(buf.begin(), buf.end());
        if (s[0] == '-') {
            sign = -1;
            buf.pop_back();
        }
    }

    BigInt operator *(const BigInt& rhs) const
    {
        BigInt res;
        res.buf.resize(buf.size() + rhs.buf.size());
        res.sign = sign == rhs.sign? 1: -1;

        for (int i=0; i < buf.size(); i++) {
            for (int j=0; j < rhs.buf.size(); j++) {
                res.buf[i + j] += buf[i] * rhs.buf[j];
            }
        }

        res.normalize();

        return res;
    }

    BigInt operator +(const BigInt& rhs) const
    {
        BigInt res;
        const BigInt * adder;
        if (rhs.greater_than_abs(*this)) {
            res = rhs;
            adder = this;
        } else {
            res = *this;
            adder = &rhs;
        }

        for (int i=0; i < adder->buf.size(); i++) {
            if (res.sign == adder->sign) {
                res.buf[i] = res.buf[i] + adder->buf[i];
            } else {
                res.buf[i] = res.buf[i] - adder->buf[i];
            }
        }

        res.normalize();
        return res;
    }

    BigInt operator -(const BigInt& rhs) const
    {
        BigInt tmp = rhs;
        tmp.sign = rhs.sign * -1;
        return *this + tmp;
    }

    string to_string()
    {
        string res;
        for (auto& n : buf) {
            res += n + '0';
        }
        if (sign == -1) {
            res += '-';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a, b;
    cin >> a >> b;

    BigInt na(a), nb(b);
    BigInt c = na + nb;
    cout << c.to_string() << endl;
    c = na - nb;
    cout << c.to_string() << endl;
    c = na * nb;
    cout << c.to_string() << endl;
    return 0;
}
