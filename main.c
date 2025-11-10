#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>

// Definições Globais e Variáveis de Estado

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TIMER_INTERVAL 10

GLfloat posX = WINDOW_WIDTH / 2.0f;  // Posição inicial X
GLfloat posY = WINDOW_HEIGHT / 2.0f; // Posição inicial Y

#define ORIGINAL_SIZE 50.0f
#define MAX_SIZE_INCREASE (ORIGINAL_SIZE * 0.20f)
#define MAX_SIZE (ORIGINAL_SIZE + MAX_SIZE_INCREASE)
#define SIZE_INCREMENT (ORIGINAL_SIZE * 0.01f)

GLfloat currentSize = ORIGINAL_SIZE;

GLfloat dirX = 1.0f;
GLfloat dirY = 1.0f; 
const GLfloat SPEED = 3.0f; 

GLfloat colorR = 0.2f;
GLfloat colorG = 0.3f;
GLfloat colorB = 0.8f;


//Funções de Lógica

//Gera uma nova cor aleatória para o quadrado.

void generateRandomColor() {
    colorR = (GLfloat)(rand() % 100) / 100.0f;
    colorG = (GLfloat)(rand() % 100) / 100.0f;
    colorB = (GLfloat)(rand() % 100) / 100.0f;
}

/**
 * @brief Lida com a colisão, alterando direção, cor e tamanho.
 * @param isXCollision Indica se houve colisão no eixo X.
 * @param isYCollision Indica se houve colisão no eixo Y.
 */
void handleCollision(int isXCollision, int isYCollision) {
    if (isXCollision || isYCollision) {
        generateRandomColor();

        currentSize = fmin(currentSize + SIZE_INCREMENT, MAX_SIZE);

        if (isXCollision) {
            dirX *= -1.0f; 
        }
        if (isYCollision) {
            dirY *= -1.0f;
        }
    }
}

/**
 * @brief Função de temporizador para a animação e atualização da lógica
 * @param value Valor passado pelo glutTimerFunc (não utilizado aqui)
 */
void timer(int value) {
    posX += dirX * SPEED;
    posY += dirY * SPEED;

    GLfloat halfSize = currentSize / 2.0f;

    int collisionX = 0;
    int collisionY = 0;

    if (posX + halfSize > WINDOW_WIDTH) {
        posX = WINDOW_WIDTH - halfSize;
        collisionX = 1;
    }

    if (posX - halfSize < 0) {
        posX = halfSize;
        collisionX = 1;
    }

    if (posY + halfSize > WINDOW_HEIGHT) {
        posY = WINDOW_HEIGHT - halfSize;
        collisionY = 1;
    }

    if (posY - halfSize < 0) {
        posY = halfSize;
        collisionY = 1;
    }

    handleCollision(collisionX, collisionY);

    glutPostRedisplay();

    glutTimerFunc(TIMER_INTERVAL, timer, 0);
}


// Funções de Renderização e GLUT

/**
 * @brief Desenha o quadrado na posição e tamanho atuais
 */
void drawSquare() {
    GLfloat halfSize = currentSize / 2.0f;

    glColor3f(colorR, colorG, colorB);

    glBegin(GL_QUADS);

        glVertex2f(posX - halfSize, posY - halfSize);
        glVertex2f(posX + halfSize, posY - halfSize);
        glVertex2f(posX + halfSize, posY + halfSize);
        glVertex2f(posX - halfSize, posY + halfSize);
    glEnd();
}

/**
 * @brief Função de callback de desenho da GLUT
 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawSquare();

    glutSwapBuffers();
}

/**
 * @brief Função de callback de redimensionamento da janela
 * @param w Nova largura da janela.
 * @param h Nova altura da janela.
 */
void reshape(int w, int h) {

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
 * @brief Inicialização dos parâmetros gráficos.
 */
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    srand(time(NULL));
}

// Função Principal

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Projeto: Animação de Quadrado 2D");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(TIMER_INTERVAL, timer, 0);

    glutMainLoop();

    return 0;
}
