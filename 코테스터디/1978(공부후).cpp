#include <iostream>
#include <cmath>
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
			int inputSqrt = sqrt(inputNum);

			for (int j = 2; j <= inputSqrt; j++)
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