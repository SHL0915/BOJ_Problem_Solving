#include <stdio.h>

#include <stdlib.h>

void Merge(int Arr[],int temp[], int left, int right, int right_end){

	int i, j, pos;	i = left;

	j = right;

	pos = left;

	while((i<right)&&(j<=right_end)){

		if(Arr[i]<=Arr[j]){

			temp[pos]=Arr[i];

			i++;

			pos++;

		}

		else

		{

			temp[pos]=Arr[j];

			j++;

			pos++;

		}

	}

	while(i<right)

	{

		temp[pos]=Arr[i];

			i++;

			pos++;

	}

	while(j<=right_end)

	{

		temp[pos]=Arr[j];

			j++;

			pos++;

	}

	for(i=left;i<=right_end;i++)

	{

		Arr[i] = temp[i];

	}

}	

	

void MergeSort(int Arr[], int temp[], int left, int right_end){

	int mid = (left + right_end)/2;

	if(left < right_end){

		MergeSort(Arr, temp, left, mid);

		MergeSort(Arr, temp, mid+1, right_end);

		Merge(Arr,temp,left,mid+1, right_end);

	}

}

int main(void){

	int Arr[9];

	int temp[9];

	int i, j, k;

	int sum;

	for(i=0;i<9;i++){

		scanf("%d",&Arr[i]);

	}

	MergeSort(Arr,temp,0,8);

	for(i=0;i<9;i++){

		for(j=0;j<9;j++)

		{

			sum=0;

			if(j == i)

				continue;

			for(k=0;k<9;k++){

				if((k==i)||(k==j))

				continue;

				else

				{

					sum += Arr[k];

				}

			}

			if(sum == 100){

				for(k=0;k<9;k++){

					if((k!=i)&&(k!=j))

					{

						printf("%d\n",Arr[k]);

					}

				}

				return 0;

			}

		}

	}

	return 0;

	

}