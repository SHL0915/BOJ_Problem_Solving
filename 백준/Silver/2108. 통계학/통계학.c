#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int temp[], int left, int right, int right_end)
{
	int i, j, temp_pos;
	i = left;
	j = right;
	temp_pos = left;

	while ((i <= right - 1) && (j <= right_end))
	{
		if (A[i] < A[j])
		{
			temp[temp_pos] = A[i];
			i++;
			temp_pos++;
		}
		else
		{
			temp[temp_pos] = A[j];
			temp_pos++;
			j++;
		}
	}
	while (i <= right - 1)
	{
		temp[temp_pos] = A[i];
		i++;
		temp_pos++;
	}
	while (j <= right_end)
	{
		temp[temp_pos] = A[j];
		temp_pos++;
		j++;
	}

	for (i = left; i <= right_end; i++)
	{
		A[i] = temp[i];
	}
	return;
}

void MergeSort(int A[], int temp[], int left, int right_end)
{
	int mid;
	if (right_end > left)
	{
		mid = (right_end + left) / 2;
		MergeSort(A, temp, left, mid);
		MergeSort(A, temp, mid + 1, right_end);
		Merge(A, temp, left, mid + 1, right_end);
	}
	return;
}

int main(void)
{
	int N;
	int Median;
	double average;
	int sum = 0;
	int mode;
	int range;

	int* Arr;
	int* temp;
	int count[8001] = { 0 };
	int max, flag;

	int i;

	scanf("%d", &N);

	Arr = (int*)malloc(sizeof(int) * N);
	temp = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &Arr[i]);
		sum += Arr[i];
	}

	MergeSort(Arr, temp, 0, N - 1);

	free(temp);


	average = (double)sum / N;
	if (average < 0)
	{
		average -= 0.5;
	}
	else average += 0.5;
	range = Arr[N - 1] - Arr[0];
	Median = Arr[(N - 1) / 2];

	if (Arr[0] < 0) {
		for (i = 0; i < N; i++)
		{
			count[Arr[i] - Arr[0]]++;
		}
	}
	else {
		for (i = 0; i < N; i++)
		{
			count[Arr[i]]++;
		}
	}


	max = 0;
	flag = 0;

	for (i = 0; i < 8001; i++)
	{
		if (count[i] >= max)
			max = count[i];
	}


	for (i = 0; i < 8001; i++)
	{
		if (count[i] == max) {
			mode = i;
			flag++;
		}			
	}

	if (flag == 1)
	{
		if (Arr[0] < 0)
			mode = mode + Arr[0];
		else mode = mode;
	}
	else
	{
		flag = 0;
		for (i = 0; i < 8001; i++)
		{
			if (count[i] == max) {
				if (flag == 1)
				{
					if (Arr[0] < 0)
					{
						mode = i + Arr[0];
						break;
					}
					else
					{
						mode = i;
						break;
					}
				}
				else flag = 1;
			}
		}
	}

	
	printf("%d\n%d\n%d\n%d", (int)average, Median, mode, range);
	return 0;
}