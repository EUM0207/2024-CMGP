#define _CRT_SECURET_NO_WARNINGS


#define PROB 5

#if PROB == 1
#include <iostream>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);
GLvoid Timer(int run);

bool isTimerRunning = false; //--- 타이머 상태를 저장


void main(int argc, char** argv) //--- 윈도우 출력하고 콜백함수 설정
{
	//--- 윈도우 생성하기
	glutInit(&argc, argv); //--- glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //--- 디스플레이 모드 설정
	glutInitWindowPosition(0, 0); //--- 윈도우의 위치 지정
	glutInitWindowSize(800, 600); //--- 윈도우의 크기 지정
	glutCreateWindow("Example1"); //--- 윈도우 생성 (윈도우 이름)
		
	//--- GLEW 초기화하기
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) //--- glew 초기화
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";

	glutDisplayFunc(drawScene); //--- 출력 콜백함수의 지정
	glutReshapeFunc(Reshape); //--- 다시 그리기 콜백함수 지정
	glutKeyboardFunc(Keyboard); //--- 키보드 입력 콜백함수 지정
	glutMainLoop(); //--- 이벤트 처리 시작
}

GLvoid drawScene() //--- 콜백 함수: 그리기 콜백 함수
{
    glClear(GL_COLOR_BUFFER_BIT); //--- 설정된 색으로 전체를 칠하기
    glutSwapBuffers(); //--- 화면에 출력하기
}

GLvoid Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

GLvoid Timer(int value) //--- 타이머 함수
{
    if (isTimerRunning) {
        glClearColor((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f); //--- 랜덤 색
        glutPostRedisplay(); //--- 화면 갱신
        glutTimerFunc(500, Timer, 0); //--- 500ms마다 타이머 호출
    }
}

GLvoid Keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'c':
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //--- 청록색 (초록 + 파랑)
        break;
    case 'm':
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //--- 자홍색 (빨강 + 파랑)
        break;
    case 'y':
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //--- 노랑색 (빨강 + 초록)
        break;
    case 'a':
        glClearColor((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f); //--- 랜덤 색
        break;
    case 'w':
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //--- 흰색
        break;
    case 'k':
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //--- 검정색
        break;
    case 't':
        if (!isTimerRunning) { //--- 타이머가 실행 중이 아니면 타이머 시작
            isTimerRunning = true;
            glutTimerFunc(500, Timer, 0); //--- 500ms마다 타이머 호출
        }
        break;
    case 's':
        isTimerRunning = false; //--- 타이머 중지
        break;
    case 'q':
        exit(0); //--- 프로그램 종료
        break;
    }
    glutPostRedisplay(); //--- 화면 갱신
}

#elif PROB == 2
#include <iostream>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

// 사각형 좌표 및 색상 변수
float rect1_x1 = -1.0f, rect1_y1 = -0.0f, rect1_x2 = -0.0f, rect1_y2 = 1.0f;
float rect2_x1 = 0.0f, rect2_y1 = -0.0f, rect2_x2 = 1.0f, rect2_y2 = 1.0f;
float rect3_x1 = -1.0f, rect3_y1 = -1.0f, rect3_x2 = -0.0f, rect3_y2 = -0.0f;
float rect4_x1 = 0.0f, rect4_y1 = -1.0f, rect4_x2 = 1.0f, rect4_y2 = -0.0f;

// 사각형 색상
float rect1_r = 1.0f, rect1_g = 0.0f, rect1_b = 0.0f;
float rect2_r = 0.0f, rect2_g = 1.0f, rect2_b = 0.0f;
float rect3_r = 0.0f, rect3_g = 0.0f, rect3_b = 1.0f;
float rect4_r = 1.0f, rect4_g = 1.0f, rect4_b = 0.0f;

// 배경색 변수
float background_r = 1.0f, background_g = 1.0f, background_b = 1.0f;

void drawRectangles() {
    // 사각형 1
    glColor3f(rect1_r, rect1_g, rect1_b);
    glRectf(rect1_x1, rect1_y1, rect1_x2, rect1_y2);

    // 사각형 2
    glColor3f(rect2_r, rect2_g, rect2_b);
    glRectf(rect2_x1, rect2_y1, rect2_x2, rect2_y2);

    // 사각형 3
    glColor3f(rect3_r, rect3_g, rect3_b);
    glRectf(rect3_x1, rect3_y1, rect3_x2, rect3_y2);

    // 사각형 4
    glColor3f(rect4_r, rect4_g, rect4_b);
    glRectf(rect4_x1, rect4_y1, rect4_x2, rect4_y2);
}

void drawScene() {
    glClearColor(background_r, background_g, background_b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 사각형들을 그리기
    drawRectangles();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'q') {
        exit(0);
    }
    glutPostRedisplay();
}

// 색상을 랜덤으로 변경하는 함수
void changeRectangleColor(int rectId) {
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    if (rectId == 1) {
        rect1_r = r; rect1_g = g; rect1_b = b;
    }
    else if (rectId == 2) {
        rect2_r = r; rect2_g = g; rect2_b = b;
    }
    else if (rectId == 3) {
        rect3_r = r; rect3_g = g; rect3_b = b;
    }
    else if (rectId == 4) {
        rect4_r = r; rect4_g = g; rect4_b = b;
    }
}

// 마우스 클릭에 따른 상호작용
void mouse(int button, int state, int x, int y) {
    // 윈도우 좌표를 OpenGL 좌표로 변환
    float xpos = (x / 400.0f) - 1.0f;
    float ypos = 1.0f - (y / 300.0f);

    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            // 사각형 안을 클릭했는지 확인하고 색상 변경
            if (xpos > rect1_x1 && xpos < rect1_x2 && ypos > rect1_y1 && ypos < rect1_y2) {
                changeRectangleColor(1);
            }
            else if (xpos > rect2_x1 && xpos < rect2_x2 && ypos > rect2_y1 && ypos < rect2_y2) {
                changeRectangleColor(2);
            }
            else if (xpos > rect3_x1 && xpos < rect3_x2 && ypos > rect3_y1 && ypos < rect3_y2) {
                changeRectangleColor(3);
            }
            else if (xpos > rect4_x1 && xpos < rect4_x2 && ypos > rect4_y1 && ypos < rect4_y2) {
                changeRectangleColor(4);
            }
            else {
                // 사각형 외부 클릭 시 배경색 변경
                background_r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                background_g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                background_b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            }
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            // 사각형 크기 조절
            if (xpos > rect1_x1 && xpos < rect1_x2 && ypos > rect1_y1 && ypos < rect1_y2) {
                rect1_x1 += 0.01f; rect1_y1 += 0.01f; rect1_x2 -= 0.01f; rect1_y2 -= 0.01f; // 사각형 축소
            }
            else if (xpos > rect2_x1 && xpos < rect2_x2 && ypos > rect2_y1 && ypos < rect2_y2) {
                rect2_x1 += 0.01f; rect2_y1 += 0.01f; rect2_x2 -= 0.01f; rect2_y2 -= 0.01f; // 사각형 축소
            }
            else if (xpos > rect3_x1 && xpos < rect3_x2 && ypos > rect3_y1 && ypos < rect3_y2) {
                rect3_x1 += 0.01f; rect3_y1 += 0.01f; rect3_x2 -= 0.01f; rect3_y2 -= 0.01f; // 사각형 축소
            }
            else if (xpos > rect4_x1 && xpos < rect4_x2 && ypos > rect4_y1 && ypos < rect4_y2) {
                rect4_x1 += 0.01f; rect4_y1 += 0.01f; rect4_x2 -= 0.01f; rect4_y2 -= 0.01f; // 사각형 축소
            }
            else {
                // 사각형 외부 클릭 시 크기 확대
                rect1_x1 -= 0.01f; rect1_y1 -= 0.01f; rect1_x2 += 0.01f; rect1_y2 += 0.01f;
                rect2_x1 -= 0.01f; rect2_y1 -= 0.01f; rect2_x2 += 0.01f; rect2_y2 += 0.01f;
                rect3_x1 -= 0.01f; rect3_y1 -= 0.01f; rect3_x2 += 0.01f; rect3_y2 += 0.01f;
                rect4_x1 -= 0.01f; rect4_y1 -= 0.01f; rect4_x2 += 0.01f; rect4_y2 += 0.01f;
            }
        }
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0))); // 랜덤 시드 설정

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rectangle Interaction");

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Unable to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
}

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 초기 배경색을 흰색으로 설정

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}


#elif PROB == 3
// 실습 3번: 사각형 이동 및 합치기
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// 사각형 구조체 정의
struct Rect {
    float x1, y1, x2, y2; // 좌표
    float r, g, b;        // 색상
    bool isSelected;      // 선택 여부
};

std::vector<Rect> rectangles; // 사각형 목록
const int MAX_RECTANGLES = 10;     // 최대 사각형 수
int selectedRectIndex = -1;        // 선택된 사각형 인덱스
float offsetX = 0.0f, offsetY = 0.0f; // 드래그 시 마우스와 사각형 사이의 거리

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 사각형 그리기
    for (const auto& rect : rectangles) {
        glColor3f(rect.r, rect.g, rect.b);
        // glRectf 함수 사용
        glRectf(rect.x1, rect.y1, rect.x2, rect.y2);
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    // 뷰포트 설정
    glViewport(0, 0, w, h);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') {
        if (rectangles.size() < MAX_RECTANGLES) {
            Rect rect;
            // 랜덤 위치 생성 (-0.8 ~ 0.6 범위)
            rect.x1 = ((float)rand() / RAND_MAX) * 1.4f - 0.8f;
            rect.y1 = ((float)rand() / RAND_MAX) * 1.4f - 0.8f;
            rect.x2 = rect.x1 + 0.2f;
            rect.y2 = rect.y1 + 0.2f;

            // 랜덤 색상 생성
            rect.r = (float)rand() / RAND_MAX;
            rect.g = (float)rand() / RAND_MAX;
            rect.b = (float)rand() / RAND_MAX;

            rect.isSelected = false;

            rectangles.push_back(rect);
            glutPostRedisplay();
        }
    }
    else if (key == 'q' || key == 'Q') {
        exit(0);
    }
}

bool isInsideRect(const Rect& rect, float x, float y) {
    return x >= rect.x1 && x <= rect.x2 && y >= rect.y1 && y <= rect.y2;
}

void mouse(int button, int state, int x, int y) {
    // 윈도우 좌표를 OpenGL 좌표로 변환
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    float xpos = ((float)x / windowWidth) * 2.0f - 1.0f;
    float ypos = 1.0f - ((float)y / windowHeight) * 2.0f;

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            // 사각형 목록을 역순으로 탐색하여 가장 위에 있는 사각형 선택
            for (int i = rectangles.size() - 1; i >= 0; --i) {
                if (isInsideRect(rectangles[i], xpos, ypos)) {
                    selectedRectIndex = i;
                    rectangles[i].isSelected = true;
                    // 드래그 시작 시점에서의 오프셋 계산
                    offsetX = xpos - (rectangles[i].x1 + rectangles[i].x2) / 2.0f;
                    offsetY = ypos - (rectangles[i].y1 + rectangles[i].y2) / 2.0f;
                    break;
                }
            }
        }
        else if (state == GLUT_UP) {
            if (selectedRectIndex != -1) {
                rectangles[selectedRectIndex].isSelected = false;
                // 사각형 겹침 체크 및 합치기
                for (int i = rectangles.size() - 1; i >= 0; --i) {
                    if (i != selectedRectIndex && rectangles[i].isSelected == false) {
                        // 사각형이 겹치는지 확인
                        Rect& rect1 = rectangles[selectedRectIndex];
                        Rect& rect2 = rectangles[i];

                        bool isOverlap = !(rect1.x2 < rect2.x1 || rect1.x1 > rect2.x2 || rect1.y2 < rect2.y1 || rect1.y1 > rect2.y2);

                        if (isOverlap) {
                            // 최소 및 최대 좌표 계산
                            float minX = std::min(rect1.x1, rect2.x1);
                            float minY = std::min(rect1.y1, rect2.y1);
                            float maxX = std::max(rect1.x2, rect2.x2);
                            float maxY = std::max(rect1.y2, rect2.y2);

                            // 새로운 사각형 생성
                            Rect mergedRect;
                            mergedRect.x1 = minX;
                            mergedRect.y1 = minY;
                            mergedRect.x2 = maxX;
                            mergedRect.y2 = maxY;
                            mergedRect.r = (float)rand() / RAND_MAX;
                            mergedRect.g = (float)rand() / RAND_MAX;
                            mergedRect.b = (float)rand() / RAND_MAX;
                            mergedRect.isSelected = false;

                            // 기존 사각형 삭제 및 새로운 사각형 추가
                            int firstIndex = std::max(selectedRectIndex, i);
                            int secondIndex = std::min(selectedRectIndex, i);

                            rectangles.erase(rectangles.begin() + firstIndex);
                            rectangles.erase(rectangles.begin() + secondIndex);
                            rectangles.push_back(mergedRect);

                            selectedRectIndex = -1;
                            break;
                        }
                    }
                }
                selectedRectIndex = -1;
                glutPostRedisplay();
            }
        }
    }
}

void motion(int x, int y) {
    if (selectedRectIndex != -1) {
        // 마우스 이동에 따라 사각형 위치 변경
        int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        float xpos = ((float)x / windowWidth) * 2.0f - 1.0f;
        float ypos = 1.0f - ((float)y / windowHeight) * 2.0f;

        float width = rectangles[selectedRectIndex].x2 - rectangles[selectedRectIndex].x1;
        float height = rectangles[selectedRectIndex].y2 - rectangles[selectedRectIndex].y1;

        rectangles[selectedRectIndex].x1 = xpos - width / 2.0f - offsetX;
        rectangles[selectedRectIndex].y1 = ypos - height / 2.0f - offsetY;
        rectangles[selectedRectIndex].x2 = rectangles[selectedRectIndex].x1 + width;
        rectangles[selectedRectIndex].y2 = rectangles[selectedRectIndex].y1 + height;

        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0))); // 랜덤 시드 설정

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("실습 3: 사각형 이동 및 합치기");

    // GLEW 제거: 허용된 함수만 사용하므로 필요 없음

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();

    return 0;
}


#elif PROB == 4
#include <iostream>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <vector>
#include <cstdlib>
#include <ctime>

// 사각형 구조체 정의
struct Square {
    float x, y;           // 현재 중심 좌표
    float size;           // 크기
    float r, g, b;        // 색상
    float dx, dy;         // 이동 속도
    bool movingDiagonal;  // 대각선 이동 여부
    bool movingZigzag;    // 지그재그 이동 여부
    bool changingSize;    // 크기 변화 여부
    bool changingColor;   // 색상 변화 여부
    float originalX, originalY; // 초기 위치
};

std::vector<Square> squares; // 사각형 목록
const int MAX_SQUARES = 5;   // 최대 사각형 수

bool isMovingDiagonal = false;
bool isMovingZigzag = false;
bool isChangingSize = false;
bool isChangingColor = false;

void init() {
    // 짙은 회색 배경 설정
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 사각형 그리기
    for (const auto& square : squares) {
        glColor3f(square.r, square.g, square.b);
        float halfSize = square.size / 2.0f;
        // glRectf 함수 사용하여 사각형 그리기
        glRectf(square.x - halfSize, square.y - halfSize, square.x + halfSize, square.y + halfSize);
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    // 뷰포트 설정 (허용된 함수 사용)
    glViewport(0, 0, w, h);
}

void timer(int value) {
    bool needRedisplay = false;

    for (auto& square : squares) {
        // 대각선 이동
        if (square.movingDiagonal) {
            square.x += square.dx;
            square.y += square.dy;

            // 벽에 닿으면 반사
            if (square.x + square.size / 2 > 1.0f || square.x - square.size / 2 < -1.0f)
                square.dx *= -1;
            if (square.y + square.size / 2 > 1.0f || square.y - square.size / 2 < -1.0f)
                square.dy *= -1;

            needRedisplay = true;
        }

        // 지그재그 이동
        if (square.movingZigzag) {
            square.x += square.dx;
            square.y += square.dy * (((int)(square.x * 10) % 2 == 0) ? 1 : -1);

            // 벽에 닿으면 반사
            if (square.x + square.size / 2 > 1.0f || square.x - square.size / 2 < -1.0f)
                square.dx *= -1;
            if (square.y + square.size / 2 > 1.0f || square.y - square.size / 2 < -1.0f)
                square.dy *= -1;

            needRedisplay = true;
        }

        // 크기 변화
        if (square.changingSize) {
            square.size += ((float)rand() / RAND_MAX - 0.5f) * 0.02f;
            if (square.size < 0.1f) square.size = 0.1f;
            if (square.size > 0.9f) square.size = 0.9f;
            needRedisplay = true;
        }

        // 색상 변화
        if (square.changingColor) {
            square.r = (float)rand() / RAND_MAX;
            square.g = (float)rand() / RAND_MAX;
            square.b = (float)rand() / RAND_MAX;
            needRedisplay = true;
        }
    }

    if (needRedisplay)
        glutPostRedisplay();

    glutTimerFunc(16, timer, 0); // 약 60FPS로 업데이트
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        isMovingDiagonal = !isMovingDiagonal;
        for (auto& square : squares) {
            square.movingDiagonal = isMovingDiagonal;
            square.movingZigzag = false;
        }
        break;
    case '2':
        isMovingZigzag = !isMovingZigzag;
        for (auto& square : squares) {
            square.movingZigzag = isMovingZigzag;
            square.movingDiagonal = false;
        }
        break;
    case '3':
        isChangingSize = !isChangingSize;
        for (auto& square : squares) {
            square.changingSize = isChangingSize;
        }
        break;
    case '4':
        isChangingColor = !isChangingColor;
        for (auto& square : squares) {
            square.changingColor = isChangingColor;
        }
        break;
    case 's':
    case 'S':
        isMovingDiagonal = false;
        isMovingZigzag = false;
        isChangingSize = false;
        isChangingColor = false;
        for (auto& square : squares) {
            square.movingDiagonal = false;
            square.movingZigzag = false;
            square.changingSize = false;
            square.changingColor = false;
        }
        break;
    case 'm':
    case 'M':
        for (auto& square : squares) {
            square.x = square.originalX;
            square.y = square.originalY;
            square.dx = ((float)rand() / RAND_MAX - 0.5f) * 0.01f;
            square.dy = ((float)rand() / RAND_MAX - 0.5f) * 0.01f;
        }
        glutPostRedisplay();
        break;
    case 'r':
    case 'R':
        squares.clear();
        glutPostRedisplay();
        break;
    case 'q':
    case 'Q':
        exit(0);
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        if (squares.size() < MAX_SQUARES) {
            int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
            int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
            float xpos = ((float)x / windowWidth) * 2.0f - 1.0f;
            float ypos = 1.0f - ((float)y / windowHeight) * 2.0f;

            Square square;
            square.x = xpos;
            square.y = ypos;
            square.size = 0.2f;
            square.r = (float)rand() / RAND_MAX;
            square.g = (float)rand() / RAND_MAX;
            square.b = (float)rand() / RAND_MAX;
            square.dx = ((float)rand() / RAND_MAX - 0.5f) * 0.01f;
            square.dy = ((float)rand() / RAND_MAX - 0.5f) * 0.01f;
            square.movingDiagonal = isMovingDiagonal;
            square.movingZigzag = isMovingZigzag;
            square.changingSize = isChangingSize;
            square.changingColor = isChangingColor;
            square.originalX = xpos;
            square.originalY = ypos;

            squares.push_back(square);
            glutPostRedisplay();
        }
    }
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("실습 4: 사각형 동작 프로그램");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}


#elif PROB == 5
#include <iostream>
#include <gl/glew.h> //--- 필요한 헤더파일 include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>



#elif PROB == 6
#endif


