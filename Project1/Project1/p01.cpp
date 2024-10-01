#define _CRT_SECURET_NO_WARNINGS


#define PROB 3

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
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

// 사각형 좌표 및 색상 변수
float rect1_x1 = -0.9f, rect1_y1 = -0.1f, rect1_x2 = -0.5f, rect1_y2 = 0.3f;
float rect2_x1 = 0.1f, rect2_y1 = -0.1f, rect2_x2 = 0.5f, rect2_y2 = 0.3f;
float rect3_x1 = -0.9f, rect3_y1 = -0.7f, rect3_x2 = -0.5f, rect3_y2 = -0.3f;
float rect4_x1 = 0.1f, rect4_y1 = -0.7f, rect4_x2 = 0.5f, rect4_y2 = -0.3f;

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
                rect1_x1 += 0.01f; rect1_y1 += 0.01f; // 사각형 축소
            }
            else if (xpos > rect2_x1 && xpos < rect2_x2 && ypos > rect2_y1 && ypos < rect2_y2) {
                rect2_x1 += 0.01f; rect2_y1 += 0.01f; // 사각형 축소
            }
            else if (xpos > rect3_x1 && xpos < rect3_x2 && ypos > rect3_y1 && ypos < rect3_y2) {
                rect3_x1 += 0.01f; rect3_y1 += 0.01f; // 사각형 축소
            }
            else if (xpos > rect4_x1 && xpos < rect4_x2 && ypos > rect4_y1 && ypos < rect4_y2) {
                rect4_x1 += 0.01f; rect4_y1 += 0.01f; // 사각형 축소
            }
            else {
                // 사각형 외부 클릭 시 크기 확대
                rect1_x2 += 0.01f; rect1_y2 += 0.01f;
                rect2_x2 += 0.01f; rect2_y2 += 0.01f;
                rect3_x2 += 0.01f; rect3_y2 += 0.01f;
                rect4_x2 += 0.01f; rect4_y2 += 0.01f;
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
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // for std::min and std::max

// 사각형 구조체 정의
struct Rectangle {
    float x1, y1, x2, y2;
    float r, g, b;
    bool isDragging = false;
};

// 사각형 리스트
std::vector<Rectangle> rectangles;
int maxRectangles = 10;
Rectangle* selectedRectangle = nullptr;
bool isDragging = false;
float lastX = 0.0f, lastY = 0.0f; // 마우스의 마지막 위치

// 랜덤 색상 생성
void setRandomColor(Rectangle& rect) {
    rect.r = static_cast<float>(rand()) / RAND_MAX;
    rect.g = static_cast<float>(rand()) / RAND_MAX;
    rect.b = static_cast<float>(rand()) / RAND_MAX;
}

// 랜덤 위치의 사각형 생성
void addRandomRectangle() {
    if (rectangles.size() < maxRectangles) {
        Rectangle rect;
        rect.x1 = static_cast<float>(rand()) / RAND_MAX * 1.8f - 0.9f;
        rect.y1 = static_cast<float>(rand()) / RAND_MAX * 1.8f - 0.9f;
        rect.x2 = rect.x1 + 0.2f;
        rect.y2 = rect.y1 + 0.2f;
        setRandomColor(rect);
        rectangles.push_back(rect);
        glutPostRedisplay();
    }
}

// 겹치는 사각형 병합
void mergeRectangles(Rectangle& rect1, Rectangle& rect2) {
    rect1.x1 = std::min(rect1.x1, rect2.x1);
    rect1.y1 = std::min(rect1.y1, rect2.y1);
    rect1.x2 = std::max(rect1.x2, rect2.x2);
    rect1.y2 = std::max(rect1.y2, rect2.y2);
    setRandomColor(rect1);

    // 병합된 사각형을 리스트에서 제거
    rectangles.erase(std::remove(rectangles.begin(), rectangles.end(), rect2), rectangles.end());
}

// 드래그 중 사각형 이동
void moveRectangle(Rectangle* rect, float dx, float dy) {
    rect->x1 += dx;
    rect->y1 += dy;
    rect->x2 += dx;
    rect->y2 += dy;
}

// 사각형 그리기
void drawRectangles() {
    for (const auto& rect : rectangles) {
        glColor3f(rect.r, rect.g, rect.b);
        glRectf(rect.x1, rect.y1, rect.x2, rect.y2);
    }
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawRectangles();

    glutSwapBuffers();
}

// 창 크기 변경 시 처리
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

// 키보드 입력 처리
void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') {
        addRandomRectangle();
    }
    else if (key == 'q') {
        exit(0);
    }
    glutPostRedisplay();
}

// 사각형 선택
Rectangle* findRectangleAt(float xpos, float ypos) {
    for (int i = rectangles.size() - 1; i >= 0; --i) {
        Rectangle& rect = rectangles[i];
        if (xpos > rect.x1 && xpos < rect.x2 && ypos > rect.y1 && ypos < rect.y2) {
            return &rect;
        }
    }
    return nullptr;
}

// 마우스 클릭 및 드래그 처리
void mouse(int button, int state, int x, int y) {
    float xpos = (x / 400.0f) - 1.0f;
    float ypos = 1.0f - (y / 300.0f);

    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        selectedRectangle = findRectangleAt(xpos, ypos);
        if (selectedRectangle != nullptr) {
            isDragging = true;
            lastX = xpos; // 마우스 클릭 순간의 좌표를 저장
            lastY = ypos;
        }
    }
    else if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
        if (isDragging && selectedRectangle != nullptr) {
            for (auto& rect : rectangles) {
                if (&rect != selectedRectangle &&
                    !(selectedRectangle->x2 < rect.x1 || selectedRectangle->x1 > rect.x2 ||
                        selectedRectangle->y2 < rect.y1 || selectedRectangle->y1 > rect.y2)) {
                    mergeRectangles(*selectedRectangle, rect);
                    break;
                }
            }
        }
        isDragging = false;
        selectedRectangle = nullptr;
    }
    glutPostRedisplay();
}

void motion(int x, int y) {
    if (isDragging && selectedRectangle != nullptr) {
        float xpos = (x / 400.0f) - 1.0f;
        float ypos = 1.0f - (y / 300.0f);

        float dx = xpos - lastX;
        float dy = ypos - lastY;

        moveRectangle(selectedRectangle, dx, dy);

        lastX = xpos;
        lastY = ypos;
        glutPostRedisplay();
    }
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
    glutMotionFunc(motion);

    glutMainLoop();

    return 0;
}


#elif PROB == 4
#elif PROB == 5
#elif PROB == 6
#endif


