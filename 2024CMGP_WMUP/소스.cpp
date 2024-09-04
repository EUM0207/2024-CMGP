#define _CRT_SECURET_NO_WARNINGS



#define PROB 1



#if PROB == 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

void generate_matrix(int matrix[SIZE][SIZE]);	//행렬 생성
void print_matrix01(int matrix[SIZE][SIZE]);	//행렬 한개 출력
void print_matrix02(int matrix01[SIZE][SIZE], int matrix02[SIZE][SIZE]);		//행렬 두개 출력

void a_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]); //덧셈
void d_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]); //뺄셈
void m_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]); //곱셈

int main() {
	int matrix01[SIZE][SIZE], matrix02[SIZE][SIZE];
	int result[SIZE][SIZE];
	char command[20];
	
	srand(time(NULL));

	generate_matrix(matrix01);
	generate_matrix(matrix02);

	print_matrix02(matrix01, matrix02);

	while (1) {
		printf("\nInput Command : ");
		if (fgets(command, sizeof(command), stdin) != NULL) {
			command[strcspn(command, "\n")] = '\0';
		}
		
		//곱셈
		if (strcmp(command, "m") == 0) {
			m_matrix(matrix01, matrix02, result);
			printf("result: \n");
			print_matrix01(result);
		}
		//덧셈
		else if (strcmp(command, "a") == 0) {
			a_matrix(matrix01, matrix02, result);
			printf("result: \n");
			print_matrix01(result);
		}
		//뺄셈
		else if (strcmp(command, "d") == 0) {
			d_matrix(matrix01, matrix02, result);
			printf("result: \n");
			print_matrix01(result);
		}
		//2개의 행렬의 행렬식 값 모두 출력
		else if (strcmp(command, "r") == 0) {
		}
		//2개의 행렬의 전치 행렬(Transposed matrix)과 그 행렬식의 값 모두 출력
		else if (strcmp(command, "t") == 0) {
		}
		//행렬의 짝수 값만 출력 -> 다시 누르면 홀수 -> 다시 누르면 원래대로 출력
		else if (strcmp(command, "e") == 0) {
		}
		//행렬의 값을 새로 랜덤하게 설정
		else if (strcmp(command, "s") == 0) {
		}
		//입력한 숫자(1~9)를 행렬에 곱한다.
		else if (strcmp(command, "1") == 0 || strcmp(command, "2") == 0 ||
			     strcmp(command, "3") == 0 || strcmp(command, "4") == 0 ||
			     strcmp(command, "5") == 0 || strcmp(command, "6") == 0 ||
			     strcmp(command, "7") == 0 || strcmp(command, "8") == 0 ||
			     strcmp(command, "9") == 0) {
		}
		
		//프로그램 종료
		else if (strcmp(command, "q") == 0) {
			printf("Stop Program.\n");
			break;
		}
		//잘못된 명령어
		else {
			printf("Wrong Order: try again...\n");
		}

	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//행렬을 한개 출력
void print_matrix01(int matrix[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//행렬을 두개 출력
void print_matrix02(int matrix01[SIZE][SIZE], int matrix02[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%3d ", matrix01[i][j]);
		}
		printf("\t");
		for (int j = 0; j < SIZE; j++) {
			printf("%3d ", matrix02[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//행렬 생성
void generate_matrix(int matrix[SIZE][SIZE]) {
	int value[SIZE * SIZE];
	int index = 0;

	//행렬에 2를 단 두개만 넣는 과정
	for (int i = 0; i < SIZE * SIZE; i++) {
		if (i < 2) {
			value[i] = 2;
		}
		else {
			value[i] = rand() % 2;
		}
	}
	//행렬에 값 랜덤 배치
	for (int i = 0; i < SIZE * SIZE; i++) {
		int j = rand() % (SIZE * SIZE);
		int t = value[i];
		value[i] = value[j];
		value[j] = t;
	}
	//행렬 값 할당
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = value[index++];
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//행렬 곱셈 (m)
void m_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[i][j] = 0;
			for (int k = 0; k < SIZE; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
//행렬 덧셈 (a)
void a_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
}
//행렬 뺄셈 (d)
void d_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[i][j] = a[i][j] - b[i][j];
		}
	}
}

#elif PROB == 2

#elif PROB == 3

#endif