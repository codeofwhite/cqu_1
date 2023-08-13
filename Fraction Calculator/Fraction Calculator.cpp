//20220664 张和俊 程序设计project 分数计算机实现
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<string>
#include<Windows.h>
using namespace std;
#include"Fraction.h"
void m_HMI();
void HMI_1();
void HMI_2();
void HMI_3();
//设置单个句子或字的颜色
void SetColorAndBackground(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
//加减乘除界面
void HMI_1() {
	do {
		char signs_1;
		Fraction fra1, fra2;
		SetColorAndBackground(7, 1);
		cout << "Please enter the score formula (such as 1/2 + 1/3 press enter)" << endl;
		cout << "enter a ";
		SetColorAndBackground(4, 1);
		cout << " # ";
		SetColorAndBackground(7, 1);
		cout << "sign to return to the previous directory" << endl;
		SetColorAndBackground(15, 9);
		cout << "Please enter here:";
		cin >> fra1 >> signs_1 >> fra2;
		//判断是否符合输入格式
		while (cin.fail() || (signs_1 != '+' && signs_1 != '-' && signs_1 != '*' && signs_1 != '/') || fra1.getDeno() == 0 || fra2.getDeno() == 0) {
			try
			{
				if (cin.fail() == true) {
					throw 0.1;
				}
				else if (fra1.getDeno() == 0 || fra2.getDeno() == 0) {
					throw 0;
				}
				else if ((signs_1 != '+' && signs_1 != '-' && signs_1 != '*' && signs_1 != '/')) {
					throw signs_1;
				}

			}
			catch (const int e)
			{
				SetColorAndBackground(7, 5);
				cout << "The denominator cannot be " << e << endl;
			}
			catch (const char s) {
				SetColorAndBackground(7, 5);
				cout << "Operator sign error " << "[" << s << "]" << endl;
			}
			catch (const double de) {
				SetColorAndBackground(7, 5);
				cout << "The format of the fraction is incorrect" << endl;
			}
			cin.clear();//清除错误的状态（注意不是把里面的东西清了）
			if (cin.peek() == '#')//只是看#这个字符，但不取走。
			{
				cin.get();//这条就直接把#取走了
				system("cls");
				return m_HMI();
			}
			cin.ignore(INT_MAX, '\n');//消除上一次输入对下一次输入的影响
			SetColorAndBackground(7, 4);
			cout << "*******************************" << endl;
			cout << "**Input error, please re-type**" << endl;
			cout << "*******************************" << endl;
			SetColorAndBackground(7, 1);
			cout << "Please enter the score formula (such as 1/2 + 1/3 press enter)" << endl;
			cout << "enter a ";
			SetColorAndBackground(4, 1);
			cout << " # ";
			SetColorAndBackground(7, 1);
			cout << "sign to return to the previous directory" << endl;
			SetColorAndBackground(15, 9);
			cout << "Please enter here:";
			cin >> fra1 >> signs_1 >> fra2;
		}
		Fraction rs;
		switch (signs_1)
		{
		case '+':
			rs = fra1 + fra2;
			break;
		case '-':
			rs = fra1 - fra2;
			break;
		case'*':
			rs = fra1 * fra2;
			break;
		case'/':
			rs = fra1 / fra2;
			break;
		}
		cout << fra1 << signs_1 << fra2 << " = " << rs << endl;
		cout << "Enter [S] to {S<=>D}.Press Enter to skip" << endl;
		string button2;
		cin.get();
		getline(cin, button2);
		if (button2 == "S") {
			cout << rs << " = " << (double)rs.getNumer() / rs.getDeno() << endl;
		}

	} while (1);
}
//排序界面
void HMI_2() {
	do {
		char signs_2;
		Fraction frac_2;
		vector<Fraction> nums;
		SetColorAndBackground(7, 1);
		cout << "Please enter a set of fractions separated by commas. If you need to sort from large to small, end with a symbol (>). " << endl;
		cout << "If you need to sort from large to small, end with a symbol (<) (such as 1/2,1/4,3/4<)," << endl;
		cout << "enter a ";
		SetColorAndBackground(4, 1);
		cout << " # ";
		SetColorAndBackground(7, 1);
		cout << "sign to return to the previous directory" << endl;
		SetColorAndBackground(15, 9);
		cout << "Please enter here:";
		SetColorAndBackground(15, 9);
		do {
			cin >> frac_2 >> signs_2;
			while (cin.fail() || (signs_2 != ',' && signs_2 != '>' && signs_2 != '<') || frac_2.getDeno() == 0) {
				try
				{
					if (cin.fail() == true) {
						throw 0.1;
					}
					else if (frac_2.getDeno() == 0) {
						throw 0;
					}
					else if ((signs_2 != ',' && signs_2 != '>' && signs_2 != '<')) {
						throw signs_2;
					}
				}
				catch (const int e)
				{
					SetColorAndBackground(7, 5);
					cout << "The denominator cannot be " << e << endl;
				}
				catch (const char s) {
					SetColorAndBackground(7, 5);
					cout << "Operator sign error " << "[" << s << "]" << endl;
				}
				catch (const double de) {
					SetColorAndBackground(7, 5);
					cout << "The format of the fraction is incorrect" << endl;
				}
				cin.clear();
				if (cin.peek() == '#') {
					cin.get();
					system("cls");
					return m_HMI();
				}
				cin.ignore(INT_MAX, '\n');
				SetColorAndBackground(7, 4);
				cout << "*******************************" << endl;
				cout << "**Input error, please re-type**" << endl;
				cout << "*******************************" << endl;
				SetColorAndBackground(7, 1);
				cout << "Please enter a set of fractions separated by commas. If you need to sort from large to small, end with a symbol (>). " << endl;
				cout << "If you need to sort from large to small, end with a symbol (<) (such as 1/2,1/4,3/4<)," << endl;
				cout << "enter a ";
				SetColorAndBackground(4, 1);
				cout << " # ";
				SetColorAndBackground(7, 1);
				cout << "sign to return to the previous directory" << endl;
				SetColorAndBackground(15, 9);
				cout << "Please enter here:";
				cin >> frac_2 >> signs_2;
			}

			nums.push_back(frac_2);

			if (signs_2 == '>' || signs_2 == '<') {
				break;
			}
		} while (1);
		//这里开始调用排序
		sortFraction(nums, signs_2);
		int k = nums.size();
		int count = 0;
		if (signs_2 == '>') {
			cout << "from left to right, sort from largest to smallest:";
		}
		else {
			cout << "from left to right, sort from smallest to biggest:";
		}
		//输出排序好的分数组
		for (vector<Fraction>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			count++;
			if (count != k) {
				cout << *it << "→";
			}
			else if (count == k)
			{
				cout << *it;
			}

		}
		cout << endl;

	} while (1);
}
//累积计算界面
void HMI_3() {
	do {
		char signs_3;
		Fraction frac_3;
		vector<Fraction> numss;
		SetColorAndBackground(7, 1);
		cout << "Please enter a set of fractions separated by commas, end with a symbol(+,-,*,/). " << endl;
		cout << "(such as 1/2,1/4,3/4+)," << endl;
		cout << "enter a ";
		SetColorAndBackground(4, 1);
		cout << " # ";
		SetColorAndBackground(7, 1);
		cout << "sign to return to the previous directory" << endl;
		SetColorAndBackground(15, 9);
		cout << "Please enter here:";
		SetColorAndBackground(15, 9);
		do {
			cin >> frac_3 >> signs_3;
			while (cin.fail() || (signs_3 != ',' && signs_3 != '+' && signs_3 != '-' && signs_3 != '*' && signs_3 != '/') || (frac_3.getDeno() == 0)) {
				try
				{
					if (cin.fail() == true) {
						throw  0.1;
					}
					else if (frac_3.getDeno() == 0) {
						throw 0;
					}
					else if ((signs_3 != ',' && signs_3 != '+' && signs_3 != '-' && signs_3 != '*' && signs_3 != '/')) {
						throw signs_3;
					}
				}
				catch (const int e)
				{
					SetColorAndBackground(7, 5);
					cout << "The denominator cannot be " << e << endl;
				}
				catch (const char s) {
					SetColorAndBackground(7, 5);
					cout << "Operator sign error " << "[" << s << "]" << endl;
				}
				catch (const double de) {
					SetColorAndBackground(7, 5);
					cout << "The format of the fraction is incorrect" << endl;
				}

				cin.clear();
				if (cin.peek() == '#') {
					cin.get();
					system("cls");
					return m_HMI();
				}
				cin.ignore(INT_MAX, '\n');
				SetColorAndBackground(7, 4);
				cout << "*******************************" << endl;
				cout << "**Input error, please re-type**" << endl;
				cout << "*******************************" << endl;
				SetColorAndBackground(7, 1);
				cout << "Please enter a set of fractions separated by commas, end with a symbol(+,-,*,/). " << endl;
				cout << "(such as 1/2,1/4,3/4+)," << endl;
				cout << "enter a ";
				SetColorAndBackground(4, 1);
				cout << " # ";
				SetColorAndBackground(7, 1);
				cout << "sign to return to the previous directory" << endl;
				SetColorAndBackground(15, 9);
				cout << "Please enter here:";
				cin >> frac_3 >> signs_3;
			}

			numss.push_back(frac_3);

			if (signs_3 == '+' || signs_3 == '-' || signs_3 == '*' || signs_3 == '/') {
				break;
			}
		} while (1);
		vector<Fraction>::iterator it3 = numss.begin();
		Fraction sum = *it3;
		if (signs_3 == '+') {
			for (vector<Fraction>::iterator it3 = numss.begin() + 1; it3 != numss.end(); it3++) {
				sum = sum + *it3;
			}
			cout << "Addition by accumulation" << " = " << sum << endl;
		}
		else if (signs_3 == '-') {
			for (vector<Fraction>::iterator it3 = numss.begin() + 1; it3 != numss.end(); it3++) {
				sum = sum - *it3;
			}
			cout << "Cumulative subtraction" << " = " << sum << endl;
		}
		else if (signs_3 == '*') {
			for (vector<Fraction>::iterator it3 = numss.begin() + 1; it3 != numss.end(); it3++) {
				sum = sum * *it3;
			}
			cout << "Multiplication by accumulation" << " = " << sum << endl;
		}
		else if (signs_3 == '/') {
			for (vector<Fraction>::iterator it3 = numss.begin() + 1; it3 != numss.end(); it3++) {
				sum = sum / *it3;
			}
			cout << "Division by accumulation" << " = " << sum << endl;
		}
		cout << "Enter [S] to {S<=>D}.Press Enter to skip" << endl;
		string button3;
		cin.get();
		getline(cin, button3);
		if (button3 == "S") {
			cout << sum << " = " << (double)sum.getNumer() / sum.getDeno() << endl;
		}

	} while (1);
}
//主界面
void m_HMI() {
	system("color 9E");
	string button;
	cout << "--------------------------------------------" << endl;
	cout << "|  Welcome to the Fraction calculator!!!   |" << endl;
	cout << "--------------------------------------------" << endl;
	system("pause");
loop1:
	cout << "--------------------------------------------" << endl;
	cout << "Please select function(Type A or B or C)   |" << endl;
	cout << "A.Fraction Calculate                       |" << endl;
	cout << "B.Order of fraction                        |" << endl;
	cout << "C.Continuous fractional operation          |" << endl;
	SetColorAndBackground(15, 9);
	cout << "Press ";
	SetColorAndBackground(4, 9);
	cout << " # ";
	SetColorAndBackground(15, 9);
	cout << " to exit                          |" << endl;
	cout << "--------------------------------------------" << endl;
	SetColorAndBackground(0, 9);
	cout << "Enter the operation here:";
	do {
		cin >> button;
		if (button == "A") {
			system("cls");
			HMI_1();
		}
		else if (button == "B") {
			system("cls");
			HMI_2();
		}
		else if (button == "#") {
			cout << "*********************************************" << endl;
			cout << "**Successfully exit the Fraction calculator**" << endl;
			cout << "*********************************************" << endl;
			exit(-1);
		}
		else if (button == "C") {
			system("cls");
			HMI_3();
		}
		else {
			system("cls");
			SetColorAndBackground(0, 4);
			cout << "***************************************" << endl;
			cout << "**Wrong operation!Please enter again!**" << endl;
			cout << "***************************************" << endl;
			SetColorAndBackground(7, 1);
			goto loop1;
		}
	} while (1);

}
int main() {
	for (;;) {
		system("cls");
		m_HMI();
	}
	return 0;
}