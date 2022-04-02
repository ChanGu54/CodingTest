#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int GCD(int a, int b);

int main()
{
	int testCnt;
	int inputCnt;
	int inputNum;
	long long sum;

	vector<int> inputNums;
	queue<long long> outputNums;

	cin >> testCnt;

	while (testCnt--)
	{
		sum = 0;

		cin >> inputCnt;

		for (int i = 0; i < inputCnt; i++)
		{
			cin >> inputNum;
			inputNums.push_back(inputNum);
		}


		for (int i = 0; i < inputCnt; i++)
		{
			for (int j = i + 1; j < inputCnt; j++)
			{
				sum += GCD(inputNums[i], inputNums[j]);
			}			
		}

		outputNums.push(sum);
		inputNums.clear();
	}

	while (!outputNums.empty())
	{
		cout << outputNums.front() << endl;
		outputNums.pop();
	}

	return 0;
}

/// <summary>
/// 최대 공약수
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int GCD(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return GCD(b, a % b);
}