#define _CRT_SECURET_NO_WARNINGS


#define PROB 5

#if PROB == 1
#include <iostream>
#include <gl/glew.h> //--- �ʿ��� ������� include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);
GLvoid Timer(int run);

bool isTimerRunning = false; //--- Ÿ�̸� ���¸� ����


void main(int argc, char** argv) //--- ������ ����ϰ� �ݹ��Լ� ����
{
	//--- ������ �����ϱ�
	glutInit(&argc, argv); //--- glut �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //--- ���÷��� ��� ����
	glutInitWindowPosition(0, 0); //--- �������� ��ġ ����
	glutInitWindowSize(800, 600); //--- �������� ũ�� ����
	glutCreateWindow("Example1"); //--- ������ ���� (������ �̸�)
		
	//--- GLEW �ʱ�ȭ�ϱ�
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) //--- glew �ʱ�ȭ
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";

	glutDisplayFunc(drawScene); //--- ��� �ݹ��Լ��� ����
	glutReshapeFunc(Reshape); //--- �ٽ� �׸��� �ݹ��Լ� ����
	glutKeyboardFunc(Keyboard); //--- Ű���� �Է� �ݹ��Լ� ����
	glutMainLoop(); //--- �̺�Ʈ ó�� ����
}

GLvoid drawScene() //--- �ݹ� �Լ�: �׸��� �ݹ� �Լ�
{
    glClear(GL_COLOR_BUFFER_BIT); //--- ������ ������ ��ü�� ĥ�ϱ�
    glutSwapBuffers(); //--- ȭ�鿡 ����ϱ�
}

GLvoid Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

GLvoid Timer(int value) //--- Ÿ�̸� �Լ�
{
    if (isTimerRunning) {
        glClearColor((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f); //--- ���� ��
        glutPostRedisplay(); //--- ȭ�� ����
        glutTimerFunc(500, Timer, 0); //--- 500ms���� Ÿ�̸� ȣ��
    }
}

GLvoid Keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'c':
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //--- û�ϻ� (�ʷ� + �Ķ�)
        break;
    case 'm':
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //--- ��ȫ�� (���� + �Ķ�)
        break;
    case 'y':
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //--- ����� (���� + �ʷ�)
        break;
    case 'a':
        glClearColor((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f); //--- ���� ��
        break;
    case 'w':
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //--- ���
        break;
    case 'k':
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //--- ������
        break;
    case 't':
        if (!isTimerRunning) { //--- Ÿ�̸Ӱ� ���� ���� �ƴϸ� Ÿ�̸� ����
            isTimerRunning = true;
            glutTimerFunc(500, Timer, 0); //--- 500ms���� Ÿ�̸� ȣ��
        }
        break;
    case 's':
        isTimerRunning = false; //--- Ÿ�̸� ����
        break;
    case 'q':
        exit(0); //--- ���α׷� ����
        break;
    }
    glutPostRedisplay(); //--- ȭ�� ����
}

#elif PROB == 2
#include <iostream>
#include <gl/glew.h> //--- �ʿ��� ������� include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

// �簢�� ��ǥ �� ���� ����
float rect1_x1 = -1.0f, rect1_y1 = -0.0f, rect1_x2 = -0.0f, rect1_y2 = 1.0f;
float rect2_x1 = 0.0f, rect2_y1 = -0.0f, rect2_x2 = 1.0f, rect2_y2 = 1.0f;
float rect3_x1 = -1.0f, rect3_y1 = -1.0f, rect3_x2 = -0.0f, rect3_y2 = -0.0f;
float rect4_x1 = 0.0f, rect4_y1 = -1.0f, rect4_x2 = 1.0f, rect4_y2 = -0.0f;

// �簢�� ����
float rect1_r = 1.0f, rect1_g = 0.0f, rect1_b = 0.0f;
float rect2_r = 0.0f, rect2_g = 1.0f, rect2_b = 0.0f;
float rect3_r = 0.0f, rect3_g = 0.0f, rect3_b = 1.0f;
float rect4_r = 1.0f, rect4_g = 1.0f, rect4_b = 0.0f;

// ���� ����
float background_r = 1.0f, background_g = 1.0f, background_b = 1.0f;

void drawRectangles() {
    // �簢�� 1
    glColor3f(rect1_r, rect1_g, rect1_b);
    glRectf(rect1_x1, rect1_y1, rect1_x2, rect1_y2);

    // �簢�� 2
    glColor3f(rect2_r, rect2_g, rect2_b);
    glRectf(rect2_x1, rect2_y1, rect2_x2, rect2_y2);

    // �簢�� 3
    glColor3f(rect3_r, rect3_g, rect3_b);
    glRectf(rect3_x1, rect3_y1, rect3_x2, rect3_y2);

    // �簢�� 4
    glColor3f(rect4_r, rect4_g, rect4_b);
    glRectf(rect4_x1, rect4_y1, rect4_x2, rect4_y2);
}

void drawScene() {
    glClearColor(background_r, background_g, background_b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // �簢������ �׸���
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

// ������ �������� �����ϴ� �Լ�
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

// ���콺 Ŭ���� ���� ��ȣ�ۿ�
void mouse(int button, int state, int x, int y) {
    // ������ ��ǥ�� OpenGL ��ǥ�� ��ȯ
    float xpos = (x / 400.0f) - 1.0f;
    float ypos = 1.0f - (y / 300.0f);

    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            // �簢�� ���� Ŭ���ߴ��� Ȯ���ϰ� ���� ����
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
                // �簢�� �ܺ� Ŭ�� �� ���� ����
                background_r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                background_g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                background_b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            }
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            // �簢�� ũ�� ����
            if (xpos > rect1_x1 && xpos < rect1_x2 && ypos > rect1_y1 && ypos < rect1_y2) {
                rect1_x1 += 0.01f; rect1_y1 += 0.01f; rect1_x2 -= 0.01f; rect1_y2 -= 0.01f; // �簢�� ���
            }
            else if (xpos > rect2_x1 && xpos < rect2_x2 && ypos > rect2_y1 && ypos < rect2_y2) {
                rect2_x1 += 0.01f; rect2_y1 += 0.01f; rect2_x2 -= 0.01f; rect2_y2 -= 0.01f; // �簢�� ���
            }
            else if (xpos > rect3_x1 && xpos < rect3_x2 && ypos > rect3_y1 && ypos < rect3_y2) {
                rect3_x1 += 0.01f; rect3_y1 += 0.01f; rect3_x2 -= 0.01f; rect3_y2 -= 0.01f; // �簢�� ���
            }
            else if (xpos > rect4_x1 && xpos < rect4_x2 && ypos > rect4_y1 && ypos < rect4_y2) {
                rect4_x1 += 0.01f; rect4_y1 += 0.01f; rect4_x2 -= 0.01f; rect4_y2 -= 0.01f; // �簢�� ���
            }
            else {
                // �簢�� �ܺ� Ŭ�� �� ũ�� Ȯ��
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
    srand(static_cast<unsigned>(time(0))); // ���� �õ� ����

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rectangle Interaction");

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Unable to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
}

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // �ʱ� ������ ������� ����

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}


#elif PROB == 3
// �ǽ� 3��: �簢�� �̵� �� ��ġ��
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// �簢�� ����ü ����
struct Rect {
    float x1, y1, x2, y2; // ��ǥ
    float r, g, b;        // ����
    bool isSelected;      // ���� ����
};

std::vector<Rect> rectangles; // �簢�� ���
const int MAX_RECTANGLES = 10;     // �ִ� �簢�� ��
int selectedRectIndex = -1;        // ���õ� �簢�� �ε���
float offsetX = 0.0f, offsetY = 0.0f; // �巡�� �� ���콺�� �簢�� ������ �Ÿ�

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // �簢�� �׸���
    for (const auto& rect : rectangles) {
        glColor3f(rect.r, rect.g, rect.b);
        // glRectf �Լ� ���
        glRectf(rect.x1, rect.y1, rect.x2, rect.y2);
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    // ����Ʈ ����
    glViewport(0, 0, w, h);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') {
        if (rectangles.size() < MAX_RECTANGLES) {
            Rect rect;
            // ���� ��ġ ���� (-0.8 ~ 0.6 ����)
            rect.x1 = ((float)rand() / RAND_MAX) * 1.4f - 0.8f;
            rect.y1 = ((float)rand() / RAND_MAX) * 1.4f - 0.8f;
            rect.x2 = rect.x1 + 0.2f;
            rect.y2 = rect.y1 + 0.2f;

            // ���� ���� ����
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
    // ������ ��ǥ�� OpenGL ��ǥ�� ��ȯ
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    float xpos = ((float)x / windowWidth) * 2.0f - 1.0f;
    float ypos = 1.0f - ((float)y / windowHeight) * 2.0f;

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            // �簢�� ����� �������� Ž���Ͽ� ���� ���� �ִ� �簢�� ����
            for (int i = rectangles.size() - 1; i >= 0; --i) {
                if (isInsideRect(rectangles[i], xpos, ypos)) {
                    selectedRectIndex = i;
                    rectangles[i].isSelected = true;
                    // �巡�� ���� ���������� ������ ���
                    offsetX = xpos - (rectangles[i].x1 + rectangles[i].x2) / 2.0f;
                    offsetY = ypos - (rectangles[i].y1 + rectangles[i].y2) / 2.0f;
                    break;
                }
            }
        }
        else if (state == GLUT_UP) {
            if (selectedRectIndex != -1) {
                rectangles[selectedRectIndex].isSelected = false;
                // �簢�� ��ħ üũ �� ��ġ��
                for (int i = rectangles.size() - 1; i >= 0; --i) {
                    if (i != selectedRectIndex && rectangles[i].isSelected == false) {
                        // �簢���� ��ġ���� Ȯ��
                        Rect& rect1 = rectangles[selectedRectIndex];
                        Rect& rect2 = rectangles[i];

                        bool isOverlap = !(rect1.x2 < rect2.x1 || rect1.x1 > rect2.x2 || rect1.y2 < rect2.y1 || rect1.y1 > rect2.y2);

                        if (isOverlap) {
                            // �ּ� �� �ִ� ��ǥ ���
                            float minX = std::min(rect1.x1, rect2.x1);
                            float minY = std::min(rect1.y1, rect2.y1);
                            float maxX = std::max(rect1.x2, rect2.x2);
                            float maxY = std::max(rect1.y2, rect2.y2);

                            // ���ο� �簢�� ����
                            Rect mergedRect;
                            mergedRect.x1 = minX;
                            mergedRect.y1 = minY;
                            mergedRect.x2 = maxX;
                            mergedRect.y2 = maxY;
                            mergedRect.r = (float)rand() / RAND_MAX;
                            mergedRect.g = (float)rand() / RAND_MAX;
                            mergedRect.b = (float)rand() / RAND_MAX;
                            mergedRect.isSelected = false;

                            // ���� �簢�� ���� �� ���ο� �簢�� �߰�
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
        // ���콺 �̵��� ���� �簢�� ��ġ ����
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
    srand(static_cast<unsigned>(time(0))); // ���� �õ� ����

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("�ǽ� 3: �簢�� �̵� �� ��ġ��");

    // GLEW ����: ���� �Լ��� ����ϹǷ� �ʿ� ����

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
#include <gl/glew.h> //--- �ʿ��� ������� include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <vector>
#include <cstdlib>
#include <ctime>

// �簢�� ����ü ����
struct Square {
    float x, y;           // ���� �߽� ��ǥ
    float size;           // ũ��
    float r, g, b;        // ����
    float dx, dy;         // �̵� �ӵ�
    bool movingDiagonal;  // �밢�� �̵� ����
    bool movingZigzag;    // ������� �̵� ����
    bool changingSize;    // ũ�� ��ȭ ����
    bool changingColor;   // ���� ��ȭ ����
    float originalX, originalY; // �ʱ� ��ġ
};

std::vector<Square> squares; // �簢�� ���
const int MAX_SQUARES = 5;   // �ִ� �簢�� ��

bool isMovingDiagonal = false;
bool isMovingZigzag = false;
bool isChangingSize = false;
bool isChangingColor = false;

void init() {
    // £�� ȸ�� ��� ����
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // �簢�� �׸���
    for (const auto& square : squares) {
        glColor3f(square.r, square.g, square.b);
        float halfSize = square.size / 2.0f;
        // glRectf �Լ� ����Ͽ� �簢�� �׸���
        glRectf(square.x - halfSize, square.y - halfSize, square.x + halfSize, square.y + halfSize);
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    // ����Ʈ ���� (���� �Լ� ���)
    glViewport(0, 0, w, h);
}

void timer(int value) {
    bool needRedisplay = false;

    for (auto& square : squares) {
        // �밢�� �̵�
        if (square.movingDiagonal) {
            square.x += square.dx;
            square.y += square.dy;

            // ���� ������ �ݻ�
            if (square.x + square.size / 2 > 1.0f || square.x - square.size / 2 < -1.0f)
                square.dx *= -1;
            if (square.y + square.size / 2 > 1.0f || square.y - square.size / 2 < -1.0f)
                square.dy *= -1;

            needRedisplay = true;
        }

        // ������� �̵�
        if (square.movingZigzag) {
            square.x += square.dx;
            square.y += square.dy * (((int)(square.x * 10) % 2 == 0) ? 1 : -1);

            // ���� ������ �ݻ�
            if (square.x + square.size / 2 > 1.0f || square.x - square.size / 2 < -1.0f)
                square.dx *= -1;
            if (square.y + square.size / 2 > 1.0f || square.y - square.size / 2 < -1.0f)
                square.dy *= -1;

            needRedisplay = true;
        }

        // ũ�� ��ȭ
        if (square.changingSize) {
            square.size += ((float)rand() / RAND_MAX - 0.5f) * 0.02f;
            if (square.size < 0.1f) square.size = 0.1f;
            if (square.size > 0.9f) square.size = 0.9f;
            needRedisplay = true;
        }

        // ���� ��ȭ
        if (square.changingColor) {
            square.r = (float)rand() / RAND_MAX;
            square.g = (float)rand() / RAND_MAX;
            square.b = (float)rand() / RAND_MAX;
            needRedisplay = true;
        }
    }

    if (needRedisplay)
        glutPostRedisplay();

    glutTimerFunc(16, timer, 0); // �� 60FPS�� ������Ʈ
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
    glutCreateWindow("�ǽ� 4: �簢�� ���� ���α׷�");

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
#include <gl/glew.h> //--- �ʿ��� ������� include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>



#elif PROB == 6
#endif


