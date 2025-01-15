#include <iostream>
#include <vector>
#include <string>

using namespace std;

void CreationNumber(const string& str, vector<int>& result)//представляется число в виде строки  
{
	result.clear();//очищает результат для новой записи 
	for (int i = str.size() - 1; i >= 0; i--)
	{
		result.push_back((str[i]) - 48);//добавляется в вектор уже целыми числами  
	}
}

void mul(const vector<int>& a, const vector<int>& b, vector<int>& result)//функция умножения двух больших чисел  
{
	result.clear();// очищает результат для нового вычисления 
	result.resize(a.size() + b.size(), 0);//размер вектора равен сумме размеров умножаемых чисел, тк разрядов после умножения будет такое же количество 
	for (size_t i = 0; i < a.size(); i++)
	{
		int carry = 0;// переменная для хранения числа, которое надо прибавить к следущему разряду 
		for (size_t j = 0; j < b.size(); j++)
		{
			long long current = result[i + j] + carry + (j < b.size() ? a[i] * b[j] : 0);
			result[i + j] = current % 10;//младший разряд результата 
			carry = current / 10;//остаток переносится на следующий разряд
		}
		result[i + b.size()] += carry; // Обработка оставшегося переноса
	}
	while (result.size() > 1 && result.back() == 0)
	{
		result.pop_back();//удаление нулей впереди числа если они будут 
	}
}

void div(const vector<int>& a, int ch, vector<int>& result)//организация деления большого числа на маленькое 
{
	result.clear();
	result.resize(a.size(), 0);//создние вектора с размером, для того чтобы добавлять числа в нужном порядке(обратном)
	long long ostatok = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		ostatok = ostatok * 10 + a[i];
		result[i] = ostatok / ch;
		ostatok %= ch;
	}
	while (result.size() > 1 && result.back() == 0)
	{
		result.pop_back();//удаление нулей впереди числа если они будут 
	}
}

void add(const vector<int>& a, const vector<int>& b, vector<int>& result)//функция для суммы двух больших чисел 
{
	result.clear();
	int carry = 0;
	for (int i = 0; i < a.size() || i < b.size() || carry; i++)
	{
		int sum = carry;
		if (i < a.size())//проверка на лину числа, если оно закончилось ничего не добавляется 
		{
			sum += a[i];//добавляем число из текущего разряда в сумму  
		}
		if (i < b.size())
		{
			sum += b[i];//аналогично как с тем же разрядом добавляет число в сумму
		}
		result.push_back(sum % 10);
		carry = sum / 10;
	}
}

void PrintNumber(const vector<int>& num)
{
	for (int i = num.size() - 1; i >= 0; i--) {
		cout << num[i];//выводит каждый элемент из массива результата суммы в виде большого числа 
	}
	cout << endl;
}

void SumSquares(const string& Nstr, vector<int>& result)//по формуле(n*(n+1)*(2n+1))/6 нахожу сумму квадратов натуральных чисел до n  
{
	vector<int> N;
	vector<int> one;
	vector<int> Nplus1;
	vector<int> twoN;
	vector<int> twoNplus1;
	vector<int> mul1;
	vector<int> mul2;
	CreationNumber(Nstr, N);//превращает строку N в число 
	one.push_back(1);//создание еденицы(вектор {1})
	add(N, one, Nplus1);//вычисляется N+1
	add(N, N, twoN);//вычисляется 2N
	add(twoN, one, twoNplus1);//вычисляется 2N+1
	mul(N, Nplus1, mul1);//умножение N*(N+1)
	mul(mul1, twoNplus1, mul2);//умножение N*(N+1)*(2N+1)
	div(mul2, 6, result);//делится на 6
}
