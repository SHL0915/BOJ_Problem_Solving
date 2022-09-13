#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char line[51];
	char convert[6];
	int final[51];
	int len, i, j, k, temp, start, sum = 0;
	scanf("%s", line);

	len = strlen(line);	

	j = 0;
	k = 0;
	start = 0;
	for (i = 0; i < len; i++) {
		if (line[i] == '+') {
			while (1) {
				if (line[start] == '0')
					start++;
				else
					break;
			}
			for (j = start; j < i; j++) {
				convert[j - start] = line[j];				
			}
			convert[j - start] = '\0';
			start = j + 1;
			temp = atoi(convert);			
			sum += temp;
			final[k] = sum;
		}
		else if (line[i] == '-') {
			while (1) {
				if (line[start] == '0')
					start++;
				else
					break;
			}
			for (j = start; j < i; j++) {
				convert[j - start] = line[j];				
			}
			convert[j - start] = '\0';
			start = j + 1;
			temp = atoi(convert);			
			sum += temp;
			final[k] = sum;
			sum = 0;
			final[k + 1] = -1;
			k += 2;			
		}
		else if (i == len - 1) {
			while (1) {
				if (line[start] == '0')
					start++;
				else
					break;
			}
			for (j = start; j <= i; j++) {
				convert[j - start] = line[j];
			}
			convert[j - start] = '\0';
			start = j + 1;
			temp = atoi(convert);			
			sum += temp;
			final[k] = sum;
		}
	}

	sum = final[0];
	for (i = 2; i <= k; i += 2) {
		sum -= final[i];
	}

	printf("%d", sum);
	return 0;
}