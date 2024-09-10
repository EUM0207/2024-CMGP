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
int r_matrix(int a[SIZE][SIZE], int n); //��Ľ� ���
void t_matrix(int a[SIZE][SIZE], int result[SIZE][SIZE]); //��ġ ��� ���

int main() {
	int matrix01[SIZE][SIZE], matrix02[SIZE][SIZE];
	int result[SIZE][SIZE];
	char command[20];
	int e_mode = 0; //¦��,Ȧ�� ��� (0: ����, 1: ¦, 2: Ȧ)
	
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
			printf("matrix01 = %d\n", r_matrix(matrix01, SIZE));
			printf("matrix02 = %d\n", r_matrix(matrix02, SIZE));
		}
		//2���� ����� ��ġ ���(Transposed matrix)�� �� ��Ľ��� �� ��� ���
		else if (strcmp(command, "t") == 0) {
			t_matrix(matrix01, result);
			print_matrix01(result);
			printf("t_matrix01 = %d\n\n", r_matrix(result, SIZE));

			t_matrix(matrix02, result);
			print_matrix01(result);
			printf("t_matrix02 = %d\n", r_matrix(result, SIZE));
		}
		else if (strcmp(command, "e") == 0) {
			e_mode = (e_mode + 1) % 3; // ��� ���� (0: ����, 1: ¦����, 2: Ȧ����)

			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					// matrix01 ���
					if (e_mode == 1 && (matrix01[i][j] % 2 == 0)) { // ¦���� ���
						printf("%3d ", matrix01[i][j]);
					}
					else if (e_mode == 2 && (matrix01[i][j] % 2 != 0)) { // Ȧ���� ���
						printf("%3d ", matrix01[i][j]);
					}
					else if (e_mode == 0) { // ������� ���
						printf("%3d ", matrix01[i][j]);
					}
					else { // �ش� ��忡 ���� ������ �� ĭ ���
						printf("    ");
					}
				}

				printf("\t"); // �� ��� ������ ����

				for (int j = 0; j < SIZE; j++) {
					// matrix02 ���
					if (e_mode == 1 && (matrix02[i][j] % 2 == 0)) { // ¦���� ���
						printf("%3d ", matrix02[i][j]);
					}
					else if (e_mode == 2 && (matrix02[i][j] % 2 != 0)) { // Ȧ���� ���
						printf("%3d ", matrix02[i][j]);
					}
					else if (e_mode == 0) { // ������� ���
						printf("%3d ", matrix02[i][j]);
					}
					else { // �ش� ��忡 ���� ������ �� ĭ ���
						printf("    ");
					}
				}
				printf("\n");
			}
			printf("\n");
		}
		//����� ���� ���� �����ϰ� ����
		else if (strcmp(command, "s") == 0) {
			generate_matrix(matrix01);
			generate_matrix(matrix02);
			print_matrix02(matrix01, matrix02);
		}
		//�Է��� ����(1~9)�� ��Ŀ� ���Ѵ�.
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
//��Ľ� ��� (r)
void get_cofactor(int matrix[SIZE][SIZE], int temp[SIZE][SIZE], int p, int q, int n) {
	int i = 0, j = 0;

	// ���� ��(p)�� ��(q)�� ������ ����Ľ� ����
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			// ��� ���� ������ ��Ҹ� �ӽ� �迭 temp�� ����
			if (row != p && col != q) {
				temp[i][j++] = matrix[row][col];

				// �� ���� �� ä������ ���� ������ �Ѿ
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

	// ����� 1x1�� ��� ��Ľ��� �ش� ���� ��ü
	if (n == 1) {
		return matrix[0][0];
	}

	int temp[SIZE][SIZE]; // ����Ľ� ������ �ӽ� ���
	int sign = 1; // +�� - ��ȣ ����

	// ù ��° ���� �������� ����Ľ��� ����Ͽ� ��Ľ��� ����
	for (int f = 0; f < n; f++) {
		// ����Ľ� ���
		get_cofactor(matrix, temp, 0, f, n);
		// ��Ľ� ��� ���
		det += sign * matrix[0][f] * r_matrix(temp, n - 1);

		// ��ȣ ����
		sign = -sign;
	}

	return det;
}
//��ġ ��� ��� (t)
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