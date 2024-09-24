#define _CRT_SECURET_NO_WARNINGS
#pragma warning(disable:4996)


#define PROB 3



#if PROB == 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

void generate_matrix(int matrix[SIZE][SIZE]);	//행렬 생성
void print_matrix01(int matrix[SIZE][SIZE]);	//행렬 한개 출력
void print_matrix02(int matrix01[SIZE][SIZE], int matrix02[SIZE][SIZE]); //행렬 두개 출력

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
		printf("\nInput Command (m, a, d, r, t, e, s, 1~9, q) : ");
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void setColor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 기본 색상
}

void findCapitalWords(char* str) {
	int count = 0;
	char* token = strtok(str, " ");
	while (token != NULL) {
		if (isupper(token[0])) {
			setColor(12); // 빨간색 출력
			printf("%s ", token);
			resetColor();
			count++;
		}
		else {
			printf("%s ", token);
		}
		token = strtok(NULL, " ");
	}
	printf("\n대문자로 시작하는 단어 개수: %d\n", count);
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
	printf("단어 개수: %d\n", count);
}

int main() {
	char fileName[100];
	printf("파일 이름을 입력하세요: ");
	scanf("%s", fileName);

	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	char line[256];
	while (fgets(line, sizeof(line), file)) {
		printf("입력한 명령어: ");
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
			printf("바꿀 문자와 새 문자를 입력하세요: ");
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
			printf("잘못된 명령어입니다.\n");
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
	int isEmpty;  // 삭제된 항목을 표시하기 위한 플래그
} Point;

Point list[20];
int count = 0;

float distanceFromOrigin(Point p) {
	return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

void printList() {
	printf("현재 리스트 상태 (총 %d개):\n", count);
	int displayIndex = 20; // 출력할 때 번호를 20부터 시작
	for (int i = 19; i >= 0; i--) { // 역순 출력
		if (!list[i].isEmpty) {
			float length = distanceFromOrigin(list[i]);
			printf("%d: (%d, %d, %d) - length: %.2f\n", displayIndex, list[i].x, list[i].y, list[i].z, length);
		}
		else {
			printf("%d: (0, 0, 0) - length: 0.00\n", displayIndex);
		}
		displayIndex--; // 출력되는 번호는 20부터 시작해서 감소
	}
}

void addPointToBottom(int x, int y, int z) {
	if (count < 20) {
		list[count].x = x;
		list[count].y = y;
		list[count].z = z;
		list[count].isEmpty = 0; // 비어있지 않음 표시
		count++;
		printf("+ (%d, %d, %d) 추가됨\n", x, y, z);
		printList();
	}
	else {
		printf("리스트가 가득 찼습니다.\n");
	}
}



void removeBottomPoint() {
	if (count > 0) {
		count--; // 카운트는 줄이지만 삭제된 곳은 빈 칸으로 표시
		list[count].isEmpty = 1; // 해당 칸을 비었다고 표시
		printf("맨 아래의 (%d, %d, %d) 삭제됨\n", list[count].x, list[count].y, list[count].z);
		printList();
	}
	else {
		printf("리스트가 비어 있습니다.\n");
	}
}

void findFarthestPoint() {
	if (count == 0) {
		printf("리스트가 비어 있습니다.\n");
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

	printf("가장 먼 점: (%d, %d, %d)\n", list[maxIndex].x, list[maxIndex].y, list[maxIndex].z);
}

void findClosestPoint() {
	if (count == 0) {
		printf("리스트가 비어 있습니다.\n");
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

	printf("가장 가까운 점: (%d, %d, %d)\n", list[minIndex].x, list[minIndex].y, list[minIndex].z);
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
	printf("원점과의 거리에 따라 오름차순으로 정렬됨\n");
	printList();
}

void restoreOriginalList() {
	printf("리스트가 원래 상태로 복구됨\n");
	printList();
}

int main() {
	char command;
	while (1) {
		printf("명령어를 입력하세요 (+ x y z, - , e x y z, d, l, m, n, a, q): ");
		scanf(" %c", &command);

		if (command == '+') {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			addPointToBottom(x, y, z); // 맨 아래에 점 추가
		}
		else if (command == '-') {
			removeBottomPoint(); // 맨 아래에서 삭제
		}
		else if (command == 'd') {
			removeBottomPoint(); // 맨 아래에서 삭제
		}
		else if (command == 'l') {
			printf("리스트 길이: %d\n", count); // 리스트의 길이 출력
		}
		else if (command == 'm') {
			findFarthestPoint(); // 가장 먼 점 찾기
		}
		else if (command == 'n') {
			findClosestPoint(); // 가장 가까운 점 찾기
		}
		else if (command == 'a') {
			sortPointsAsc(); // 점들을 원점과의 거리 기준 오름차순 정렬
		}
		else if (command == 'q') {
			break; // 프로그램 종료
		}
		else {
			printf("잘못된 명령어입니다.\n");
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

#define N 30  // 배열 크기

// 배열과 장애물 초기화
void init_grid(char grid[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] = '1';  // 배경을 1로 초기화
		}
	}

	// 장애물 X를 랜덤으로 30개 생성
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

// 배열 출력 함수
void print_grid(char grid[N][N], int px, int py) {
	system("clear");  // 화면을 지움 (Linux/Mac 환경, Windows는 system("cls"))
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == px && j == py) {
				printf("* ");  // 플레이어 위치
			}
			else {
				printf("%c ", grid[i][j]);
			}
		}
		printf("\n");
	}
}

// 경로 생성 규칙에 맞게 이동
void move(char grid[N][N], int* px, int* py, char direction) {
	int nx = *px, ny = *py;

	// 방향에 따라 좌표 업데이트
	if (direction == 'w' && *px > 0) nx--;         // 위로 이동
	if (direction == 's' && *px < N - 1) nx++;      // 아래로 이동
	if (direction == 'a' && *py > 0) ny--;         // 왼쪽으로 이동
	if (direction == 'd' && *py < N - 1) ny++;      // 오른쪽으로 이동

	// 장애물이 있으면 이동 불가
	if (grid[nx][ny] != 'X') {
		*px = nx;
		*py = ny;
	}
}

int main() {
	char grid[N][N];
	int px = 0, py = 0;  // 플레이어 시작 위치

	init_grid(grid);  // 배열 초기화

	while (1) {
		print_grid(grid, px, py);  // 배열 출력

		printf("Move (w: up, a: left, s: down, d: right, q: quit): ");
		char command = getchar();  // 키보드 입력 대기
		getchar();  // 엔터 처리

		if (command == 'q') {
			break;  // 프로그램 종료
		}

		move(grid, &px, &py, command);  // 경로 이동
	}

	return 0;
}



#elif PROB == 7
#endif