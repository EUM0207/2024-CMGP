#define _CRT_SECURET_NO_WARNINGS


#define PROB 3

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
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

// �簢�� ��ǥ �� ���� ����
float rect1_x1 = -0.9f, rect1_y1 = -0.1f, rect1_x2 = -0.5f, rect1_y2 = 0.3f;
float rect2_x1 = 0.1f, rect2_y1 = -0.1f, rect2_x2 = 0.5f, rect2_y2 = 0.3f;
float rect3_x1 = -0.9f, rect3_y1 = -0.7f, rect3_x2 = -0.5f, rect3_y2 = -0.3f;
float rect4_x1 = 0.1f, rect4_y1 = -0.7f, rect4_x2 = 0.5f, rect4_y2 = -0.3f;

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
                rect1_x1 += 0.01f; rect1_y1 += 0.01f; // �簢�� ���
            }
            else if (xpos > rect2_x1 && xpos < rect2_x2 && ypos > rect2_y1 && ypos < rect2_y2) {
                rect2_x1 += 0.01f; rect2_y1 += 0.01f; // �簢�� ���
            }
            else if (xpos > rect3_x1 && xpos < rect3_x2 && ypos > rect3_y1 && ypos < rect3_y2) {
                rect3_x1 += 0.01f; rect3_y1 += 0.01f; // �簢�� ���
            }
            else if (xpos > rect4_x1 && xpos < rect4_x2 && ypos > rect4_y1 && ypos < rect4_y2) {
                rect4_x1 += 0.01f; rect4_y1 += 0.01f; // �簢�� ���
            }
            else {
                // �簢�� �ܺ� Ŭ�� �� ũ�� Ȯ��
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
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // for std::min and std::max

// �簢�� ����ü ����
struct Rectangle {
    float x1, y1, x2, y2;
    float r, g, b;
    bool isDragging = false;
};

// �簢�� ����Ʈ
std::vector<Rectangle> rectangles;
int maxRectangles = 10;
Rectangle* selectedRectangle = nullptr;
bool isDragging = false;
float lastX = 0.0f, lastY = 0.0f; // ���콺�� ������ ��ġ

// ���� ���� ����
void setRandomColor(Rectangle& rect) {
    rect.r = static_cast<float>(rand()) / RAND_MAX;
    rect.g = static_cast<float>(rand()) / RAND_MAX;
    rect.b = static_cast<float>(rand()) / RAND_MAX;
}

// ���� ��ġ�� �簢�� ����
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

// ��ġ�� �簢�� ����
void mergeRectangles(Rectangle& rect1, Rectangle& rect2) {
    rect1.x1 = std::min(rect1.x1, rect2.x1);
    rect1.y1 = std::min(rect1.y1, rect2.y1);
    rect1.x2 = std::max(rect1.x2, rect2.x2);
    rect1.y2 = std::max(rect1.y2, rect2.y2);
    setRandomColor(rect1);

    // ���յ� �簢���� ����Ʈ���� ����
    rectangles.erase(std::remove(rectangles.begin(), rectangles.end(), rect2), rectangles.end());
}

// �巡�� �� �簢�� �̵�
void moveRectangle(Rectangle* rect, float dx, float dy) {
    rect->x1 += dx;
    rect->y1 += dy;
    rect->x2 += dx;
    rect->y2 += dy;
}

// �簢�� �׸���
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

// â ũ�� ���� �� ó��
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

// Ű���� �Է� ó��
void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') {
        addRandomRectangle();
    }
    else if (key == 'q') {
        exit(0);
    }
    glutPostRedisplay();
}

// �簢�� ����
Rectangle* findRectangleAt(float xpos, float ypos) {
    for (int i = rectangles.size() - 1; i >= 0; --i) {
        Rectangle& rect = rectangles[i];
        if (xpos > rect.x1 && xpos < rect.x2 && ypos > rect.y1 && ypos < rect.y2) {
            return &rect;
        }
    }
    return nullptr;
}

// ���콺 Ŭ�� �� �巡�� ó��
void mouse(int button, int state, int x, int y) {
    float xpos = (x / 400.0f) - 1.0f;
    float ypos = 1.0f - (y / 300.0f);

    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        selectedRectangle = findRectangleAt(xpos, ypos);
        if (selectedRectangle != nullptr) {
            isDragging = true;
            lastX = xpos; // ���콺 Ŭ�� ������ ��ǥ�� ����
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
    glutMotionFunc(motion);

    glutMainLoop();

    return 0;
}


#elif PROB == 4
#elif PROB == 5
#elif PROB == 6
#endif


