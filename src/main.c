/*	@authour: Ronald Tavarez
 *	@date: 2023-05-08
 *	@description: A small program that uses a sieve of eratosthenes 
 *	implementation to generate an array of prime numbers up to a user defined limit;
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MINIMUM_ARGUMENT_COUNT 2
#define MINIMUM_LIMIT_SIZE 1

bool initialize_arguments(const int * argc, char ** argv);
void sieve_of_eratosthenes(size_t limit);

int main(int argc, char ** argv) {
	if (!initialize_arguments(&argc, argv)) { return EXIT_FAILURE; }
	sieve_of_eratosthenes(atoi(argv[1]));
	return EXIT_SUCCESS;
}

bool initialize_arguments(const int * argc, char ** argv) {
	if (*argc < MINIMUM_ARGUMENT_COUNT) { 
		fprintf(stderr, "Usage: prime (1..=N)");
		return false;
	}

	if (atoi(argv[1]) < MINIMUM_LIMIT_SIZE) {
		fprintf(stderr, "number_array_length must be within range (1..=N)");
		return false;
	}
	
	return true;
}

void sieve_of_eratosthenes(size_t limit) {
	bool prime[limit + 1];
	memset(prime, true, sizeof(prime));

	for (size_t i = 2; (i * i) <= limit; i++) {
		if (prime[i] == true) {
			for (size_t j = (i * i); j <= limit; j += i) {
				prime[j] = false;
			}
		}
	}
	
	printf("[ ");
	for (size_t i = 2; i <= limit; i++) {
		if (prime[i]) {
			printf("%d, ", i);
		} 
	}
	printf(" ]\n");
}
