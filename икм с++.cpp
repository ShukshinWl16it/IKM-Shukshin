#include <iostream>
#include <vector>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
	vector<int> result;
	setlocale(LC_ALL, "rus");
	string N;
	while (true)
	{
		cout << "Добро пожаловать новый пользователь!" << endl;
		cout << "Введите число N(положительное целое число): ";
		getline(cin, N);
		bool correct = true;//переменная для проверки на правильность ввода
		for (int i = 0; i < N.size(); i++) {
			if (cin.fail() || N.empty()) {
				cout << "Неккоректный ввод! Пожалуйста введите число заново" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if ((!isdigit(N[i])) || isspace(N[i]) || N[0] == '0') {//если символ не является цифрой булевая переменная false
				correct = false;
				break;
			}
		}
		if (!correct) {
			cout << "Неккоректный ввод! Пожалуйста введите число заново" << endl;
			continue;
		}
		else {
			break;
		}
	}
	SumSquares(N, result);//считает сумму 
	cout << "Сумма квадратов от 1 до N=";
	PrintNumber(result);
	return 0;
}