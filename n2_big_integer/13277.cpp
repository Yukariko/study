#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int CUT = 8;
const int DEC = 1e8;
class BigInt
{
    vector<ll> buf;
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
        ll carry = 0;
        for (size_t i=0; i < buf.size(); i++) {
            buf[i] += carry;
            if (buf[i] < 0) {
                carry = -1;
                buf[i] = DEC + buf[i];
            } else if (buf[i] >= DEC) {
                carry = buf[i] / DEC;
                buf[i] %= DEC;
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
    BigInt(const string& s)
    {
        int start = 0;
        if (s[0] == '-') {
            sign = -1;
            start = 1;
        }
        for (int i=s.size() - 1; i >= start; i -= CUT) {
            int num = 0;
            for (int j=min(CUT - 1, i - start); j >= 0; j--) {
                num = num * 10 + s[i-j] - '0';
            }
            buf.push_back(num);
        }
    }
    BigInt(vector<ll>::const_iterator begin, vector<ll>::const_iterator end, int sign = 1) : buf(begin, end), sign(sign)
    {
    }

    static BigInt karatsuba(const BigInt& lhs, const BigInt& rhs)
    {
        if (lhs.buf.size() <= 300 || rhs.buf.size() <= 300) {
            return lhs * rhs;
        }

        int m = min(lhs.buf.size(), rhs.buf.size()) / 2;

        auto hi = BigInt(lhs.buf.begin() + m, lhs.buf.end(), lhs.sign);
        auto hi2 = BigInt(rhs.buf.begin() + m, rhs.buf.end(), rhs.sign);
        auto lo = BigInt(lhs.buf.begin(), lhs.buf.begin() + m, lhs.sign);
        auto lo2 = BigInt(rhs.buf.begin(), rhs.buf.begin() + m, rhs.sign);

        auto z0 = karatsuba(lo, lo2);
        auto z1 = karatsuba((hi + lo), (hi2 + lo2));
        auto z2 = karatsuba(hi, hi2);

        return z2.power10(m * 2) + (z1 - z2 - z0).power10(m) + z0;
    }

    BigInt power10(int p) const
    {
        if (buf.back() == 0) {
            return *this;
        }

        vector<ll> tmp(p);
        tmp.insert(tmp.end(), buf.begin(), buf.end());
        BigInt res(tmp.begin(), tmp.end(), sign);
        return res;
    }

    BigInt operator *(const BigInt&& rhs) const
    {
        BigInt res;
        res.buf.resize(buf.size() + rhs.buf.size() + 1);
        res.sign = sign == rhs.sign? 1: -1;

        for (size_t i=0; i < buf.size(); i++) {
            for (size_t j=0; j < rhs.buf.size(); j++) {
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

        for (size_t i=0; i < adder->buf.size(); i++) {
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
        if (sign == -1) {
            res += '-';
        }

        res += std::to_string(buf.back());
        for (auto it = buf.rbegin() + 1; it != buf.rend(); it++) {
            for (int i=DEC / 10; i >= 1; i /= 10) {
                res += (*it / i % 10) + '0';
            }
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a, b;
    cin >> a >> b;

    BigInt na(a), nb(b);
    cout << BigInt::karatsuba(na, nb).to_string() << endl;
    return 0;
}
