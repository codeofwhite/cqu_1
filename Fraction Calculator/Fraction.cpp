#include "Fraction.h"
Fraction operator+(const Fraction& frac1, const Fraction& frac2) { //重载+运算符
	Fraction temp;
	temp.numer = frac1.numer * frac2.deno + frac2.numer * frac1.deno;
	temp.deno = frac1.deno * frac2.deno;
	temp.RdcFrc();//约分
	return temp;
}
Fraction operator-(const Fraction& frac1, const Fraction& frac2) { //重载-运算符
	Fraction temp;
	temp.numer = frac1.numer * frac2.deno - frac2.numer * frac1.deno;
	temp.deno = frac1.deno * frac2.deno;
	temp.RdcFrc();//约分
	return temp;
} 
Fraction operator*(const Fraction& frac1, const Fraction& frac2) { //重载*运算符
	Fraction temp;
	temp.numer = frac1.numer * frac2.numer;
	temp.deno = frac1.deno * frac2.deno;
	temp.RdcFrc();//约分
	return temp;
} 
Fraction operator/(const Fraction& frac1, const Fraction& frac2) { //重载/运算符
	Fraction temp;
	temp.numer = frac1.numer * frac2.deno;
	temp.deno = frac1.deno * frac2.numer;
	temp.RdcFrc();//约分
	return temp;
} 
bool operator==(Fraction frac1, Fraction frac2) { //重载==运算符
	Fraction ts_frac1, ts_frac2;
	ts_frac1 = frac1;
	ts_frac2 = frac2;
	//约分
	ts_frac1.RdcFrc();
	ts_frac2.RdcFrc();
	return (ts_frac1.numer == frac1.numer && ts_frac2.numer == frac2.numer);
}
bool operator>(const Fraction& frac1, const Fraction& frac2) { //重载>运算符
	double r1 = (double)frac1.numer / frac1.deno;
	double r2 = (double)frac2.numer / frac2.deno;
	return r1 > r2;
}
bool operator<(const Fraction& frac1, const Fraction& frac2) { //重载<运算符
	double r1 = (double)frac1.numer / frac1.deno;
	double r2 = (double)frac2.numer / frac2.deno;
	return r1 < r2;
}
ostream& operator<<(ostream& out, const Fraction& frac) { //重载<<运算符
	char rod = '/';
	if (frac.deno == 1) {
		return out << frac.numer;
	}
	else if (frac.deno < 0) {
		return out << -frac.numer << rod << -frac.deno;
	}
	return out << frac.numer << rod << frac.deno;
}
istream& operator>>(istream& in, Fraction& frac) { //重载>>运算符
	char rod = '/';
	return in >> frac.numer >> rod >> frac.deno;
}
void sortFraction(vector<Fraction>& num, char signs) { //对分数数组排序
	if (signs == '>') {
		sort(num.begin(), num.end(), greater<>());		 //从大到小排序
	}
	else {
		sort(num.begin(), num.end(), less<>());			//从小到大排序

	}
}

