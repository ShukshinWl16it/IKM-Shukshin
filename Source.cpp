#include <iostream>
#include <vector>
#include <string>

using namespace std;

void CreationNumber(const string& str, vector<int>& result)//�������������� ����� � ���� ������  
{
	result.clear();//������� ��������� ��� ����� ������ 
	for (int i = str.size() - 1; i >= 0; i--)
	{
		result.push_back((str[i]) - 48);//����������� � ������ ��� ������ �������  
	}
}

void mul(const vector<int>& a, const vector<int>& b, vector<int>& result)
{
	result.clear();// ������� ��������� ��� ������ ���������� 
	result.resize(a.size() + b.size(), 0);//������ ������� ����� ����� �������� ���������� �����, �� �������� ����� ��������� ����� ����� �� ���������� 
	for (size_t i = 0; i < a.size(); i++)
	{
		int carry = 0;// ���������� ��� �������� �����, ������� ���� ��������� � ��������� ������� 
		for (size_t j = 0; j < b.size(); j++)
		{
			long long current = result[i + j] + carry + (j < b.size() ? a[i] * b[j] : 0);//���� ������ ����� ��� ����, �� ������������� ����� �� ������ �������, ����� ������������ ����
			result[i + j] = current % 10;//������� ������ ���������� 
			carry = current / 10;//������� ����������� �� ��������� ������
		}
		result[i + b.size()] += carry; // ��������� ����������� ��������
	}
	while (result.size() > 1 && result.back() == 0)
	{
		result.pop_back();//�������� ����� ������� ����� ���� ��� ����� 
	}
}

void div(const vector<int>& a, int ch, vector<int>& result)//����������� ������� ���������
{
	result.clear();
	result.resize(a.size(), 0);//������� ������� � ��������, ��� ���� ����� ��������� ����� � ������ �������(��������)
	long long ostatok = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		ostatok = ostatok * 10 + a[i];
		result[i] = ostatok / ch;
		ostatok %= ch;
	}
	while (result.size() > 1 && result.back() == 0)
	{
		result.pop_back();//�������� ����� ������� ����� ���� ��� ����� 
	}
}

void add(const vector<int>& a, const vector<int>& b, vector<int>& result)
{
	result.clear();
	int carry = 0;
	for (int i = 0; i < a.size() || i < b.size() || carry; i++)
	{
		int sum = carry;
		if (i < a.size())//�������� �� ���� �����, ���� ��� ����������� ������ �� ����������� 
		{
			sum += a[i];//��������� ����� �� �������� ������� � �����  
		}
		if (i < b.size())
		{
			sum += b[i];//���������� ��� � ��� �� �������� ��������� ����� � �����
		}
		result.push_back(sum % 10);
		carry = sum / 10;
	}
}

void PrintNumber(const vector<int>& num)
{
	for (int i = num.size() - 1; i >= 0; i--) {
		cout << num[i];//������� ������ ������� �� ������� ���������� ����� � ���� �������� ����� 
	}
	cout << endl;
}

void SumSquares(const string& Nstr, vector<int>& result)//�� �������(n*(n+1)*(2n+1))/6 ������ ����� ��������� ����������� ����� �� n  
{
	vector<int> N;
	vector<int> one;
	vector<int> Nplus1;
	vector<int> twoN;
	vector<int> twoNplus1;
	vector<int> mul1;
	vector<int> mul2;
	CreationNumber(Nstr, N);//���������� ������ N � ����� 
	one.push_back(1);//�������� �������(������ {1})
	add(N, one, Nplus1);//����������� N+1
	add(N, N, twoN);//����������� 2N
	add(twoN, one, twoNplus1);//����������� 2N+1
	mul(N, Nplus1, mul1);//��������� N*(N+1)
	mul(mul1, twoNplus1, mul2);//��������� N*(N+1)*(2N+1)
	div(mul2, 6, result);//������� �� 6
}