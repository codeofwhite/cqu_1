#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Fraction
{
	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //重载+运算符
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //重载-运算符
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //重载*运算符
	friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //重载/运算符
	friend bool operator==(Fraction frac1, Fraction frac2);                  //重载==运算符
	friend bool operator>(const Fraction& frac1, const Fraction& frac2);     //重载>运算符
	friend bool operator<(const Fraction& frac1, const Fraction& frac2);     //重载<运算符
	friend ostream& operator<<(ostream& out, const Fraction& frac);          //重载<<运算符
	friend istream& operator>>(istream& in, Fraction& frac);                 //重载>>运算符
	friend void sortFraction(vector<Fraction>&, char);//对分数数组排序
public:
	Fraction();                      //无参造函数
	Fraction(int n, int d);          //带参造函数
	Fraction(const Fraction& f);     //复制造函数
	void setFraction(int n, int d);  //设置分数的分子和分母
	int getNumer();                  //获取分数的分子
	int getDeno();                   //获取分数的分母
	void RdcFrc();                   //当前分数约分
	int Gcd(int, int);				 //获取最大公约数
private:
	int numer; //分子
	int deno;  //分母    
};


