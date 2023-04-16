#include <stdio.h>
#include <string.h>

void bitStuffing(int N, int arr[])
{

	int brr[30];
	int i, j, k;
	i = 0;
	j = 0;
	while (i < N) {
		if (arr[i] == 1) {
			int count = 1;
			brr[j] = arr[i];
			for (k = i + 1; arr[k] == 1 && k < N && count < 5; k++) 
			{
				j++;
				brr[j] = arr[k];
				count++;
				if (count == 5)
				{
					j++;
					brr[j] = 0;
				}
				i = k;
			}
		}
		else 
		{
			brr[j] = arr[i];
		}
		i++;
		j++;
	}
	printf("The New array after bit stuffing is: \n");
	for (i = 0; i < j; i++)
		printf("%d ", brr[i]);
		printf("\n");
}

int main()
{	
	int i;
	int N;
	int arr[10];
	printf("Enter the array size: \n");
	scanf("%d", &N);
	printf("Enter the array: \n");
	for(i=0;i<N;i++)
	scanf("%d", &arr[i]);

	bitStuffing(N, arr);

	return 0;
}

