#include<stdio.h>
#include<string.h>

void print_arr(int* arr, size_t size) {
	for(size_t i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void lower_to_upper(char*);
size_t str_len(const char*);
void str_cpy(char*, const char*);
int str_cmp(const char*, const char*);
void str_reverse(char* str);
char check_mirror(const char*);
void sort_ascending(int*, const size_t);
void sort_descending(int*, const size_t);
int max(const int*, const size_t);
int min(const int*, const size_t);
float average(const int*, const size_t);
size_t find(const int*, const int, const size_t);
int second_largest(const int*, const size_t);
void arr_reverse(int*, const size_t);
size_t remove_duplicates(const int*, const size_t, int*);
int most_occurance(const int*, const size_t);
size_t max_consecutive(int*, size_t);

typedef struct student {
	size_t id;
	char name[20];
	int grades[10];
} Student;

typedef struct time {
	size_t hours;
	size_t minutes;
	size_t seconds;
} Time;

Time time_difference(const Time time1, const Time time2) {
	Time time;
	time.hours = time2.hours - time1.hours;
	time.minutes = time2.minutes - time1.minutes;
	time.seconds = time2.seconds - time1.seconds;
	
	return time;
}

int main() {
	char str[] = "lowercase";
	
	lower_to_upper(str);
	printf("%s\n", str);
	
	str_len(str);
	printf("The lenght of the string using pointers is: %ld\n", str_len(str));
	printf("The lenght of the string using string library is: %ld\n", strlen(str));
	
	char destination_str[10] = "";
	str_cpy(destination_str, str);
	printf("The destination_str using pointers is: %s\n", destination_str);
	printf("The destination_str using string library is: %s\n", strcpy(destination_str, str));
	
	printf("Comparing strings using pointers against using string library:\n");
	if (str_cmp(str, destination_str) == strcmp(str, destination_str)) printf("The two strings are equal\n");
	if (str_cmp(str, "LOWERCASE1") == strcmp(str, "LOWERCASE1")) printf("The 1st string is shorter\n");
	if (str_cmp(str, "LOWERCAS") == strcmp(str, "LOWERCAS")) printf("The 1st string is longer\n");
	
	printf("The string %s reversed is: ", str);
	str_reverse(str);
	printf("%s\n", str);
	
	char not_mirror[] = "momo";
	check_mirror(not_mirror) ? printf("The string '%s' is a mirror to itself\n", not_mirror) : printf("This string '%s' is not a mirror to itself\n", not_mirror);
	char mirror[] = "mum";
	check_mirror(mirror) ? printf("This string '%s' is a mirror to itself\n", mirror) : printf("This string '%s' is not a mirror to itself\n", mirror);
	
	int num = 0xaabbccff;
 	unsigned char *ptr = (unsigned char*)&num;

	*ptr == 0xff ? printf("Little Endian\n"): printf("Big Endian\n");
	
	int arr[] = {0, -5, 10, 15, 11, 1, -15};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	printf("The array: ");
	print_arr(arr, size);
	printf("After ascending order sorting: ");
	sort_ascending(arr, size);
	print_arr(arr, size);
	int arr2[] = {-15, 100, 0, -2, -10, 50, 2, 4, 4, -15};
	size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("The array: ");
	print_arr(arr2, size2);
	printf("After descending order sorting: ");
	sort_descending(arr2, size2);
	print_arr(arr2, size2);
	
	printf("The max number of the array: ");
	print_arr(arr2, size2);
	printf("%d\n", max(arr2, size2));
	printf("The min number of the array ");
	print_arr(arr, size);
	printf("%d\n", min(arr, size));
	
	printf("The average value of the array ");
	print_arr(arr, size);
	printf("%.2f\n", average(arr, size));
	
	size_t idx = find(arr, 15, size);
	idx < 0 ? printf("The number 15 was not found in the array\n") : printf("The number 15 was found at the index %ld\n", idx);
	
	printf("The second largest element of the array: ");
	int arr3[] = {60, 10, -50, 6, 0, 0, 200, 10, 90};
	size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
	print_arr(arr3, size3);
	printf("is %d\n", second_largest(arr3, size3));
	
	printf("The reverse of the array: ");
	print_arr(arr3, size3);
	printf("is: ");
	arr_reverse(arr3, size3);
	print_arr(arr3, size3);
	
	int new_arr[size3];
	size_t new_size = remove_duplicates(arr3, size3, new_arr);
	printf("The new array without duplicates is: ");
	print_arr(new_arr,new_size);
	
	printf("The most frequent element of the array: ");
	print_arr(arr3, size3);
	printf("is: %d\n", most_occurance(arr3, size3));
	
	int arr4[] = {1, 1, 1, 5, 5, 5, 3, 3, 5, 5, 5, 5};
	size_t size4 = sizeof(arr4) / sizeof(arr4[0]);
	printf("The max number of consecutive elements of the array: ");
	print_arr(arr4, size4);
	printf("is: %ld\n", max_consecutive(arr4, size4));
	
	Student student1 = {1, "student1", {0}};
	Time now = {10, 30, 30};
	Time now2 = {11, 0, 30};
	
	Time time_diff = time_difference(now, now2);
	printf("The time difference is: %ld:%ld:%ld\n", time_diff.hours, time_diff.minutes, time_diff.seconds);
	
	return 0;
}

void lower_to_upper(char* str) {
	while(*str) {
		if(*str >= 'a' && *str <= 'z') *str -= 32;
		
		++str;
	}
}

size_t str_len(const char* str) {
	const char* ptr = str;
	while(*ptr) ++ptr;
	
	return ptr - str;
}

void str_cpy(char* destination, const char* origin) {
	while(*origin) {
		*destination = *origin;
		
		++origin;
		++destination;
	}
}

int str_cmp(const char* str1, const char* str2) {
	while(*str1) {
		if (*str1 != *str2) break;
		
		++str1;
		++str2;
	}
	
	return *str1 - *str2;
}

void str_reverse(char* str) {
	char* end = str + str_len(str) - 1;
	char temp;
	while(str < end) {
		temp = *str;
		*str = *end;
		*end = temp;
		
		++str;
		--end;
	}
}

char check_mirror(const char* str) {
	const char* end = str + str_len(str) - 1;
	while(str < end) {
		if(*str != *end) return 0;
		
		++str;
		--end;
	}
	
	return 1;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_ascending(int* arr, const size_t size) {
    int* start = NULL;
    int* ptr = NULL;
    for (size_t window = 1; window < size; ++window) {
    	start = arr;
    	ptr = start + window;
    	
    	// Early termination: if element is already in correct position
        if (*(ptr - 1) <= *ptr) {
            continue;  // Skip this iteration entirely
        }
        
        while(start < ptr) {
            if(*ptr < *start) swap(ptr, start);
            
            ++start;
        }
    }
}

void sort_descending(int* arr, const size_t size) {
    int* start = NULL;
    int* ptr = NULL;
    for (size_t window = 1; window < size; ++window) {
    	start = arr;
    	ptr = start + window;
    	
    	// Early termination: if element is already in correct position
        if (*(ptr - 1) >= *ptr) {
            continue;  // Skip this iteration entirely
        }
        
        while(start < ptr) {
            if(*ptr > *start) swap(ptr, start);
            
            ++start;
        }
    }
}

int max(const int* ptr, const size_t size) {
	int largest = ptr[0];
	
	for (size_t i = 0; i < size; ++i) {
		int value = ptr[i];
		if (largest < value) {
			largest = value;
		}
	}
	
	return largest;
}

int min(const int* ptr, const size_t size) {
	int smallest = ptr[0];
	
	for (size_t i = 0; i < size; ++i) {
		int value = ptr[i];
		if (smallest > value) {
			smallest = value;
		}
	}
	
	return smallest;
}

float average(const int* ptr, const size_t size) {
	float sum = 0;
	
	for (size_t i = 0; i < size; ++i) {
		sum += ptr[i];
	}
	
	return sum / size;
}

size_t find(const int* ptr, const int num, const size_t size) {	
	const int* start = ptr;
	
	while(start < ptr + size) {
		if (*start == num) return start - ptr;
		
		++start;
	}
	
	return -1;
}

int second_largest(const int* ptr, const size_t size) {
	int max[2] = {ptr[0], ptr[1]};
	for (size_t i = 1; i < size; ++i) {
		if (max[0] < ptr[i]) {
			max[1] = max[0];
			max[0] = ptr[i];
		} else if (max[1] < ptr[i]) {
			max[1] = ptr[i];
		}
		
	}
	
	return max[1];
}

void arr_reverse(int* ptr, const size_t size) {
	int* start = ptr;
	int* end = ptr + size - 1;
	int temp = 0;
	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;
		
		++start;
		--end;
	}
}

size_t remove_duplicates(const int* ptr, const size_t size, int* new_arr) {
    if (size == 0) return 0;

    *new_arr = ptr[0];
    size_t new_size = 1;

    for (size_t i = 1; i < size; ++i) {
        if (find(new_arr, ptr[i], new_size) == -1) {
            new_arr[new_size++] = ptr[i];
        }
    }

    return new_size;
}

int most_occurance(const int* ptr, const size_t size) {
	size_t max_count = 0;
	int most_frequent = *ptr;
	size_t count = 0;
	
	for(size_t i = 0; i < size; ++i) {
		count = 0;
		for (size_t j = 0; j < size; ++j) {
			if (ptr[i] == ptr[j]) ++count;
		}
		
		if (count > max_count) {
			max_count = count;
			most_frequent = ptr[i];
		}
	}
	
	return most_frequent;
}

size_t max_consecutive(int* ptr, size_t size) {
	size_t count = 1;
	size_t max_count = 1;
	for (size_t i = 1; i < size; i++) {
		if (ptr[i] == ptr[i - 1]) {
			++count;
		} else {
			if (count > max_count) max_count = count;
			count = 1;
		}
	}
	
	if (count > max_count) max_count = count;
	
	return max_count;
}

// pointer to int: int* ptr;
// pointer to pointer to int: int** dprt;
// pointer to array of 10 elements of int: int (*aptr)[10];
// Pointer to function which take 2 int and return void: void (*fptr)(int, int);
// Array of 20 pointer to int: int* ptrs[20];
// Array of 10 pointer to function: void (*fptrs[10])();
// Pointer to const int: const int* cptr;
// Pointer to constant pointer: int* const cppointer;

// Function that take 2 dimensional array and return the address of 1 dimensional array.
/*
int (*func(int* arr[][4]))[4];
*/

// Function that takes two variables and returns the biggest one
/*
int func(int a, int b);
*/

// Call back function that take pointer to long and pointer to function (the function return pointer to integer and take char).
/*
void callback(*long, int* (*)(char));
*/
