#define _CRT_SECURET_NO_WARNINGS
#pragma warning(disable:4996)


#define PROB 3



#if PROB == 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

void generate_matrix(int matrix[SIZE][SIZE]);	//��� ����
void print_matrix01(int matrix[SIZE][SIZE]);	//��� �Ѱ� ���
void print_matrix02(int matrix01[SIZE][SIZE], int matrix02[SIZE][SIZE]); //��� �ΰ� ���

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
		printf("\nInput Command (m, a, d, r, t, e, s, 1~9, q) : ");
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void setColor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �⺻ ����
}

void findCapitalWords(char* str) {
	int count = 0;
	char* token = strtok(str, " ");
	while (token != NULL) {
		if (isupper(token[0])) {
			setColor(12); // ������ ���
			printf("%s ", token);
			resetColor();
			count++;
		}
		else {
			printf("%s ", token);
		}
		token = strtok(NULL, " ");
	}
	printf("\n�빮�ڷ� �����ϴ� �ܾ� ����: %d\n", count);
}

void reverseSentence(char* str) {
	int len = strlen(str);
	for (int i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}

void insertAt(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		printf("%c", str[i]);
		if ((i + 1) % 3 == 0) {
			printf("@@");
		}
	}
	printf("\n");
}

void reverseWords(char* str) {
	char* token = strtok(str, " ");
	char* words[100];
	int count = 0;

	while (token != NULL) {
		words[count++] = token;
		token = strtok(NULL, " ");
	}

	for (int i = count - 1; i >= 0; i--) {
		printf("%s ", words[i]);
	}
	printf("\n");
}

void replaceChar(char* str, char oldChar, char newChar) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == oldChar) {
			str[i] = newChar;
		}
	}
	printf("%s\n", str);
}

void countWordsInLine(char* str) {
	int count = 0;
	char* token = strtok(str, " ");
	while (token != NULL) {
		count++;
		token = strtok(NULL, " ");
	}
	printf("�ܾ� ����: %d\n", count);
}

int main() {
	char fileName[100];
	printf("���� �̸��� �Է��ϼ���: ");
	scanf("%s", fileName);

	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return 1;
	}

	char line[256];
	while (fgets(line, sizeof(line), file)) {
		printf("�Է��� ��ɾ�: ");
		char command;
		scanf(" %c", &command);

		switch (command) {
		case 'c':
			findCapitalWords(line);
			break;
		case 'd':
			reverseSentence(line);
			break;
		case 'e':
			insertAt(line);
			break;
		case 'f':
			reverseWords(line);
			break;
		case 'g': {
			char oldChar, newChar;
			printf("�ٲ� ���ڿ� �� ���ڸ� �Է��ϼ���: ");
			scanf(" %c %c", &oldChar, &newChar);
			replaceChar(line, oldChar, newChar);
			break;
		}
		case 'h':
			countWordsInLine(line);
			break;
		case 'q':
			fclose(file);
			return 0;
		default:
			printf("�߸��� ��ɾ��Դϴ�.\n");
		}
	}

	fclose(file);

	return 0;
}
#elif PROB == 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x, y, z;
	int isEmpty;  // ������ �׸��� ǥ���ϱ� ���� �÷���
} Point;

Point list[20];
int count = 0;

float distanceFromOrigin(Point p) {
	return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

void printList() {
	printf("���� ����Ʈ ���� (�� %d��):\n", count);
	int displayIndex = 20; // ����� �� ��ȣ�� 20���� ����
	for (int i = 19; i >= 0; i--) { // ���� ���
		if (!list[i].isEmpty) {
			float length = distanceFromOrigin(list[i]);
			printf("%d: (%d, %d, %d) - length: %.2f\n", displayIndex, list[i].x, list[i].y, list[i].z, length);
		}
		else {
			printf("%d: (0, 0, 0) - length: 0.00\n", displayIndex);
		}
		displayIndex--; // ��µǴ� ��ȣ�� 20���� �����ؼ� ����
	}
}

void addPointToBottom(int x, int y, int z) {
	if (count < 20) {
		list[count].x = x;
		list[count].y = y;
		list[count].z = z;
		list[count].isEmpty = 0; // ������� ���� ǥ��
		count++;
		printf("+ (%d, %d, %d) �߰���\n", x, y, z);
		printList();
	}
	else {
		printf("����Ʈ�� ���� á���ϴ�.\n");
	}
}



void removeBottomPoint() {
	if (count > 0) {
		count--; // ī��Ʈ�� �������� ������ ���� �� ĭ���� ǥ��
		list[count].isEmpty = 1; // �ش� ĭ�� ����ٰ� ǥ��
		printf("�� �Ʒ��� (%d, %d, %d) ������\n", list[count].x, list[count].y, list[count].z);
		printList();
	}
	else {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
	}
}

void findFarthestPoint() {
	if (count == 0) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	int maxIndex = 0;
	float maxDistance = distanceFromOrigin(list[0]);

	for (int i = 1; i < count; i++) {
		float dist = distanceFromOrigin(list[i]);
		if (dist > maxDistance) {
			maxDistance = dist;
			maxIndex = i;
		}
	}

	printf("���� �� ��: (%d, %d, %d)\n", list[maxIndex].x, list[maxIndex].y, list[maxIndex].z);
}

void findClosestPoint() {
	if (count == 0) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	int minIndex = 0;
	float minDistance = distanceFromOrigin(list[0]);

	for (int i = 1; i < count; i++) {
		float dist = distanceFromOrigin(list[i]);
		if (dist < minDistance) {
			minDistance = dist;
			minIndex = i;
		}
	}

	printf("���� ����� ��: (%d, %d, %d)\n", list[minIndex].x, list[minIndex].y, list[minIndex].z);
}

int compare(const void* a, const void* b) {
	Point* p1 = (Point*)a;
	Point* p2 = (Point*)b;

	float dist1 = distanceFromOrigin(*p1);
	float dist2 = distanceFromOrigin(*p2);

	return (dist1 > dist2) - (dist1 < dist2);
}

void sortPointsAsc() {
	qsort(list, count, sizeof(Point), compare);
	printf("�������� �Ÿ��� ���� ������������ ���ĵ�\n");
	printList();
}

void restoreOriginalList() {
	printf("����Ʈ�� ���� ���·� ������\n");
	printList();
}

int main() {
	char command;
	while (1) {
		printf("��ɾ �Է��ϼ��� (+ x y z, - , e x y z, d, l, m, n, a, q): ");
		scanf(" %c", &command);

		if (command == '+') {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			addPointToBottom(x, y, z); // �� �Ʒ��� �� �߰�
		}
		else if (command == '-') {
			removeBottomPoint(); // �� �Ʒ����� ����
		}
		else if (command == 'd') {
			removeBottomPoint(); // �� �Ʒ����� ����
		}
		else if (command == 'l') {
			printf("����Ʈ ����: %d\n", count); // ����Ʈ�� ���� ���
		}
		else if (command == 'm') {
			findFarthestPoint(); // ���� �� �� ã��
		}
		else if (command == 'n') {
			findClosestPoint(); // ���� ����� �� ã��
		}
		else if (command == 'a') {
			sortPointsAsc(); // ������ �������� �Ÿ� ���� �������� ����
		}
		else if (command == 'q') {
			break; // ���α׷� ����
		}
		else {
			printf("�߸��� ��ɾ��Դϴ�.\n");
		}
	}

	return 0;
}

#elif PROB == 4
#elif PROB == 5
#elif PROB == 6
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30  // �迭 ũ��

// �迭�� ��ֹ� �ʱ�ȭ
void init_grid(char grid[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] = '1';  // ����� 1�� �ʱ�ȭ
		}
	}

	// ��ֹ� X�� �������� 30�� ����
	int obstacles = 30;
	srand(time(0));
	while (obstacles > 0) {
		int x = rand() % N;
		int y = rand() % N;
		if (grid[x][y] != 'X') {
			grid[x][y] = 'X';
			obstacles--;
		}
	}
}

// �迭 ��� �Լ�
void print_grid(char grid[N][N], int px, int py) {
	system("clear");  // ȭ���� ���� (Linux/Mac ȯ��, Windows�� system("cls"))
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == px && j == py) {
				printf("* ");  // �÷��̾� ��ġ
			}
			else {
				printf("%c ", grid[i][j]);
			}
		}
		printf("\n");
	}
}

// ��� ���� ��Ģ�� �°� �̵�
void move(char grid[N][N], int* px, int* py, char direction) {
	int nx = *px, ny = *py;

	// ���⿡ ���� ��ǥ ������Ʈ
	if (direction == 'w' && *px > 0) nx--;         // ���� �̵�
	if (direction == 's' && *px < N - 1) nx++;      // �Ʒ��� �̵�
	if (direction == 'a' && *py > 0) ny--;         // �������� �̵�
	if (direction == 'd' && *py < N - 1) ny++;      // ���������� �̵�

	// ��ֹ��� ������ �̵� �Ұ�
	if (grid[nx][ny] != 'X') {
		*px = nx;
		*py = ny;
	}
}

int main() {
	char grid[N][N];
	int px = 0, py = 0;  // �÷��̾� ���� ��ġ

	init_grid(grid);  // �迭 �ʱ�ȭ

	while (1) {
		print_grid(grid, px, py);  // �迭 ���

		printf("Move (w: up, a: left, s: down, d: right, q: quit): ");
		char command = getchar();  // Ű���� �Է� ���
		getchar();  // ���� ó��

		if (command == 'q') {
			break;  // ���α׷� ����
		}

		move(grid, &px, &py, command);  // ��� �̵�
	}

	return 0;
}



#elif PROB == 7
#endif