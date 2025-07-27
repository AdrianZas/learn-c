#include <stdio.h>
#include <stdlib.h>

void mallocMemory () {
	int *a = (int *)malloc(sizeof(int));
	int *b = (int *)malloc(sizeof(int));
	int *c = (int *)malloc(sizeof(int));

	*a = 42;
	*b = 1337;
	*c = 7;

	printf("Adresse von a: %p, Wert: %d\n", (void *)a, *a);
	printf("Adresse von b: %p, Wert: %d\n", (void *)b, *b);
	printf("Adresse von c: %p, Wert: %d\n", (void *)c, *c);


	free(a);
	free(b);
	free(c);
}

void dynamicArrayInitialization() {

	//10 times the size of int: 40 bytes
	int *arr = malloc(10 * sizeof(int));

	if (arr == NULL) {
		printf("Memory could not be stored");
		return;
	}

	for (int i = 0; i < 10; i++) {
	        printf("arr[%d] = %d (Adresse: %p)\n", i, arr[i], (void *)&arr[i]);
    	}

	free(arr);
}

int main() {
	mallocMemory();
	dynamicArrayInitialization();
}
