#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
/**
 * is_prime - count
 * @n: int number
 * Return: returns a pointer to a new string or NULL
 */

bool is_prime(int n)
{
	int i;

	if (n <= 1)
	{
		return (false);
	}
	if (n == 2)
	{
		return (true);
	}
	if (n % 2 == 0)
	{
		return (false);
	}
	for (i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
		{
			return (false);
		}
	}
	return (true);
}
/**
 * find_factors - count
 * @n: int number
 * Return: returns a pointer to a new string or NULL
 */
void find_factors(int n)
{
	int factors[100];
	int count = 0;
	int i;

	for (i = 2; i < n; i++)
	{
		if (is_prime(i) && n % i == 0)
		{
			factors[count++] = i;
			n /= i;
			break;
		}
	}
	factors[count++] = n;

	printf("%d = ", n);
	for (i = 0; i < count; i++)
	{
		printf("%d ", factors[i]);
	}
	printf("\n");
}
/**
 * factorize_numbers - count
 * @*file_path: int number
 * Return: returns a pointer to a new string or NULL
 */

void factorize_numbers(const char *file_path)
{
	int n;
	char line[100];

	FILE *file = fopen(file_path, "r");

	if (file == NULL)
	{
		printf("error file\n");
		return;
	}

	while (fgets(line, sizeof(line), file))
	{
		n = atoi(line);
		find_factors(n);
	}

	fclose(file);
}
/**
 * main - count
 *Return: returns a pointer to a new string or NULL
 */
int main(void)
{
	const char *file_path = ("../tests/test00");

	factorize_numbers(file_path);
	return (0);
}
