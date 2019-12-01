#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>

#ifdef _APPLE_

#else
#include <glut.h>
#endif

#include "imageloader.h"

using namespace std;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xkey = 0.0f, ykey = 0.0f, zkey = 0.0f;
bool mouseDown = false;
bool dalam = false;
GLuint _textureId4;

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void initRendering() {
	Image* gambar4 = loadBMP("hantu.bmp");
	_textureId4 = loadTexture(gambar4);
	delete gambar4;
}

void Inisialisasi(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glOrtho(200, -200, 200, -200, 200, -200);
}
void tekstur(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(50, 10, 80.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(70, 10, 80.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(70, 20, 80.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(50, 20, 80.1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void kotakdepan(float a, float b, float c, float d, float e,float f, float g, float h){
	glColor3f(f, g, h);
	glBegin(GL_QUADS);
	glVertex3d(a, b, c);
	glVertex3d(d, b, c);
	glVertex3d(d, e, c);
	glVertex3d(a, e, c);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3d(a, b, c);
	glVertex3d(d, b, c);
	glVertex3d(d, e, c);
	glVertex3d(a, e, c);
	glEnd();
}
void kotaksamping(float c, float b, float a, float d, float e,float f,float g,float h,float i){
	glColor3f(g, h, i);
	glBegin(GL_QUADS);
	glVertex3f(c, b, a);
	glVertex3f(c, b, d);
	glVertex3f(f, e, d);
	glVertex3f(f, e, a);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(c, b, a);
	glVertex3f(c, b, d);
	glVertex3f(f, e, d);
	glVertex3f(f, e, a);
	glEnd();
}

void atapsegitiga(){
	glColor3f(0, 0, 1);
	kotakdepan(20, 43.2, 60, -20, 40, 0.9, 0.8, 0.6);//bawah
	kotakdepan(19.9, 45, 60, -19.9, 43.2, 0.4, 0.2, 0);//atas
	kotaksamping(0, 60, 60.1, 62, 45, 20, 0.9, 0.8, 0.5);//bawahdalamsmp
	kotaksamping(0, 60, 60.1, 62, 45, -20, 0.9, 0.8, 0.5);//bawahdalamsmp
	kotaksamping(-20, 44.9, 0, 62, 43.2, -20, 0.4, 0.2, 0);//dalam
	kotaksamping(20, 44.9, 0, 62, 43.2, 20, 0.4, 0.2, 0);//dalam
	kotaksamping(20, 43.2, 0, 62, 43.2, 25, 0.9, 0.8, 0.5);//bawah
	kotaksamping(-20, 43.2, 0, 62, 43.2, -25, 0.9, 0.8, 0.5);//bawah
	kotaksamping(20, 43.2, 50.1, 60, 40, 20, 0.9, 0.8, 0.6);//samping
	kotaksamping(-20, 43.2, 50.1, 60, 40, -20, 0.9, 0.8, 0.6);//samping
	kotaksamping(0, 62, 0, 62, 43.2, 25, 0.2, 0.2, 0.2);//atas
	kotaksamping(0, 62, 0, 62, 43.2, -25, 0.2, 0.2, 0.2);//atas
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.2, 0);
	glVertex3f(0, 60, 60);
	glVertex3f(-20, 45, 60);
	glVertex3f(20, 45, 60);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.8, 0.6);
	glVertex3f(-20, 45, 62);
	glVertex3f(0, 60, 62);
	glVertex3f(0, 62, 62);
	glVertex3f(-25, 43.2, 62);
	glVertex3f(-20, 43.2, 62);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20, 45, 62);
	glVertex3f(0, 60, 62);
	glVertex3f(0, 62, 62);
	glVertex3f(25, 43.2, 62);
	glVertex3f(20, 43.2, 62);
	glEnd();
}

void atap(float a,float b,float c,float d,float e, float f,float g, float h, float i,float j,
	float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float ii, float jj){
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.8,0.5 );//alas
	glVertex3f(a, b, c);
	glVertex3f(d, b, c);
	glVertex3f(d, b, e);
	glVertex3f(a, b, e);

	glColor3f(0.25, 0.25, 0.25);//tutup
	glVertex3f(f, g, j);
	glVertex3f(i, g, j);
	glVertex3f(i, g, h);
	glVertex3f(f, g, h);

	glColor3f(0.2, 0.2, 0.2);//kulit depan
	glVertex3f(f, g, h);
	glVertex3f(i, g, h);
	glVertex3f(d, b, e);
	glVertex3f(a, b, e);

	glColor3f(0.2, 0.2, 0.2);//kulit belakang
	glVertex3f(f, g, j);
	glVertex3f(i, g, j);
	glVertex3f(d, b, c);
	glVertex3f(a, b, c);
	
	glColor3f(0.2, 0.2, 0.2);//kulit kanan
	glVertex3f(f, g, j);
	glVertex3f(f, g, h);
	glVertex3f(a, b, e);
	glVertex3f(a, b, c);

	glColor3f(0.2, 0.2, 0.2);//kulit kiri
	glVertex3f(i, g, h);
	glVertex3f(i, g, j);
	glVertex3f(d, b, c);
	glVertex3f(d, b, e);
	
	glColor3f(0.9, 0.8, 0.6);//sela depan
	glVertex3f(ff, gg, hh);
	glVertex3f(ii, gg, hh);
	glVertex3f(dd, bb, ee);
	glVertex3f(aa, bb, ee);
//sela belakang
	glVertex3f(ff, gg, jj);
	glVertex3f(ii, gg, jj);
	glVertex3f(dd, bb, cc);
	glVertex3f(aa, bb, cc);
//sela kanan
	glVertex3f(ff, gg, jj);
	glVertex3f(ff, gg, hh);
	glVertex3f(aa, bb, ee);
	glVertex3f(aa, bb, cc);
//sela kiri
	glVertex3f(ii, gg, hh);
	glVertex3f(ii, gg, jj);
	glVertex3f(dd, bb, cc);
	glVertex3f(dd, bb, ee);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(a, b, c);
	glVertex3f(d, b, c);
	glVertex3f(d, b, e);
	glVertex3f(a, b, e);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(f, g, j);
	glVertex3f(i, g, j);
	glVertex3f(i, g, h);
	glVertex3f(f, g, h);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(f, g, h);
	glVertex3f(i, g, h);
	glVertex3f(d, b, e);
	glVertex3f(a, b, e);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(f, g, j);
	glVertex3f(i, g, j);
	glVertex3f(d, b, c);
	glVertex3f(a, b, c);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(f, g, j);
	glVertex3f(f, g, h);
	glVertex3f(a, b, e);
	glVertex3f(a, b, c);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(i, g, h);
	glVertex3f(i, g, j);
	glVertex3f(d, b, c);
	glVertex3f(d, b, e);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(ff, gg, hh);
	glVertex3f(ii, gg, hh);
	glVertex3f(dd, bb, ee);
	glVertex3f(aa, bb, ee);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(ff, gg, jj);
	glVertex3f(ii, gg, jj);
	glVertex3f(dd, bb, cc);
	glVertex3f(aa, bb, cc);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(ff, gg, jj);
	glVertex3f(ff, gg, hh);
	glVertex3f(aa, bb, ee);
	glVertex3f(aa, bb, cc);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(ii, gg, hh);
	glVertex3f(ii, gg, jj);
	glVertex3f(dd, bb, cc);
	glVertex3f(dd, bb, ee);
	glEnd();
}
void ataptumpuk(){
	atap(60, 30, -60, -60, 60, 50, 40, 50, -50, -50, 57, 28, -57, -57, 57, 57, 30, 57, -57, -57);//bawah
	atap(55, 43, -55, -55, 55, 40, 55, 40, -40, -40, 50, 40, -50, -50, 50, 50, 43, 50, -50, -50);//tengah
	atap(40, 60, -40, -40, 40, 20, 100, 2.5, -20, -2.5, 35, 43, -35, -35, 35, 35, 60, 35, -35, -35);//atas
	atap(35, 30, 60.1, -35, 75, 25, 40, 65, -25, 50.1, 32, 28, 57, -32, 72, 32, 30, 72, -32, 57.1);//muka
	atapsegitiga();
}
void ornamendepan(float a, float b, float c, float d, float e, float f, float g, float h,
	float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float jml){
	for (int i = 0; i < jml; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.6, 0.3, 0);
		glVertex3f(a + i * 3, d, h);
		glVertex3f(b + i * 3, d, h);
		glVertex3f(b + i * 3, e, h);
		glVertex3f(c + i * 3, f, h);
		glVertex3f(a + i * 3, g, h);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(aa + i * 3, dd, hh);
		glVertex3f(aa + i * 3, ee, hh);
		glVertex3f(bb + i * 3, ff, hh);
		glVertex3f(cc + i * 3, gg, hh);
		glVertex3f(cc + i * 3, dd, hh);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(a + i * 3, d, h);
		glVertex3f(b + i * 3, d, h);
		glVertex3f(b + i * 3, e, h);
		glVertex3f(c + i * 3, f, h);
		glVertex3f(a + i * 3, g, h);
		glVertex3f(bb + i * 3, ff, hh);
		glVertex3f(cc + i * 3, gg, hh);
		glVertex3f(cc + i * 3, dd, hh);
		glEnd();
	}
}
void ornamensamping(float a, float b, float c, float d, float e, float f, float g, float h,
	float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float jml){
	for (int i = 0; i < jml; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.6, 0.3, 0);
		glVertex3f(h, d, a + i * 3);
		glVertex3f(h, d, b + i * 3);
		glVertex3f(h, e, b + i * 3);
		glVertex3f(h, f, c + i * 3);
		glVertex3f(h, g, a + i * 3);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(hh, dd, aa + i * 3);
		glVertex3f(hh, ee, aa + i * 3);
		glVertex3f(hh, ff, bb + i * 3);
		glVertex3f(hh, gg, cc + i * 3);
		glVertex3f(hh, dd, cc + i * 3);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(h, d, a + i * 3);
		glVertex3f(h, d, b + i * 3);
		glVertex3f(h, e, b + i * 3);
		glVertex3f(h, f, c + i * 3);
		glVertex3f(h, g, a + i * 3);
		glVertex3f(hh, ff, bb + i * 3);
		glVertex3f(hh, gg, cc + i * 3);
		glVertex3f(hh, dd, cc + i * 3);
		glEnd();
	}
}
void ornamen(){
	ornamendepan(-55.5, -56, -57, 28, 27, 26.5, 25, 57, -55.5, -54, -55, 28, 25, 26.5, 27, 57, 38);
	ornamendepan(-55.5, -56, -57, 28, 27, 26.5, 25, -57, -55.5, -54, -55, 28, 25, 26.5, 27, -57, 38);//belakang
	ornamendepan(-53.5, -54, -55, 43, 42, 41.5, 40, 55, -53.5, -52, -53, 43, 40, 41.5, 42, 55, 36);
	ornamendepan(-53.5, -54, -55, 43, 42, 41.5, 40, -55, -53.5, -52, -53, 43, 40, 41.5, 42, -55, 36);//belakang
	ornamendepan(-38.5, -39, -40, 60, 59, 58.5, 57, 40, -38.5, -37, -38, 60, 57, 58.5, 59, 40, 26);
	ornamendepan(-38.5, -39, -40, 60, 59, 58.5, 57, -40, -38.5, -37, -38, 60, 57, 58.5, 59, -40, 26);//belakang
	ornamensamping(-55.5, -56, -57, 28, 27, 26.5, 25, 57, -55.5, -54, -55, 28, 25, 26.5, 27, 57, 38);
	ornamensamping(-55.5, -56, -57, 28, 27, 26.5, 25, -57, -55.5, -54, -55, 28, 25, 26.5, 27, -57, 38);//kiri
	ornamensamping(-53.5, -54, -55, 43, 42, 41.5, 40, 55, -53.5, -52, -53, 43, 40, 41.5, 42, 55, 36);
	ornamensamping(-53.5, -54, -55, 43, 42, 41.5, 40, -55, -53.5, -52, -53, 43, 40, 41.5, 42, -55, 36);//kiri
	ornamensamping(-38.5, -39, -40, 60, 59, 58.5, 57, 40, -38.5, -37, -38, 60, 57, 58.5, 59, 40, 26);
	ornamensamping(-38.5, -39, -40, 60, 59, 58.5, 57, -40, -38.5, -37, -38, 60, 57, 58.5, 59, -40, 26);//kiri
	ornamendepan(-31.5, -32, -33, 28, 27, 26.5, 25, 72, -31.5, -30, -31, 28, 25, 26.5, 27, 72, 22);//muka
	glPushMatrix();
	glRotatef(-36, 0, 0, 1);
	glTranslatef(-32.5, -9.7, 0);
	ornamendepan(2.5, 3, 4, 58, 57, 56.5, 55, 62, 2.5, 1, 2, 58, 55, 56.5, 57, 62, 7);//mukaatas
	glPopMatrix();
	glPushMatrix();
	glRotatef(36, 0, 0, 1);
	glTranslatef(9.5, -9.7, 0);
	ornamendepan(2.5, 3, 4, 58, 57, 56.5, 55, 62, 2.5, 1, 2, 58, 55, 56.5, 57, 62, 7);//mukaatas
	glPopMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.3, 0);
	glVertex3f(0, 60, 62);
	glVertex3f(-2, 58.5, 62);
	glVertex3f(0, 53, 62);
	glVertex3f(2, 58.5, 62);

	glColor3f(0.6, 0.1, 0);
	glVertex3f(0, 60, 62.1);
	glVertex3f(-2, 58.5, 62.1);
	glVertex3f(0, 57, 62.1);
	glVertex3f(2, 58.5, 62.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3f(0, 60, 62);
	glVertex3f(-2, 58.5, 62);
	glVertex3f(0, 53, 62);
	glVertex3f(2, 58.5, 62);

	glVertex3f(0, 60, 62.1);
	glVertex3f(-2, 58.5, 62.1);
	glVertex3f(0, 57, 62.1);
	glVertex3f(2, 58.5, 62.1);
	glEnd();
}
void tinggi(){
	glBegin(GL_QUADS);
	//depan
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50, 30, 50);
	glVertex3f(50, 30, 50);
	glVertex3f(50, 0, 50);
	glVertex3f(-50, 0, 50);
	glEnd();
}
void persegi_panjang_miring(float a, float b, float c, float d, float e, float j, float o, float p, float k){
	if (k == 1)glColor3f(0.4, 0.2, 0);
	else glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_QUADS);
	//depan
	glVertex3f(a, b, e);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(a, d, e);
	//belakang
	glVertex3f(a, o, j);
	glVertex3f(c, o, j);
	glVertex3f(c, p, j);
	glVertex3f(a, p, j);
	//kiri
	glVertex3f(a, p, j);
	glVertex3f(a, d, e);
	glVertex3f(a, b, e);
	glVertex3f(a, o, j);
	//kanan
	glVertex3f(c, p, j);
	glVertex3f(c, d, e);
	glVertex3f(c, b, e);
	glVertex3f(c, o, j);
	// atas
	glVertex3f(c, d, e);
	glVertex3f(c, p, j);
	glVertex3f(a, p, j);
	glVertex3f(a, d, e);
	//bawah
	glVertex3f(c, b, e);
	glVertex3f(c, o, j);
	glVertex3f(a, o, j);
	glVertex3f(a, b, e);
	glEnd();

	//border 
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	//depan
	glVertex3f(a, b, e);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(a, d, e);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//kiri
	glVertex3f(a, d, e);
	glVertex3f(a, b, e);
	glVertex3f(a, o, j);
	glVertex3f(a, p, j);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//kanan
	glVertex3f(c, o, j);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(c, p, j);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//belakang
	glVertex3f(a, p, j);
	glVertex3f(c, p, j);
	glVertex3f(c, o, j);
	glVertex3f(a, o, j);
	glEnd();
}
void persegi_panjang(float a, float b, float c, float d, float e, float j, float k){
	glBegin(GL_QUADS);
	if (k == 1)glColor3f(0.1, 0.1, 0.1);
	else glColor3f(k, 0.2, 0);
	//depan
	glVertex3f(a, b, e);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(a, d, e);
	//belakang
	glVertex3f(a, b, j);
	glVertex3f(c, b, j);
	glVertex3f(c, d, j);
	glVertex3f(a, d, j);
	//kiri
	glVertex3f(a, b, j);
	glVertex3f(a, b, e);
	glVertex3f(a, d, e);
	glVertex3f(a, d, j);
	//kanan
	glVertex3f(c, b, j);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(c, d, j);
	// atas
	glVertex3f(c, d, e);
	glVertex3f(c, d, j);
	glVertex3f(a, d, j);
	glVertex3f(a, d, e);
	//bawah
	glVertex3f(c, b, e);
	glVertex3f(c, b, j);
	glVertex3f(a, b, j);
	glVertex3f(a, b, e);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	//depan
	glVertex3f(a, b, e);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(a, d, e);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//kiri
	glVertex3f(a, d, e);
	glVertex3f(a, b, e);
	glVertex3f(a, b, j);
	glVertex3f(a, d, j);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//belakang
	glVertex3f(a, d, j);
	glVertex3f(c, d, j);
	glVertex3f(c, b, j);
	glVertex3f(a, b, j);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//kanan
	glVertex3f(c, b, j);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(c, d, j);
	glEnd();
}
void persegi_panjang1(float a, float b, float c, float d, float e, float j, float k){
	glBegin(GL_QUADS);
	glColor3f(k, 0.2, 0);
	//depan
	glVertex3f(a, b, e);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(a, d, e);
	//belakang
	glVertex3f(a, b, j);
	glVertex3f(c, b, j);
	glVertex3f(c, d, j);
	glVertex3f(a, d, j);
	//kiri
	glVertex3f(a, b, j);
	glVertex3f(a, b, e);
	glVertex3f(a, d, e);
	glVertex3f(a, d, j);
	//kanan
	glVertex3f(c, b, j);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(c, d, j);
	//bawah
	glVertex3f(c, b, e);
	glVertex3f(c, b, j);
	glVertex3f(a, b, j);
	glVertex3f(a, b, e);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	//depan
	glVertex3f(a, b, e);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(a, d, e);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//kiri
	glVertex3f(a, d, e);
	glVertex3f(a, b, e);
	glVertex3f(a, b, j);
	glVertex3f(a, d, j);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//belakang
	glVertex3f(a, d, j);
	glVertex3f(c, d, j);
	glVertex3f(c, b, j);
	glVertex3f(a, b, j);
	glEnd();
	glBegin(GL_LINE_LOOP);
	//kanan
	glVertex3f(c, b, j);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(c, d, j);
	glEnd();
}
void tiang_bawah(){
	int a = -46, b = 0, c = -44, d = 2, e = 46, f = 44;
	float g = -45.5, h = 0, m = -44.5, n = 10, k = 45.5, l = 44.5;
	int byk = 0;
	for (int j = 0; j < 8; j++){
		if (j < 2 || j>5) byk = 10;
		else byk = 9;
		for (int i = 0; i < byk; i++){
			persegi_panjang(a, b, c, d, e, f, 0.4);
			persegi_panjang(g, h, m, n, k, l, 0.4);
			k -= 10, l -= 10, e -= 10, f -= 10;
			if (j < 2 || j>5){
				if (i % 2 == 0){
					persegi_panjang(g, 7, m, n, k, l + 10, 0.4);
				}
				if (j % 2 == 0){
					persegi_panjang(g, 8, m + 13, n, k + 10, l + 10, 0.4);
				}
			}
			else{
				if (i % 2 == 1){
					persegi_panjang(g, 7, m, n, k, l + 10, 0.4);
				}
				if (j % 2 == 0){
					persegi_panjang(g, 8, m + 13, n, k + 10, l + 10, 0.4);
				}
			}
		}
		a += 13, c += 13, e = 46, f = 44, g += 13, m += 13, k = 45.5, l = 44.5;
	}
}
void papan(){
	persegi_panjang(51, 10, 50, 0, 80, 79, 0.4);
	persegi_panjang(70, 10, 69, 0, 80, 79, 0.4);
	persegi_panjang(70, 20, 50, 10, 80, 79, 0.5);
}
void alas(){
	glBegin(GL_QUADS);
	//atas
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-50, 0, 80);
	glVertex3f(70, 0, 80);
	glVertex3f(70, 0, -50);
	glVertex3f(-50, 0, -50);
	//depan
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50, -2, 80);
	glVertex3f(70, -2, 80);
	glVertex3f(70, 0, 80);
	glVertex3f(-50, 0, 80);
	//kanan
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(70, -2, 80);
	glVertex3f(70, 0, 80);
	glVertex3f(70, 0, -50);
	glVertex3f(70, -2, -50);
	//kiri
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50, -2, 80);
	glVertex3f(-50, 0, 80);
	glVertex3f(-50, 0, -50);
	glVertex3f(-50, -2, -50);
	//belakang
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50, -2, -50);
	glVertex3f(70, -2, -50);
	glVertex3f(70, 0, -50);
	glVertex3f(-50, 0, -50);
	//bawah
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-50, -2, 80);
	glVertex3f(70, -2, 80);
	glVertex3f(70, -2, -50);
	glVertex3f(-50, -2, -50);
	glEnd();
}
void tengah(){
	persegi_panjang1(-45.5, 10, 46.5, 29.9, 45.5, -45.5, 0.45);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-45.5, 12.5, 45.5);
	glVertex3f(-45.5, 12.5, -45.5);
	glVertex3f(46.5, 12.5, -45.5);
	glVertex3f(46.5, 12.5, 45.5);
	glEnd();
}
void tangga_kanan(){
	float a = 9, b = 8, c = 7.5, d = 9, e = 65.5, f = 55.5, k = 0.4;
	glPushMatrix();
	glRotatef(-33, 0, 0, 1);
	glTranslatef(-9, 1.2, 0);
	persegi_panjang(15.5, 16, a-2, 16.2, e, e - 0.2, 0.4);
	persegi_panjang(15.5, 16, a-2, 16.2, f, f + 0.2, 0.4);
	glPopMatrix();
	for (int i = 0; i < 5; i++){
		persegi_panjang(a, b, c, d, e, f, k);
		a += 1.5, b -= 1, c += 1.5, d -= 1;
		//samping tangga
		persegi_panjang(a-1.5, d + 1, a - 1.7, 15 - i, e, e - 0.2, 0.4);
		persegi_panjang(a - 2.7, d + 1, a - 3, 15 + 0.5 - i, e, e - 0.2, 0.4);
		persegi_panjang(a-1.5, d + 1, a - 1.7, 15 - i, f + 0.2, f, 0.4);
		persegi_panjang(a - 2.7, d + 1, a - 3, 15 + 0.5 - i, f + 0.2, f, 0.4);
		persegi_panjang(a-1.5, d + 1, a - 2.7, d + 1 + 0.2, e, e - 0.2, 0.4);
		persegi_panjang(a-1.5, d + 1, a - 2.7, d + 1 + 0.2, f + 0.2, f, 0.4);
	}
	a += 6;
	persegi_panjang(a, 0, c, d, e, f, k);
	//tangga tengah
	persegi_panjang(a, 11, c, 11.2, f + 0.2, f, 0.4);
	persegi_panjang(a, d, c, d + 0.2, f + 0.2, f, 0.4);
	for (int i = 0; i < 4; i++){
		persegi_panjang(a - 0.5 - (i*1.5), d, a - 0.7 - (i*1.5), 11, f + 0.2, f, 0.4);
		persegi_panjang(a - 0.5 - 1.3 - (i*1.5), d, a - 0.7 - 1.3 - (i*1.5), 11, f + 0.2, f, 0.4);
	}
	persegi_panjang(a, d, a + 0.2, d + 0.2, e, f, 0.4);
	persegi_panjang(a, 11, a + 0.2, 11 + 0.2, e, f, 0.4);
	for (int i = 0; i < 4; i++){
		persegi_panjang(a, d, a - 0.2, 11, e - 0.5 - (i*2.2), e - 0.7 - (i*2.2), 0.4);
		persegi_panjang(a, d, a - 0.2, 11, e - 0.5 - (i*2.2) - 1.9, e - 0.7 - (i*2.2) - 1.9, 0.4);
	}
	persegi_panjang(a, b, a - 0.5, 30, f + 0.5, f, 0.4);
	persegi_panjang(c + 0.5, b, c, 30, f + 0.5, f, 0.4);
	persegi_panjang(c + 0.5, b, c, 21.5, e, e - 0.5, 0.4);
	persegi_panjang(a, b, a - 0.5, 21.5, e, e - 0.5, 0.4);
	b -= 1, d -= 1, f = e, e = f + 1.5;
	//tangga bawah
	for (int i = 0; i < 3; i++){
		persegi_panjang(a, b, c, d, e, f - (1.5*i), k);
		persegi_panjang(a, d, a + 0.2, b + 8, e, e - 0.2, 0.4);
		persegi_panjang(a, d, a + 0.2, b + 8.7, e - 1.2, e - 0.2 - 1.2, 0.4);
		persegi_panjang(c, d, c - 0.2, b + 8, e, e - 0.2, 0.4);
		persegi_panjang(c, d, c - 0.2, b + 8.7, e - 1.2, e - 0.2 - 1.2, 0.4);
		b -= 1, d -= 1, e += 1.5, f += 1.5;
	}
	persegi_panjang_miring(a, b + 8.8, a + 0.2, b + 9, e - 1.5, e - 6.5, 11, 11.2, 1);
	persegi_panjang_miring(c, b + 8.8, c - 0.2, b + 9, e - 1.5, e - 6.5, 11, 11.2, 1);
	persegi_panjang(a, b, a - 0.5, 18, e - 1, e - 1.5, 0.4);
	persegi_panjang(c + 0.5, b, c, 18, e - 1, e - 1.5, 0.4);
	persegi_panjang_miring(a, 16, c, 16.5, e + 1, 55.5, 29, 29.5, 0);
}
void tangga_kiri(){
	float a = -6.5, b = 8, c = -8, d = 9, e = 65.5, f = 55.5, k = 0.4;
	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	glTranslatef(9, 0.7, 0);
	persegi_panjang(-16, 16, a, 16.2, e, e-0.2, 0.4);
	persegi_panjang(-16, 16, a, 16.2, f, f+0.2, 0.4);
	glPopMatrix();
	for (int i = 0; i < 5; i++){
		persegi_panjang(a, b, c, d, e, f, 0.4);
		a -= 1.5, b -= 1, c -= 1.5, d -= 1;
		//samping tangga
		persegi_panjang(a, d + 1, a + 0.2, 15 - i, e, e - 0.2, 0.4);
		persegi_panjang(a + 1.3, d + 1, a + 1.5, 15 + 0.5 - i, e, e - 0.2, 0.4);
		persegi_panjang(a, d + 1, a + 0.2, 15 - i, f + 0.2, f, 0.4);
		persegi_panjang(a + 1.3, d + 1, a + 1.5, 15 + 0.5 - i, f + 0.2, f, 0.4);
		persegi_panjang(a, d + 1, a + 1.3, d + 1 + 0.2, e, e - 0.2, 0.4);
		persegi_panjang(a, d + 1, a + 1.3, d + 1 + 0.2, f + 0.2, f, 0.4);
	}
	a -= 7, c += 1.5;
	persegi_panjang(a, 0, c, d, e, f, k);
	//tengah tangga
	persegi_panjang(a, 11, c, 11.2, f + 0.2, f, 0.4);
	persegi_panjang(a, d, c, d + 0.2, f + 0.2, f, 0.4);
	for (int i = 0; i < 4; i++){
		persegi_panjang(a + 0.5 + (i*1.5), d, a + 0.7 + (i*1.5), 11, f + 0.2, f, 0.4);
		persegi_panjang(a + 0.5 + 1.3 + (i*1.5), d, a + 0.7 + 1.3 + (i*1.5), 11, f + 0.2, f, 0.4);
	}
	persegi_panjang(a, d, a + 0.2, d + 0.2, e, f, 0.4);
	persegi_panjang(a, 11, a + 0.2, 11 + 0.2, e, f, 0.4);
	for (int i = 0; i < 4; i++){
		persegi_panjang(a, d, a + 0.2, 11, e - 0.5 - (i*2.2), e - 0.7 - (i*2.2), 0.4);
		persegi_panjang(a, d, a + 0.2, 11, e - 0.5 - (i*2.2) - 1.9, e - 0.7 - (i*2.2) - 1.9, 0.4);
	}
	persegi_panjang(a, b, a + 0.5, 30, f + 0.5, f, 0.4);
	persegi_panjang(c - 0.5, b, c, 30, f + 0.5, f, 0.4);
	persegi_panjang(c - 0.5, b, c, 21.5, e, e - 0.5, 0.4);
	persegi_panjang(a, b, a + 0.5, 21.5, e, e - 0.5, 0.4);
	b -= 1, d -= 1, f = e, e = f + 1.5;
	//tangga bawah
	for (int i = 0; i < 3; i++){
		persegi_panjang(a, b, c, d, e, f-(1.5*i), k);
		persegi_panjang(a, d, a + 0.2, b + 8, e, e - 0.2, 0.4);
		persegi_panjang(a, d, a + 0.2, b + 8.7, e-1.2, e - 0.2-1.2, 0.4);
		persegi_panjang(c, d, c - 0.2, b + 8, e, e - 0.2, 0.4);
		persegi_panjang(c, d, c - 0.2, b + 8.7, e - 1.2, e - 0.2 - 1.2, 0.4);
		b -= 1, d -= 1, e += 1.5, f += 1.5;
	}
	persegi_panjang_miring(a, b+8.8, a + 0.2, b + 9, e-1.5 , e-6.5, 11, 11.2, 1);
	persegi_panjang_miring(c, b + 8.8, c - 0.2, b + 9, e - 1.5, e - 6.5, 11, 11.2, 1);
	persegi_panjang(a, b, a + 0.5, 18, e - 1, e - 1.5, 0.4);
	persegi_panjang(c - 0.5, b, c, 18, e - 1, e - 1.5, 0.4);
	persegi_panjang_miring(a, 16, c, 16.5, e + 1, 55.5, 29, 29.5, 0);
	//atap bawah

	
}
void tiang_teras(){
	float a = -20, b = 0, c = -18, d = 2, e = 56, f = 54;
	float g = -19.5, h = 0, m = -18.5, n = 10, k = 55.5, l = 54.5;
	persegi_panjang(a, 10, c + (13 * 3), 30, k, l - 8.9, 0.45);
	for (int i = 0; i < 4; i++){
		persegi_panjang(a, b, c, d, e, f, 0.45);
		persegi_panjang(g, h, m, n, k, l, 0.4);
		persegi_panjang(g, 7, m, n, k, l - 10, 0.4);
		if (i % 2 == 0) persegi_panjang(g, 8, m + 13, n, k, l, 0.4);
		if (i == 1 || i == 2){
			persegi_panjang(a, b, c, d, e + 10, f + 10, 0.45);
			persegi_panjang(g, h, m, n, k + 10, l + 10, 0.4);
			persegi_panjang(g, 7, m, n, k + 10, l, 0.4);
			if (i == 1) {
				persegi_panjang(g, 8, m + 13, n, k + 10, l + 10, 0.4);
				glBegin(GL_QUADS);
				glColor3f(0.4, 0.2, 0);
				glVertex3f(g, n, k + 10);
				glVertex3f(m + 13, n, k + 10);
				glVertex3f(m + 13, n, l);
				glVertex3f(g, n, l);
				glEnd();
				persegi_panjang(g, n, g + 0.5, 30, k + 10, k + 9.5, 0.4);
				persegi_panjang(g + 13.5, n, g + 14, 30, k + 10, k + 9.5, 0.4);
				persegi_panjang(g, n, g + 14, 16, k + 10, k + 9.5, 0.4);
			}
		}
		a += 13, c += 13, g += 13, m += 13;
	}
}
void pintu(){
	glColor3f(0.6, 0.3, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(-6, 10, 55.6);
	glVertex3f(7, 10, 55.6);
	glVertex3f(7, 28, 55.6);
	glVertex3f(-6, 28, 55.6);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 10, 55.65);
	glVertex3f(0, 28, 55.65);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-0.2, 18, 55.7);
	glVertex3f(-0.6, 18, 55.7);
	glVertex3f(-0.6, 20, 55.7);
	glVertex3f(-0.2, 20, 55.7);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(1.2, 18, 55.7);
	glVertex3f(1.6, 18, 55.7);
	glVertex3f(1.6, 20, 55.7);
	glVertex3f(1.2, 20, 55.7);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(1, 10, 55.65);
	glVertex3f(1, 28, 55.65);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(0.5, 10, 55.65);
	glVertex3f(0.5, 28, 55.65);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-6, 10, 55.65);
	glVertex3f(7, 10, 55.65);
	glVertex3f(7, 28, 55.65);
	glVertex3f(-6, 28, 55.65);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-6 + 0.5, 10 + 1, 55.65);
	glVertex3f(7 - 0.5, 10 + 1, 55.65);
	glVertex3f(7 - 0.5, 28 - 1, 55.65);
	glVertex3f(-6 + 0.5, 28 - 1, 55.65);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-4.5, 10 + 1, 55.65);
	glVertex3f(-1, 10 + 1, 55.65);
	glVertex3f(-1, 28 - 3, 55.65);
	glVertex3f(-4.5, 28 - 3, 55.65);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(5.5, 10 + 1, 55.65);
	glVertex3f(2, 10 + 1, 55.65);
	glVertex3f(2, 28 - 3, 55.65);
	glVertex3f(5.5, 28 - 3, 55.65);
	glEnd();
}
void garis_kotak(float a, float b, float c, float d, float e){
	glBegin(GL_LINE_LOOP);
	glVertex3f(a, b, e);
	glVertex3f(c, b, e);
	glVertex3f(c, d, e);
	glVertex3f(a, d, e);
	glEnd();
}
void jendela(){
	glColor3f(0.6, 0.3, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(-30, 14, 45.6);
	glVertex3f(-21, 14, 45.6);
	glVertex3f(-21, 26, 45.6);
	glVertex3f(-30, 26, 45.6);
	glEnd();
	glColor3f(0, 0, 0);
	garis_kotak(-30, 14, -21, 26, 45.65);
	garis_kotak(-29.5, 14, -21.5, 26, 45.65);
	garis_kotak(-30, 14.5, -21, 25.5, 45.65);
	garis_kotak(-25.5, 14, -25.6, 26, 45.65);
	garis_kotak(-29, 15, -28, 25, 45.65);
	garis_kotak(-27.5, 15, -26, 17, 45.65);
	garis_kotak(-27.5, 23, -26, 25, 45.65);
	garis_kotak(-27.5, 17.5, -26, 22.5, 45.65);
	garis_kotak(-25, 15, -23.5, 17, 45.65);
	garis_kotak(-25, 23, -23.5, 25, 45.65);
	garis_kotak(-25, 17.5, -23.5, 22.5, 45.65);
	garis_kotak(-23, 15, -22, 25, 45.65);
}
void jendela_depan(){
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	jendela();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-13,0,0);
	jendela();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(53, 0, 0);
	jendela();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(65, 0, 0);
	jendela();
	glPopMatrix();
}
void jendela_kiri(){
	for (int i = 0; i < 5; i++){
		glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		glTranslatef(62-(i*18), 0, 0);
		jendela();
		glPopMatrix();
	}
}
void jendela_kanan(){
	for (int i = 0; i < 5; i++){
		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-10+(i * 18), 0, 1);
		jendela();
		glPopMatrix();
	}
}
void kamar1(){
	persegi_panjang(13, 11, 14, 29.9, -18, -45.4, 0.4);
	persegi_panjang(13, 11, 46.4, 29.9, -5.5, -6.5, 0.4);
	//kasur
	persegi_panjang(20, 11, 45, 14, -30, -45, 0.8);
	persegi_panjang(45.1, 11, 46.3, 17, -30, -45, 0.8);
	//lemari
	persegi_panjang(40, 11, 46.3, 25, -7, -16, 0.6);
	garis_kotak(39.9, 11, 39.9, 25, -12);
	// meja kamar
	persegi_panjang(40, 11, 46.3, 16, -19, -28, 0.6);
	persegi_panjang(45, 16.1, 46, 18, -19, -28, 0.6);
}
void kamar2(){
	persegi_panjang(-12, 11, -13, 29.9, -18, -45.4, 0.4);
	persegi_panjang(-12, 11, -45.4, 29.9, -5.5, -6.5, 0.4);
	//kasur
	persegi_panjang(-19, 11, -44, 14, -30, -45, 0.8);
	persegi_panjang(-44.1, 11, -45.3, 17, -30, -45, 0.8);
	//lemari
	persegi_panjang(-39, 11, -45.3, 25, -7, -16, 0.6);
	garis_kotak(-38.9, 11, -38.9, 25, -12);
	//// meja kamar
	persegi_panjang(-39, 11, -45.3, 16, -19, -28, 0.6);
	persegi_panjang(-44, 16.1, -45, 18, -19, -28, 0.6);
}
void ruang_tamu(){
	//-------------------kanan--------------------
	persegi_panjang(13, 11, 46.4, 17, 0, -5.4, 0.4);
	//tv
	persegi_panjang(24, 18, 36, 26, -1.7, -2.4, 1);
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(24.5, 18.5, -1.6);
	glVertex3f(35.5, 18.5, -1.6);
	glVertex3f(35.5, 25.5, -1.6);
	glVertex3f(24.5, 25.5, -1.6);
	glEnd();
	//karpet
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(14, 11.1, 40);
	glVertex3f(45.5, 11.1, 40);
	glVertex3f(45.5, 11.1, 5);
	glVertex3f(14, 11.1, 5);
	glEnd();
	//---------------------kiri-----------------
	persegi_panjang(-12, 11, -45.4, 25, 0, -5.4, 0.4);
	//karpet
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-13, 11.1, 40);
	glVertex3f(-44.5, 11.1, 40);
	glVertex3f(-44.5, 11.1, 5);
	glVertex3f(-13, 11.1, 5);
	glEnd();
	persegi_panjang(-20, 11.2, -35.5, 15, 17, 27, 0.4);
}
void furniture(){
	kamar1();
	kamar2();
	ruang_tamu();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glLineWidth(2);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glTranslatef(xkey, ykey, zkey);
	glPushMatrix();
	alas();
	tiang_bawah();
	tiang_teras();
	tangga_kanan();
	tangga_kiri();
	tengah();
	pintu();
	jendela_depan();
	jendela_kiri();
	jendela_kanan();
	furniture();
	papan();
	tekstur();
	if (dalam==false){
		ataptumpuk();
		ornamen();
	}
	glPopMatrix();
	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, lebar, tinggi);
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
	switch (key){
	case 'a': xkey -= 1; break;
	case 'd': xkey += 1; break;
	case 's': ykey -= 1; break;
	case 'w': ykey += 1; break;
	case 'j': zkey -= 1; break;
	case 'k': zkey += 1; break;
	case 'n': dalam = true; break;
	case 'm': dalam = false; break;
	default: return;
	}
	display();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(210, 30);
	glutCreateWindow("TR Grafkom Rumah Adat Lampung");
	glutDisplayFunc(display);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	Inisialisasi();
	initRendering();
	glutMainLoop();
	return 0;
}

