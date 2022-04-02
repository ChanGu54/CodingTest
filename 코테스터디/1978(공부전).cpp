#include <iostream>
using namespace std;

int main()
{
	int inputCount;
	int inputNum;
	int decimalCount;

	cin >> inputCount;
	decimalCount = inputCount;

	for (int i = 0; i < inputCount; i++)
	{
		cin >> inputNum;

		if (inputNum > 1)
		{
			for (int j = 2; j <= inputNum / 2; j++)
			{
				if ((inputNum / j) * j == inputNum)
				{
					decimalCount--;
					break;
				}
			}
		}
		else
			decimalCount--;
	}

	cout << decimalCount;

	return 0;
}