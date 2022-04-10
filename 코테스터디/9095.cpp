#include <iostream>
#include <cstdio>
using namespace std;

int* answer;

void GetCount(int value, int& answer);

int main()
{
	int count = 0;
	int* inputs;

	scanf("%d", &count);

	inputs = new int[count];
	answer = new int[count] {0, };

	for (int i = 0; i < count; i++)
	{
		scanf("%d", &inputs[i]);
	}

	for (int i = 0; i < count; i++)
	{
		GetCount(inputs[i], answer[i]);
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d\n", answer[i]);
	}

	return 0;
}

void GetCount(int value, int& answer)
{
	if (value < 4)
	{
		answer += value == 1 || value == 2 ? value : 4;
	}
	else
	{
		for (int i = 1; i < 4; i++)
		{
			int sub = value - i;

			if (sub < 1)
				break;

			GetCount(sub, answer);
		}
	}
}