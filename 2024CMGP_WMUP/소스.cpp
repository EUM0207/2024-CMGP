#define _CRT_SECURET_NO_WARNINGS



#define PROB 1



#if PROB == 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

void generate_matrix(int matrix[SIZE][SIZE]);	//��� ����
void print_matrix01(int matrix[SIZE][SIZE]);	//��� �Ѱ� ���
void print_matrix02(int matrix01[SIZE][SIZE], int matrix02[SIZE][SIZE]);		//��� �ΰ� ���

void a_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]); //����
void d_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]); //����
void m_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]); //����

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
		
		//����
		if (strcmp(command, "m") == 0) {
			m_matrix(matrix01, matrix02, result);
			printf("result: \n");
			print_matrix01(result);
		}
		//����
		else if (strcmp(command, "a") == 0) {
			a_matrix(matrix01, matrix02, result);
			printf("result: \n");
			print_matrix01(result);
		}
		//����
		else if (strcmp(command, "d") == 0) {
			d_matrix(matrix01, matrix02, result);
			printf("result: \n");
			print_matrix01(result);
		}
		//2���� ����� ��Ľ� �� ��� ���
		else if (strcmp(command, "r") == 0) {
		}
		//2���� ����� ��ġ ���(Transposed matrix)�� �� ��Ľ��� �� ��� ���
		else if (strcmp(command, "t") == 0) {
		}
		//����� ¦�� ���� ��� -> �ٽ� ������ Ȧ�� -> �ٽ� ������ ������� ���
		else if (strcmp(command, "e") == 0) {
		}
		//����� ���� ���� �����ϰ� ����
		else if (strcmp(command, "s") == 0) {
		}
		//�Է��� ����(1~9)�� ��Ŀ� ���Ѵ�.
		else if (strcmp(command, "1") == 0 || strcmp(command, "2") == 0 ||
			     strcmp(command, "3") == 0 || strcmp(command, "4") == 0 ||
			     strcmp(command, "5") == 0 || strcmp(command, "6") == 0 ||
			     strcmp(command, "7") == 0 || strcmp(command, "8") == 0 ||
			     strcmp(command, "9") == 0) {
		}
		
		//���α׷� ����
		else if (strcmp(command, "q") == 0) {
			printf("Stop Program.\n");
			break;
		}
		//�߸��� ��ɾ�
		else {
			printf("Wrong Order: try again...\n");
		}

	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//����� �Ѱ� ���
void print_matrix01(int matrix[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//����� �ΰ� ���
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
//��� ����
void generate_matrix(int matrix[SIZE][SIZE]) {
	int value[SIZE * SIZE];
	int index = 0;

	//��Ŀ� 2�� �� �ΰ��� �ִ� ����
	for (int i = 0; i < SIZE * SIZE; i++) {
		if (i < 2) {
			value[i] = 2;
		}
		else {
			value[i] = rand() % 2;
		}
	}
	//��Ŀ� �� ���� ��ġ
	for (int i = 0; i < SIZE * SIZE; i++) {
		int j = rand() % (SIZE * SIZE);
		int t = value[i];
		value[i] = value[j];
		value[j] = t;
	}
	//��� �� �Ҵ�
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = value[index++];
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��� ���� (m)
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
//��� ���� (a)
void a_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
}
//��� ���� (d)
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