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
int r_matrix(int a[SIZE][SIZE], int n); //행렬식 계산
void t_matrix(int a[SIZE][SIZE], int result[SIZE][SIZE]); //전치 행렬 계싼

int main() {
	int matrix01[SIZE][SIZE], matrix02[SIZE][SIZE];
	int result[SIZE][SIZE];
	char command[20];
	int e_mode = 0; //짝수,홀수 모드 (0: 원래, 1: 짝, 2: 홀)
	
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
			printf("matrix01 = %d\n", r_matrix(matrix01, SIZE));
			printf("matrix02 = %d\n", r_matrix(matrix02, SIZE));
		}
		//2개의 행렬의 전치 행렬(Transposed matrix)과 그 행렬식의 값 모두 출력
		else if (strcmp(command, "t") == 0) {
			t_matrix(matrix01, result);
			print_matrix01(result);
			printf("t_matrix01 = %d\n\n", r_matrix(result, SIZE));

			t_matrix(matrix02, result);
			print_matrix01(result);
			printf("t_matrix02 = %d\n", r_matrix(result, SIZE));
		}
		else if (strcmp(command, "e") == 0) {
			e_mode = (e_mode + 1) % 3; // 모드 변경 (0: 원래, 1: 짝수만, 2: 홀수만)

			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					// matrix01 출력
					if (e_mode == 1 && (matrix01[i][j] % 2 == 0)) { // 짝수만 출력
						printf("%3d ", matrix01[i][j]);
					}
					else if (e_mode == 2 && (matrix01[i][j] % 2 != 0)) { // 홀수만 출력
						printf("%3d ", matrix01[i][j]);
					}
					else if (e_mode == 0) { // 원래대로 출력
						printf("%3d ", matrix01[i][j]);
					}
					else { // 해당 모드에 맞지 않으면 빈 칸 출력
						printf("    ");
					}
				}

				printf("\t"); // 두 행렬 사이의 공백

				for (int j = 0; j < SIZE; j++) {
					// matrix02 출력
					if (e_mode == 1 && (matrix02[i][j] % 2 == 0)) { // 짝수만 출력
						printf("%3d ", matrix02[i][j]);
					}
					else if (e_mode == 2 && (matrix02[i][j] % 2 != 0)) { // 홀수만 출력
						printf("%3d ", matrix02[i][j]);
					}
					else if (e_mode == 0) { // 원래대로 출력
						printf("%3d ", matrix02[i][j]);
					}
					else { // 해당 모드에 맞지 않으면 빈 칸 출력
						printf("    ");
					}
				}
				printf("\n");
			}
			printf("\n");
		}
		//행렬의 값을 새로 랜덤하게 설정
		else if (strcmp(command, "s") == 0) {
			generate_matrix(matrix01);
			generate_matrix(matrix02);
			print_matrix02(matrix01, matrix02);
		}
		//입력한 숫자(1~9)를 행렬에 곱한다.
		else if (strcmp(command, "1") == 0 || strcmp(command, "2") == 0 ||
			     strcmp(command, "3") == 0 || strcmp(command, "4") == 0 ||
			     strcmp(command, "5") == 0 || strcmp(command, "6") == 0 ||
			     strcmp(command, "7") == 0 || strcmp(command, "8") == 0 ||
			     strcmp(command, "9") == 0) {
			int num = atoi(command);
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					matrix01[i][j] *= num;
					matrix02[i][j] *= num;
				}
			}
			printf("matrix01 multiplied by %d: \n", num);
			print_matrix01(matrix01);
			printf("matrix01 multiplied by %d: \n", num);
			print_matrix01(matrix02);
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
//행렬식 계산 (r)
void get_cofactor(int matrix[SIZE][SIZE], int temp[SIZE][SIZE], int p, int q, int n) {
	int i = 0, j = 0;

	// 현재 행(p)과 열(q)을 제외한 소행렬식 생성
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			// 행과 열을 제외한 요소만 임시 배열 temp에 저장
			if (row != p && col != q) {
				temp[i][j++] = matrix[row][col];

				// 한 행이 다 채워지면 다음 행으로 넘어감
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}
int r_matrix(int matrix[SIZE][SIZE], int n) {
	int det = 0;

	// 행렬이 1x1인 경우 행렬식은 해당 원소 자체
	if (n == 1) {
		return matrix[0][0];
	}

	int temp[SIZE][SIZE]; // 소행렬식 저장할 임시 행렬
	int sign = 1; // +와 - 기호 관리

	// 첫 번째 행을 기준으로 소행렬식을 계산하여 행렬식을 구함
	for (int f = 0; f < n; f++) {
		// 소행렬식 계산
		get_cofactor(matrix, temp, 0, f, n);
		// 행렬식 재귀 계산
		det += sign * matrix[0][f] * r_matrix(temp, n - 1);

		// 기호 변경
		sign = -sign;
	}

	return det;
}
//전치 행렬 계산 (t)
void t_matrix(int a[SIZE][SIZE], int result[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[i][j] = a[j][i];
		}
	}
	}

#elif PROB == 2

#elif PROB == 3

#endif