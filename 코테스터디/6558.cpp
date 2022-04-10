#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int GetNextDecimal(int inNum);
bool IsDecimal(int inNum);

int main()
{
	int inputNum;
	int outputA;
	int outputB;

	queue<int> outputNum;

	while (true)
	{
		outputA = 0;
		outputB = 0;

		scanf("%d", &inputNum);

		if (inputNum == 0)
		{
			break;
		}
		else if (inputNum < 6)
		{
			outputNum.push(0);
		}
		else
		{
			while (true)
			{
				outputA = GetNextDecimal(outputA);
				outputB = inputNum - outputA;

				if (outputA > outputB)
				{
					outputNum.push(0);
					break;
				}
				else if (IsDecimal(outputB))
				{
					outputNum.push(outputA);
					outputNum.push(outputB);
					break;
				}
			}
		}
	}

	while (!outputNum.empty())
	{
		outputA = outputNum.front();
		outputNum.pop();

		if (outputA == 0)
		{
			printf("Goldbach's conjecture is wrong.\n");
		}

		outputB = outputNum.front();
		outputNum.pop();

		printf("%d%s%d%s%d\n",outputA + outputB, " = ", outputA, " + ", outputB);
	}

	return 0;
}


int GetNextDecimal(int inNum)
{
	int returnVal = inNum;

	while (++returnVal)
	{
		if (IsDecimal(returnVal))
		{
			return returnVal;
		}
	}
}

bool IsDecimal(int inNum)
{
	if (inNum < 2 || inNum % 2 == 0)
		return false;

	int numSqrt = sqrt(inNum);

	for (int i = 2; i <= numSqrt; i++)
	{
		if (inNum % i == 0)
			return false;
	}

	return true;
}