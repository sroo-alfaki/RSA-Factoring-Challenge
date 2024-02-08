#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int n) {
	if (n <= 1) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void find_factors(int n) {
	int factors[100];
	int count = 0;

	for (int i = 2; i <= n; i++) {
		if (is_prime(i) && n % i == 0) {
			factors[count++] = i;
			n /= i;
			i--;
		}
	}

	printf("%d :", n);
	for (int i = 0; i < count; i++) {
		printf("%d ", factors[i]);
	}
	printf("\n");
}
int main()
{
	FILE* file = fopen("tests", "r");
	if (file == NULL) {
		printf("number\n");
		return 1;
	}

	char line[100];
	while (fgets(line, sizeof(line), file)) {
		int n = atoi(line);
		find_factors(n);
	}

	fclose(file);

	return 0;
}
