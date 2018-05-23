#include <windows.h>
#include <gl/glut.h>
#include <math.h>

GLfloat angulo = 0;					//controla o angulo das rodas
GLfloat translateX = 0;				//controla o movimento das faixas
GLfloat predioTX = 0; 				//controla o movimento dos predios
GLfloat r = 1.0f, g = 0.0f, b = 0.0f;

void circulo(float r, float g, float b, int inicio, int fim)
{
	float pi = 3.14159265358979323846;
		 glBegin(GL_POLYGON);
			glColor3f(r, g, b);
			for(int i = inicio; i <fim; i++)
			{
				float x = (float) cos(i*2*pi/100);
				float y = (float) sin(i*2*pi/100);
				glVertex2f(x, y);
			}
		glEnd();
}

void faixa()											//Desenha as faixas amarelas na pista
{
glPushMatrix();
	glTranslatef(translateX, 0.0f, 0.0f);				//controle de movimento das faixas
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-0.2f, -0.05f);
		glVertex2f(-0.2f, -0.1f);
		glVertex2f(0.2f, -0.1f);
		glVertex2f(0.2f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-1.0f, -0.05f);
		glVertex2f(-1.0f, -0.1f);
		glVertex2f(-0.6f, -0.1f);
		glVertex2f(-0.6f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(0.6f, -0.05f);
		glVertex2f(0.6f, -0.1f);
		glVertex2f(1.0f, -0.1f);
		glVertex2f(1.0f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-1.4f, -0.05f);
		glVertex2f(-1.4f, -0.1f);
		glVertex2f(-1.8f, -0.1f);
		glVertex2f(-1.8f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(1.4f, -0.05f);
		glVertex2f(1.4f, -0.1f);
		glVertex2f(1.8f, -0.1f);
		glVertex2f(1.8f, -0.05f);
	glEnd();
glPopMatrix();
}

void predios()													//Desenha os prédios ao fundo
{
glPushMatrix();
	glTranslatef(predioTX, 0.0f, 0.0f);							//Controle de movimento dos prédios

	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex2f(-1.0f, 0.0f);
		glVertex2f(-1.0f, 0.8f);
		glVertex2f(-0.5f, 0.8f);
		glVertex2f(-0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex2f(-0.45f, 0.0f);
		glVertex2f(-0.45f, 1.0f);
		glVertex2f(0.0f, 1.0f);
		glVertex2f(0.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex2f(0.05f, 0.0f);
		glVertex2f(0.05f, 0.6f);
		glVertex2f(0.5f, 0.6f);
		glVertex2f(0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex2f(0.6f, 0.0f);
		glVertex2f(0.6f, 0.9f);
		glVertex2f(1.0f, 0.9f);
		glVertex2f(1.0f, 0.0f);
	glEnd();
glPopMatrix();
}

void pista()													//Desenha a parte de baixo da tela, pista e grama
{
	glBegin(GL_QUADS);						//rua
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(-1.0f, 0.0f);
		glVertex2f(1.0f, 0.0f);
		glVertex2f(1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);						//grama
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(-1.0f, -0.5f);
		glVertex2f(1.0f, -0.5f);
		glVertex2f(1.0f, -1.0f);
	glEnd();

	faixa();
}

void cenario()															//adiciona uma lua, a pista e os predios
{
	glPushMatrix();							//lua
		glScalef(0.2f, 0.2f, 0.2f);
		glTranslatef(4.0f, 4.0f, 0.0f);
		circulo(1.0f, 1.0f, 0.0f, 0, 100);
	glPopMatrix();

	predios();
	pista();
}

void roda()															//Faz a roda do carro
{

	circulo(0.1f, 0.1f, 0.1f, 0, 100);				//Pneu

	glPushMatrix();									//Roda
		glScalef(0.8f, 0.8f, 0.0f);
		circulo(0.55f, 0.55f, 0.55f, 0, 100);
	glPopMatrix();

	glPushMatrix();									//Disco de/e freio
			glScalef(0.4f, 0.4f, 0.4f);
			circulo(0.7f, 0.7f, 0.7f, 0, 100);
			circulo(0.0f, 0.0f, 1.0f, 10, 40);
	glPopMatrix();

	arosEparafusos();
}

void arosEparafusos()												//Desenha o aro e os parafusos
{
glPushMatrix();

	glRotatef(angulo, 0.0f, 0.0f, 1.0f);							//Controle de rotação do aro e dos parafusos
	glPushMatrix();							//Aros da roda
		glScalef(0.8f, 0.8f, 0.0f);

		glBegin(GL_POLYGON);
			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex2f(-0.1f, 0.1f);
			glVertex2f(-0.1f, 1.0f);
			glVertex2f(0.1f, 1.0f);
			glVertex2f(0.1f, 0.1f);

			glVertex2f(0.1f, 0.1f);
			glVertex2f(1.0f, 0.1f);
			glVertex2f(1.0f, -0.1f);
			glVertex2f(0.1f, -0.1f);
			glVertex2f(0.1f, -0.1f);
			glVertex2f(0.1f, -1.0f);
			glVertex2f(-0.1f, -1.0f);
			glVertex2f(-0.1f, -0.1f);

			glVertex2f(-0.1f, -0.1f);
			glVertex2f(-1.0f, -0.1f);
			glVertex2f(-1.0f, 0.1f);
			glVertex2f(-0.1f, 0.1f);
		glEnd();
	glPopMatrix();

	glPushMatrix();									//Parafusos da roda
		glScalef(0.03f, 0.03f, 0.0f);
			glPushMatrix();
				glTranslatef(-1.5f, 0.0f, 0.0f);
				circulo(0.5f, 0.5f, 0.5f, 0, 100);
			glPopMatrix();

		glPushMatrix();
			glTranslatef(1.5f, 0.0f, 0.0f);
				circulo(0.5f, 0.5f, 0.5f, 0, 100);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0f, -1.5f, 0.0f);
				circulo(0.5f, 0.5f, 0.5f, 0, 100);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0f, 1.5f, 0.0f);
				circulo(0.5f, 0.5f, 0.5f, 0, 100);
		glPopMatrix();
	glPopMatrix();
glPopMatrix();
}

void lataria()															//Desenha o carro
{
	glBegin(GL_POLYGON);						//Farol
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-0.72f, 0.11);
		glVertex2f(-0.68, 0.12f);
		glVertex2f(-0.66, 0.14f);
		glVertex2f(-0.68, 0.16f);
		glVertex2f(-0.72, 0.16f);
		glVertex2f(-0.7, 0.18f);
		glVertex2f(-0.68, 0.19f);
		glVertex2f(-0.66, 0.19f);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-0.74,0.11);
		glVertex2f(-0.99,0.03);

		glVertex2f(-0.74,0.12);
		glVertex2f(-0.99,0.08);

		glVertex2f(-0.74,0.13);
		glVertex2f(-0.99,0.12);

		glVertex2f(-0.74,0.14);
		glVertex2f(-0.99,0.15);

		glVertex2f(-0.74,0.15);
		glVertex2f(-0.99,0.19);

		glVertex2f(-0.74,0.16);
		glVertex2f(-0.99,0.25);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.5f, 0.5f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(-0.65f, 0.0f);
		glVertex2f(-0.72f, 0.04f);
		glVertex2f(-0.74f, 0.07f);
		glVertex2f(-0.74f, 0.1);
		glVertex2f(-0.72f, 0.11);

		glVertex2f(-0.68f, 0.12f);		//Espaço para o farol
		glVertex2f(-0.66f, 0.14f);
		glVertex2f(-0.68f, 0.16f);
		glVertex2f(-0.72f, 0.16f);
		glVertex2f(-0.71f, 0.18f);
		glVertex2f(-0.69f, 0.2f);
		glVertex2f(-0.67f, 0.21f);

		glVertex2f(-0.3f, 0.28f);
		glVertex2f(-0.15f, 0.45f);
		glVertex2f(0.15f, 0.45f);
		glVertex2f(0.15f, 0.25f);
		glVertex2f(0.72, 0.25f);
		glVertex2f(0.72f, 0.07f);
		glVertex2f(0.74f, 0.05);
		glVertex2f(0.74f, 0.01f);
		glVertex2f(0.72f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.1f, 0.1f, 0.1f);
		glVertex2f(-0.27f, 0.28f);
		glVertex2f(-0.14f, 0.43f);
		glVertex2f(0.10f, 0.43f);
		glVertex2f(0.10f, 0.28f);
	glEnd();

	farol();
}

void farol()											//Desenha a lanterna traseira
{
	glBegin(GL_QUADS);									//Vermelho
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.68f, 0.2f);
		glVertex2f(0.68f, 0.1f);
		glVertex2f(0.72f, 0.1f);
		glVertex2f(0.72f, 0.2f);
	glEnd();

	glBegin(GL_QUADS);									//Branco
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(0.68f, 0.2f);
		glVertex2f(0.68f, 0.16f);
		glVertex2f(0.72f, 0.16f);
		glVertex2f(0.72f, 0.2f);
	glEnd();

	glBegin(GL_QUADS);									//Amarelo
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.68f, 0.18f);
		glVertex2f(0.68f, 0.16f);
		glVertex2f(0.72f, 0.16f);
		glVertex2f(0.72f, 0.18f);
	glEnd();

	glBegin(GL_LINES);									//linhas da luz
		glColor3f(r, g, b);
		glVertex2f(0.74f, 0.2f);
		glVertex2f(0.9f, 0.3f);

		glVertex2f(0.74f, 0.19f);
		glVertex2f(0.9f, 0.25f);

		glVertex2f(0.74f, 0.16f);
		glVertex2f(0.9f, 0.16f);

		glVertex2f(0.74f, 0.18f);
		glVertex2f(0.9f, 0.18f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.74f, 0.1f);
		glVertex2f(0.9f, 0.0f);

		glVertex2f(0.74f, 0.14f);
		glVertex2f(0.9f, 0.14f);

		glVertex2f(0.74f, 0.12f);
		glVertex2f(0.9f, 0.12f);

		glVertex2f(0.74f, 0.11f);
		glVertex2f(0.9f, 0.05f);
	glEnd();
}


void desenha()											//Junta todas as partes e desenha
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.35f, 0.38f, 0.61f, 1.0f);

	glPushMatrix();
		glTranslatef(0.0f, -0.1f, 0.0f);
		cenario();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f);
		lataria();
	glPopMatrix();

	glPushMatrix();								//Rodas do carro
		glScalef(0.1f, 0.1f, 0.1f);

		glPushMatrix();
			glTranslatef(-4.0f, 0.0f, 0.0f);
			roda();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(4.0f, 0.0f, 0.0f);
			roda();
		glPopMatrix();

	glPopMatrix();								//Fim - rodas
	glFlush();
}


void TeclasEspeciais(int key, int x, int y)								//Movimento para as rodas e para as faixas da pista
{
	if(translateX > 0.7f || translateX < -0.7f)			//Controla a repetição das faixas da pista
		translateX = 0.0f;

	if(predioTX > 2.0f)									//Controla a repetição dos predios
		predioTX = -2.0f;
	if(predioTX < -2.0f)
		predioTX = 2.0f;

    if(key == GLUT_KEY_LEFT)
    {
    	angulo += 20;
    	translateX += 0.1f;
    	predioTX += 0.1f;
    	r = 1.0f;
    	g = 0.0f;
    	b = 0.0f;
    }
    if(key == GLUT_KEY_RIGHT)
    {
    	angulo -= 10;
    	translateX -= 0.05f;
    	predioTX -= 0.05f;
    	r = 1.0f;
    	g = 1.0f;
    	b = 1.0f;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
	 glutInit(&argc, argv);
	 glutInitWindowSize(500,500);
	 glutInitWindowPosition(50,50);
     glutCreateWindow("Carro");
     glutDisplayFunc(desenha);
     glutSpecialFunc(TeclasEspeciais);
     glutMainLoop();
     return(0);
}
