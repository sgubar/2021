#include <iostream>
using namespace std;

int fact(int number)
{
	if (number == 0)
	{
		return 1;
	}
	else
	{
		return number * fact(number -1);
	}
}

int main()
{
	int A, B, C, D;
	double Q;

	while (true)
	{
		cout << "Enter A: "; cin >> A;
		if (!cin)
		{
			cout << "entered data is not correct, try again!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	while (true)
	{
		cout << "Enter B: "; cin >> B;
		if (!cin)
		{
			cout << "entered data is not correct, try again!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	while (true)
	{
		cout << "Enter C: "; cin >> C;
		if (!cin)
		{
			cout << "entered data is not correct, try again!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	if (B + C * C == 0)
	{
		cout << "Undefined" << endl;
		return 0;
	}

	Q = (A * B) / (B + C * C);
	for (int i = 0; i <= B; i++)
	{
		Q += fact(i);
	}

	cout.setf(ios::fixed);
	cout << "Q = " << Q << endl;
}
