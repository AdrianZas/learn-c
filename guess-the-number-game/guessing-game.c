#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int cmpNumbers(int num, int userNum) {
	if (num == userNum) {
		return 0;
	} else if (userNum < (num - 10) || userNum > (num + 10)) {
		return 1;
	} else {
		return 2;
	}
}

int generateNumber() {
	srand(time(NULL));
	return rand() % 100 + 1;

}

int main() {
	int num = generateNumber();
	int userNum;

	while (true) {
		printf("Guess the Number!\n");
		scanf("%d", &userNum);
		int guess = cmpNumbers(num, userNum);
		if (guess == 0) {
			printf("You guessed it right!\n");
			break;
		}
		if (guess == 1) {
			printf("Cold!\n");

		}
		if (guess == 2) {
			printf("Hot!\n");

		}
	}
	return 0;
}
