#include"Fraction.h"
Fraction::Fraction()//�޲ι���
{
	numer = 1;
	deno = 1;
}
Fraction::Fraction(int n, int d) :numer(n), deno(d) {}//�����캯��
Fraction::Fraction(const Fraction& f) :numer(f.numer), deno(f.deno) {}//���ƹ��캯��
void Fraction::setFraction(int n, int d) {//���÷����ķ��Ӻͷ�ĸ
	numer = n;
	deno = d;
}
int Fraction::getNumer() { //��ȡ�����ķ���
	return numer;
}
int Fraction::getDeno() {//��ȡ�����ķ�ĸ
	return deno;
}
int Fraction::Gcd(int m, int n)//���Լ��(��ŷ������㷨)
{
	if (n == 0)
		return m;
	return Gcd(n, m % n);
}
void Fraction::RdcFrc() {  //��ǰ����Լ��
	int gcd = Gcd(numer, deno);
	if (gcd != 0) {
		numer = numer / gcd;
		deno = deno / gcd;
	}
}