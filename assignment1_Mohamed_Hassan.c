/* #include<stdio.h>
#include<stdint.h>

void printBiggest(uint8_t, uint8_t);
void printOddOrEven(uint8_t);
uint8_t isPrime(uint8_t);
void printPowerOfTwoOrNot(uint8_t);
void printFactorial(uint8_t);
void printHasSquareRoot(uint8_t);
void printStudentResult(uint8_t);

// Bitwise
uint8_t readBit(uint8_t, int);
uint8_t setBit(uint8_t, int);
uint8_t clearBit(uint8_t, int);
uint8_t toggleBit(uint8_t, int);
uint8_t setLastTwoBits(uint8_t);
uint8_t swapBits(uint8_t, int, int);
uint32_t reverseBytes(uint32_t);
uint8_t swapAllBits(uint8_t);
void printOnesAndZeros(uint8_t);
uint8_t consecutiveZeros(uint8_t);
int multiplyBy(uint8_t);
void printIsEven(uint8_t);

// Functions
void swapValues1(uint8_t*, uint8_t*);
void swapValues2(uint8_t*, uint8_t*);
void swapValues3(uint8_t*, uint8_t*);
void swapValues4(uint8_t*, uint8_t*);
uint8_t isFirstMultipleOfSecond(int, int);
int calc(int, int, char); // a for addition, s for subtraction, m for multiplication 

int main() {
	printf("------Q1------\n");
	printf("Enter two 8 bit unsigned integers: ");
	uint8_t num1, num2;
	scanf("%d %d", &num1, &num2);
	float res = ((num1 + num2) * 3) / 2 - 10;
	printf("Result is: %.2f\n", res);

	printf("------Q2------\n");
	printBiggest(num1, num2);

	printf("------Q3------\n");
	printOddOrEven(num1);

	printf("------Q4------\n");
	isPrime(num1) ? printf("%d is a prime number\n", num1) : printf("%d is not a prime number\n", num1);
	
	printf("------Q5------\n");
	printPowerOfTwoOrNot(num1);
	
	printf("------Q6------\n");
	printFactorial(num1);
	
	printf("------Q7------\n");
	printHasSquareRoot(num1);
	
	printf("------Q8------\n");
	printf("Enter student's grade in percentage: ");
	uint8_t grade;
	scanf("%d", &grade);
	printStudentResult(grade);
	
	printf("------Q9------\n");
	printf("Prime numbers from 1 to 100 are: ");
	for (uint8_t i = 1; i <= 100; ++i) {
		if(isPrime(i)) printf("%d ", i);
	}
	printf("\n");
	
	printf("------Q10------\n");
	
	
	printf("------------------------------------Bitwise------------------------------------\n");
	printf("------Q1------\n");
	printf("Enter a 8 bit unsigned integer: ");
	uint8_t num;
	scanf("%d", &num);
	printf("The 4th bit of %d is %d\n", num, readBit(num, 3));
	
	printf("------Q2------\n");
	printf("The new value after setting the 5th bit of the number %d is: %d\n", num, setBit(num, 4));
	
	printf("------Q3------\n");
	printf("The new value after clearing the 2nd bit of the number %d is: %d\n", num, clearBit(num, 1));
	
	printf("------Q4------\n");
	printf("The new value after toggling the 6th bit of the number %d is: %d\n", num, toggleBit(num, 5));
	
	printf("------Q5------\n");
	printf("The new value after setting the last two bits of the number %d is: %d\n", num, setLastTwoBits(num));
	
	printf("------Q6------\n");
	printf("The new value after swapping the 2nd and 6th bits of the number %d is: %d\n", num, swapBits(num, 1, 5));
	
	printf("------Q7------\n");
	printf("Enter a 32 bit number: ");
	uint32_t num32;
	scanf("%d", &num32);
	printf("The new number after reversing all the bytes of the number %d is: %d\n", num, reverseBytes(num32));
	
	printf("------Q8------\n");
	printf("The new value after swapping all bits of the number %d is: %d\n", num, swapAllBits(num));
	
	printf("------Q9------\n");
	printf("The value of ones and zeros in the number %d is: ", num);
	printOnesAndZeros(num);
	
	printf("------Q10------\n");
	printf("The value of consecutive zeros between two ones in the number %d is: %d\n", num, consecutiveZeros(num));
	
	printf("------Q11------\n");
	printf("%d * 14 = %d\n", num, multiplyBy(num));
	
	printf("------Q12------\n");
	printf("%d is: ", num);
	printIsEven(num);
	
	printf("------------------------------------Functions------------------------------------\n");
	printf("------Q1------\n");
	uint8_t val1, val2;
	printf("Enter two 8 bit unsigned integers: ");
	scanf("%d %d", &val1, &val2);
	printf("The new values of the two numbers %d and %d after sawpping their values is: \n", val1, val2);
	swapValues1(&val1, &val2);
	printf("Method1: %d and %d\n", val1, val2);
	swapValues2(&val1, &val2);
	printf("Method2: %d and %d\n", val1, val2);
	swapValues3(&val1, &val2);
	printf("Method3: %d and %d\n", val1, val2);
	swapValues4(&val1, &val2);
	printf("Method4: %d and %d\n", val1, val2);
	
	printf("------Q2------\n");
	printf("%d is a multiple of %d: ", val1, val2);
	isFirstMultipleOfSecond(val1, val2) ? printf("TRUE\n") : printf("FALSE\n");
	
	printf("------Q5------\n");
	int a, b;
	char operation;
	printf("Enter two integers and an operation (+, -, *, /) to apply on: ");
	scanf("%d %d %c", &a, &b, &operation);
	printf("The result of %d %c %d is: %d\n", a, operation, b, calc(a, b, operation));
} */

/* void printBiggest(uint8_t num1, uint8_t num2) {
	if (num1 < num2) {
		printf("%d is the biggest\n", num2);
	} else if (num1 == num2) {
		printf("Both numbers are equal\n");
	} else {
		printf("%d is the biggest\n", num1);
	}
}

void printOddOrEven(uint8_t num) {
	num % 2 == 0 ? printf("%d is even\n", num) : printf("%d is odd\n", num);
}

uint8_t isPrime(uint8_t num) {
	if (num == 1) {
		return 1;
	}

	for(size_t i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return 0;
		}
	}

	return 1;
}

void printPowerOfTwoOrNot(uint8_t num) {
	if (num <= 2) {
		printf("%d is not a power of 2\n", num);
		return;
	}
	
	uint8_t base = 2;
	while (base < num) {
		base *= 2;
		if (base == num) {
			printf("%d is a power of 2\n", num);
			return;
		}
		
		if (base > num) {
			printf("%d is not a power of 2\n", num);
			return;		
		}
	}
}

void printFactorial(uint8_t num) {
	if (num == 0 | num == 1) {
		printf("Factorial of %d is : 1\n", num);
		return;
	}
	
	int factN_1 = 1;
	int factN;
	for (uint8_t n = 2; n <= num; ++n) {
		factN = n * factN_1;
		factN_1 = factN;
	}
	printf("Factorial of %d is : %d\n", num, factN);
	return;
}

void printHasSquareRoot(uint8_t num) {
	if (num < 0) {
		printf("%d has no perfect square root\n", num);
		return;
	}
	
	uint8_t root = 0;
	while (root * root <= num) {
		if(root * root == num) {
			printf("%d has a perfect square root\n", num);
			return;
		}
		++root;
	}
	printf("%d has no perfect square root\n", num);
	return;
}

void printStudentResult(uint8_t grade) {
	if (grade >= 85) {
		printf("Excellent\n");
		return;
	}
	
	if (grade >= 75) {
		printf("Very Good\n");
		return;
	}
	
	if (grade >= 65) {
		printf("Good\n");
		return;
	}
	
	if (grade >= 50) {
		printf("Pass\n");
		return;
	}
	
	printf("Fail\n");
	return;
}

uint8_t readBit(uint8_t num, int position) {
	return (num & (1 << position)) != 0;
}

uint8_t setBit(uint8_t num, int position) {
	return num | (1 << position);
}

uint8_t clearBit(uint8_t num, int position) {
	return num & ~(1 << position);
}

uint8_t toggleBit(uint8_t num, int position) {
	return num ^ (1 << position);
}

uint8_t setLastTwoBits(uint8_t num) {
	return num | (1 << 6) | (1 << 7);
}

uint8_t swapBits(uint8_t num, int pos1, int pos2) {
	uint8_t bit1 = readBit(num, pos1);
	// printf("The bit at %d is: %d\n", pos1, bit1);
	uint8_t bit2 = readBit(num, pos2);
	// printf("The bit at %d is: %d\n", pos2, bit2);
	
	if (bit1 ^ bit2) {
		num = toggleBit(num, pos1);
		// printf("The new bit at %d is: %d\n", pos1, readBit(num, pos1));
		num = toggleBit(num, pos2);
		// printf("The new bit at %d is: %d\n", pos2, readBit(num, pos2));
	}
	
	return num;
}

uint32_t reverseBytes(uint32_t num) {
    return ((num & 0x000000FF) << 24) |
           ((num & 0x0000FF00) << 8)  |
           ((num & 0x00FF0000) >> 8)  |
           ((num & 0xFF000000) >> 24);
}

uint8_t swapAllBits(uint8_t num) {
	uint8_t bitWidth = 8;
	uint8_t res = num;
	for (uint8_t i = 0; i < bitWidth; ++i) {
		res = swapBits(res, i, --bitWidth);
	}
	
	return res;
}

void printOnesAndZeros(uint8_t num) {
	uint8_t ones = 0;
	uint8_t zeros = 0;
	uint8_t bitWidth = 8;
	for (uint8_t i = 0; i < bitWidth; ++i) {
		readBit(num, i) ? ++ones : ++zeros;
	}
	
	printf("0s: %d, 1s: %d\n", zeros, ones);
}

uint8_t consecutiveZeros(uint8_t num) {
	uint8_t zeros = 0;
	uint8_t bitWidth = 8;
	uint8_t bitValue = 0;
	for (uint8_t i = 0; i < bitWidth; ++i) {
		bitValue = readBit(num, i);
		
		if(!bitValue) {
			++zeros;
		}
		
		if (0 < zeros && bitValue) {
			break;
		}
	}
	
	return zeros;
}

int multiplyBy(uint8_t num) {
	return (num << 4) - (num << 1); // num * 14 = num * (16 - 2) = num * 2power4 - num * 2power1
}

void printIsEven(uint8_t num) {
	readBit(num, 0) ? printf("odd\n") : printf("even\n");
}

void swapValues1(uint8_t *num1, uint8_t *num2) {
	uint8_t temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swapValues2(uint8_t *num1, uint8_t *num2) {
	uint8_t bitNum1, bitNum2 = 0;
	uint8_t bitWidth = 8;
	for(size_t i = 0; i < bitWidth; ++i) {
		bitNum1 = readBit(*num1, i);
		bitNum2 = readBit(*num2, i);
		if (bitNum1 ^ bitNum2) {
			*num1 = toggleBit(*num1, i);
			*num2 = toggleBit(*num2, i);
		}
	}
}

void swapValues3(uint8_t* num1, uint8_t* num2) {
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}

void swapValues4(uint8_t* num1, uint8_t* num2) {
	*num1 = *num1 + *num2;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}

uint8_t isFirstMultipleOfSecond(int numerator, int divisor) {
	if (divisor != 0) return numerator % divisor == 0;
	return 0;
}

int calc(int val1, int val2, char operation) {
	switch (operation) {
		case '+':
			return val1 + val2;
			break;
		case '-':
			return val1 - val2;
			break;
		case '*':
			return val1 * val2;
			break;
		case '/':
			if (val2 != 0) {
				return val1 / val2;
			}
			fprintf(stderr, "Invalid input. Please enter a valid devisor.\n");
			return -1;
		default:
			fprintf(stderr, "Invalid input. Please enter a valid operation.\n");
			return -1;
	}
} */
