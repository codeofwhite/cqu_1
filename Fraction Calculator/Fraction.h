#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Fraction
{
	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //����+�����
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //����-�����
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //����*�����
	friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //����/�����
	friend bool operator==(Fraction frac1, Fraction frac2);                  //����==�����
	friend bool operator>(const Fraction& frac1, const Fraction& frac2);     //����>�����
	friend bool operator<(const Fraction& frac1, const Fraction& frac2);     //����<�����
	friend ostream& operator<<(ostream& out, const Fraction& frac);          //����<<�����
	friend istream& operator>>(istream& in, Fraction& frac);                 //����>>�����
	friend void sortFraction(vector<Fraction>&, char);//�Է�����������
public:
	Fraction();                      //�޲��캯��
	Fraction(int n, int d);          //�����캯��
	Fraction(const Fraction& f);     //�����캯��
	void setFraction(int n, int d);  //���÷����ķ��Ӻͷ�ĸ
	int getNumer();                  //��ȡ�����ķ���
	int getDeno();                   //��ȡ�����ķ�ĸ
	void RdcFrc();                   //��ǰ����Լ��
	int Gcd(int, int);				 //��ȡ���Լ��
private:
	int numer; //����
	int deno;  //��ĸ    
};


