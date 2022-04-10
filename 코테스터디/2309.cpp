#include <cstdio>
#include <iostream>
#include <vector>

#define MAX_SIZE 9
#define ANSWER 100

int* sorted = new int[9];

using namespace std;

void Merge_Sort(int list[], int left, int right);
void Merge(int list[], int left, int mid, int right);
void FindAnswer(int twoSum, int& excludeIdx1, int& excludeIdx2);

int main()
{
	int* height = new int[9];
	int heightSum = 0;

    int excludeIdx1, excludedIdx2 = 0;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &height[i]);
        heightSum += height[i];
    }

    int twoSum = heightSum - ANSWER;

    Merge_Sort(height, 0, MAX_SIZE - 1);
    FindAnswer(twoSum, excludeIdx1, excludedIdx2);

    for (int i = 0; i < 9; i++)
    {
        if (i == excludeIdx1 || i == excludedIdx2)
        {
            continue;
        }

        printf("%d\n", sorted[i]);
    }


	delete[] height;
	delete[] sorted;

	return 0;
}

void Merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }

    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}


void Merge_Sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        Merge_Sort(list, left, mid); 
        Merge_Sort(list, mid + 1, right);
        Merge(list, left, mid, right); 
    }
}

void FindAnswer(int twoSum, int& excludeIdx1, int& excludeIdx2)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            if (sorted[i] + sorted[j] > twoSum)
            {
                break;
            }

            if (sorted[i] + sorted[j] == twoSum)
            {
                excludeIdx1 = i;
                excludeIdx2 = j;

                return;
            }
        }
    }
}