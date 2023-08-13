#include"Fraction.h"
Fraction::Fraction()//无参构造
{
	numer = 1;
	deno = 1;
}
Fraction::Fraction(int n, int d) :numer(n), deno(d) {}//带参造函数
Fraction::Fraction(const Fraction& f) :numer(f.numer), deno(f.deno) {}//复制构造函数
void Fraction::setFraction(int n, int d) {//设置分数的分子和分母
	numer = n;
	deno = d;
}
int Fraction::getNumer() { //获取分数的分子
	return numer;
}
int Fraction::getDeno() {//获取分数的分母
	return deno;
}
int Fraction::Gcd(int m, int n)//最大公约数(用欧几里得算法)
{
	if (n == 0)
		return m;
	return Gcd(n, m % n);
}
void Fraction::RdcFrc() {  //当前分数约分
	int gcd = Gcd(numer, deno);
	if (gcd != 0) {
		numer = numer / gcd;
		deno = deno / gcd;
	}
}