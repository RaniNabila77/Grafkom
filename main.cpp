#include <stdio.h> // Header untuk fungsi input/output standar
#include <stdlib.h> // Header untuk fungsi utilitas umum seperti malloc dan free
#include <string.h> // Header untuk fungsi manipulasi string
#include <math.h> // Header untuk fungsi matematika standar
#include <GL/glut.h> // Header untuk GLUT di sistem 
#include <GL/glu.h> // Header untuk GLU (OpenGL Utility Library)
#include <GL/gl.h> // Header untuk OpenGL
#include <GL/freeglut.h>

using namespace std; 

//Variabel global untuk mengatur Rotasi dan Posisi Kamera
static GLfloat spin = 0.0; 
float angle = 0; 
float lastx, lasty; 
GLint stencilBits; 
static int camx = 100; 
static int camy = 50; 
static int camz = 50; 
float rot = 0; 

//Mengatur Komponen Cahaya dan Material
const GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_ambient2[] = { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat light_diffuse2[] = { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat high_shininess[] = { 100.0f };



void init(void) {
 	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LESS);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//Fungsi set up perspektif matriks proyeksi.
	glEnable(GL_CULL_FACE);

}

void bangunan(void) {

	//lantai 1
	glPushMatrix();
	glScaled(1.115, 0.03, 2);
	glTranslatef(0.0, 0, 0.38);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 255);
	glutSolidCube(5.0);
	glPopMatrix();

	// lantai 2
	glPushMatrix();
	glScaled(1.015, 0.03, 1.64);
	glTranslatef(0.0, 80, 0.57);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 255);
	glutSolidCube(5.0);
	glPopMatrix();
	glPushMatrix();
	glScaled(0.5, 0.03, 0.15);
	glTranslatef(2.56, 80, -23.6);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 255);
	glutSolidCube(5.0);
	glPopMatrix();

	//lantai 3
	glPushMatrix();
	glScaled(0.95, 0.03, 1.8);
	glTranslatef(0.0,160, 0.3);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(138, 138, 138);
	glutSolidCube(5.0);
	glPopMatrix();

	//lapisan lantai 3
	glPushMatrix();
	glScaled(0.95, 0.02, 1.8);
	glTranslatef(0.0,246, 0.3);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(139,0,0);
	glutSolidCube(5.0);
	glPopMatrix();

	//Dinding Kiri Bawah
	glPushMatrix();
	glScaled(0.035, 0.5, 1.6);
	glTranslatef(-70.0, 2.45, 0.0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(139,0,0);
	glutSolidCube(5.0);
	glPopMatrix();

//	//Dinding Kanan Bawah
//	glPushMatrix();
//	glScaled(0.035, 0.5, 1.6);
//	glTranslatef(70.0, 2.45, 0.0);
//	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//	glColor3f(0.4613, 0.4627, 0.4174);
//	glutSolidCube(5.0);
//	glPopMatrix();
//
//	//Dinding Kanan Atas
//	glPushMatrix();
//	glScaled(0.035, 0.5, 1.8);
//	glTranslatef(70.0, 7.45, 0.3);
//	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//	glColor3ub(000, 191, 255);
//	glutSolidCube(5.0);
//	glPopMatrix();

	//Dinding Kiri Atas
	glPushMatrix();
	glScaled(0.035, 0.5, 1.8);
	glTranslatef(-70.0, 7.45, 0.3);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(139,0,0);
	glutSolidCube(5.0);
	glPopMatrix();

	//Dinding Belakang bawah
	glPushMatrix();
	glScaled(1.015, 0.5, 0.07);
	glTranslatef(0, 2.45,-58);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(139,0,0);
	glutSolidCube(5.0);
	glPopMatrix();

	//Dinding Belakang atas
	glPushMatrix();
	glScaled(1.015, 0.5, 0.07);
	glTranslatef(0, 7.45,-58);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(139,0,0);
	glutSolidCube(5.0);
	glPopMatrix();

	//Dinding Depan bawah
	glPushMatrix();
	glScaled(1.015, 0.5, 0.035);
	glTranslatef(0, 2.25,116);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(139,0,0);
	glutSolidCube(5.0);
	glPopMatrix();

	//Dinding Depan atas
	glPushMatrix();
	glScaled(1.015, 0.5, 0.035);
	glTranslatef(0, 7.45, 142);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(139,0,0);
	glutSolidCube(5.0);
	glPopMatrix();

	// HIASAN DINDING
	//background
	glPushMatrix();
	glScaled(0.35, 0.5, 0.035);
	glTranslatef(1, 7.2,-112);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(138, 138, 138);
	glutSolidCube(5.0);
	glPopMatrix();
	//strip 1
	glPushMatrix();
	glScaled(0.017,0.33, 0.035);
	glTranslatef(-16.6, 12,-110);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub (255, 255 ,255);
	glutSolidCube(5.0);
	glPopMatrix();
	//strip 2
	glPushMatrix();
	glScaled(0.017,0.33, 0.035);
	glTranslatef(-6.6, 12,-110);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub (255, 255 ,255);
	glutSolidCube(5.0);
	glPopMatrix();
	//strip 3
	glPushMatrix();
	glScaled(0.017,0.33, 0.035);
	glTranslatef(3.6, 12,-110);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub (255, 255 ,255);
	glutSolidCube(5.0);
	glPopMatrix();

	// JENDELA ATAS KANAN
	// bingkai atas
	glPushMatrix();
	glScaled(0.08, 0.017, 0.035);
	glTranslatef(22.5, 265,-112);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 240);
	glutSolidCube(5.0);
	glPopMatrix();
	// bingkai bawah
	glPushMatrix();
	glScaled(0.08, 0.017, 0.035);
	glTranslatef(22.5, 183,-112);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 240);
	glutSolidCube(5.0);
	glPopMatrix();
	// bingkai kiri
	glPushMatrix();
	glScaled(0.017,0.28, 0.035);
	glTranslatef(96.6, 13.5,-112);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 240);
	glutSolidCube(5.0);
	glPopMatrix();
	// bingkai kanan
	glPushMatrix();
	glScaled(0.017,0.28, 0.035);
	glTranslatef(115.1, 13.5,-112);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 240);
	glutSolidCube(5.0);
	glPopMatrix();
		
  	//LAMPU ATAS KANAN
	glPushMatrix();
	glScaled(0.05, 0.05, 0.05);
	glTranslatef(34.5, 95.4, 10);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
	glColor3ub(255, 255, 000);
	glutSolidSphere(2.0,20,50);
	glPopMatrix();
	

	//LAMPU ATAS KIRI    
	glPushMatrix();
	glScaled(0.05, 0.05, 0.05);
	glTranslatef(-32.5, 95.4, 10);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 000);
	glutSolidSphere(2.0,20,50);
	glPopMatrix();

	//LAMPU BAWAH KANAN
	glPushMatrix();
	glScaled(0.05, 0.05, 0.05);
	glTranslatef(34.5, 47, 10);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
	glColor3ub(255, 255, 000);
	glutSolidSphere(2.0,20,50);
	glPopMatrix();
	
	//LAMPU BAWAH KIRI
	glPushMatrix();
	glScaled(0.05, 0.05, 0.05);
	glTranslatef(-32.5, 47, 10);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(255, 255, 000);
	glutSolidSphere(2.0,20,50);
	glPopMatrix();
	void mejakasur(void);
	
}

void tempatTidur(){
     glPushMatrix();
       glTranslatef(-15.0,-8.5,-12.0);
       glScalef(6.0,1.0,9.0);
       glColor3f(0.0980, 0.0608, 0.0077);
       glutSolidCube(1.5);
    glPopMatrix();
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glPushMatrix();
       glTranslatef(-15.0,-8.5,-12.0);
       glColor3ub (255, 250, 250);
       glScalef(6.0,2.0,10.0);
       glutSolidCube(1.3);
    glPopMatrix();
    // bantal kiri
    glPushMatrix();
    	glRotated(-90, 0.0, 1.0, 0.0);
    	glScaled(0.4, 0.1, 0.6);
    	glTranslatef(-43, -70, 28);
    	glColor3ub (255, 250, 250);
    	glutSolidCube(5.0);
    glPopMatrix();
    // bantal kanan
    glPushMatrix();
    	glRotated(-90, 0.0, 1.0, 0.0);
    	glScaled(0.4, 0.1, 0.6);
    	glTranslatef(-43, -70, 22);
    	glColor3ub (255, 250, 250);
    	glutSolidCube(5.0);
    glPopMatrix();//
}

void mejakasur(void){

// MEJA Kanan
	// tatakan meja
	glPushMatrix();
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.98, 0.48, 0.08);
	glTranslatef(-1.5, 9.0, -36);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(0.0980, 0.0608, 0.0077);
	glutSolidCube(1.0);
	glPopMatrix();	
	// kaki meja kiri belakang
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-30, 5.2, 75.5);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();
	// kaki meja kiri depan
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-20, 5.2, 75.5);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();
	// kaki meja kanan depan
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-20, 5.2, 68.5);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();
	// kaki meja kanan belakang
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-30, 5.2, 68.5);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();
	
	// MEJA KIRI
	// tatakan meja
	glPushMatrix();
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.98, 0.48, 0.08);
	glTranslatef(-1.50, 2.5, -36);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3f(0.0980, 0.0608, 0.0077);
	glutSolidCube(1.0);
	glPopMatrix();
	// kaki meja kiri belakang
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-30, 5.2, 23);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();
	// kaki meja kiri depan
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-20, 5.2, 23);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();
	// kaki meja kanan depan
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-20, 5.2, 16.8);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();
	// kaki meja kanan belakang
	glPushMatrix();
	glScaled(0.06, 0.5,0.06);
	glTranslatef(-30, 5.2, 16.8);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidCube(1.0);
	glPopMatrix();

}
void mejasofa(void){
    glPushMatrix();
       glTranslatef(0.0,-5.0,0.0);
       glColor3f(0.0980, 0.0608, 0.0077);
       glScalef(6.0,0.1,8.0);
       glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
       glTranslatef(-2.5,-7.0,3.5);
       glScalef(1.0,4.0,1.0);
       glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
       glTranslatef(2.5,-7.0,3.5);
       glScalef(1.0,4.0,1.0);
       glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
       glTranslatef(-2.5,-7.0,-3.5);
       glScalef(1.0,4.0,1.0);
       glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
       glTranslatef(2.5,-7.0,-3.5);
       glScalef(1.0,4.0,1.0);
       glutSolidCube(1.0);
    glPopMatrix();
}



void sofaPanjang(){
	// bawah sofa
	glRotated(-90, 0.0, 1.0, 0.0);
	glPushMatrix();
		glScaled(1.5, 0.5, 5);
		glTranslatef(1, -17, 0);
		glColor3f(0.0980, 0.0608, 0.0077);
	    glutSolidCube(5.0);
    glPopMatrix();
    // senderan sofa
	glRotated(-90, 0.0, 1.0, 0.0);
	glPushMatrix();
		glScaled(5, 1.5, 0.5);
		glTranslatef(0, -4, -11);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(5.0);
    glPopMatrix();
    // sisi kanan sofa
	glRotated(-90, 0.0, 1.0, 0.0);
	glPushMatrix();
		glScaled(2, 1, 0.5);
		glTranslatef(-0.8, -7, 25);
		glColor3f(0.0980, 0.0608, 0.0077);
	    glutSolidCube(5.0);
    glPopMatrix();
    //sisi kiri sofa
    glPushMatrix();
		glScaled(2, 1, 0.5);
		glTranslatef(-0.8, -7, -25);
		glColor3f(0.0980, 0.0608, 0.0077);
	    glutSolidCube(5.0);
    glPopMatrix();
     // bantal sofa
	glPushMatrix();
		glScaled(1, 0.1, 4);
		glTranslatef(-1, -70, 0);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(5.0);
    glPopMatrix();
    
}

void pintuUtama(){
    // Menggambar daun pintu utama
    glPushMatrix();
        glScaled(3, 5, 0.8); 
        glTranslatef(3, 2.5, 76); 
        glColor3ub(255, 250, 250);
        glutSolidCube(5.0); 
        glPushMatrix();
            glTranslatef(-5.055, 0, 0); 
            glColor3ub(255, 250, 250); 
            glutSolidCube(5.0); // Menggambar kubus tambahan
        glPopMatrix();
    glPopMatrix();

    // Menggambar bingkai pintu bagian kiri
    glPushMatrix();
        glScaled(0.2, 0.7, 1); 
        glTranslatef(0, 20, 60.88); 
        glColor3ub(0, 0, 0); 
        glutSolidCube(5.0); 
    glPopMatrix();

    // Menggambar bingkai pintu bagian kanan
    glPushMatrix();
        glScaled(0.2, 0.7, 1); 
        glTranslatef(15, 20, 60.88); 
        glColor3ub(0, 0, 0); 
        glutSolidCube(5.0);
    glPopMatrix();
}

void tangga(){
    glRotated(-90, 0.0, 1.0, 0.0); 
    glPushMatrix();
        glScaled(0.7, 0.5, 2.5);
        glTranslatef(-30, 5, 12);
        glColor3ub(138, 138, 138); 
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glScaled(0.7, 1.0, 2.5);
        glTranslatef(-35, 3.8, 12);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glScaled(0.7, 1.5, 2.5);
        glTranslatef(-40, 3.5, 12);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glScaled(0.7, 2, 2.5);
        glTranslatef(-45, 3.2, 12);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glScaled(0.7, 2.5, 2.5);
        glTranslatef(-50, 3, 12);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glScaled(0.7, 3, 2.5);
        glTranslatef(-55, 2.8, 12);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glScaled(2, 3.5, 2.5);
        glTranslatef(-22.5, 2.7, 12);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 4, 2.5);
        glTranslatef(31, 2.6, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 4.5, 2.5);
        glTranslatef(27, 2.4, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 5, 2.5);
        glTranslatef(23, 2.4, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 5.5, 2.5);
        glTranslatef(19, 2.4, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 6, 2.5);
        glTranslatef(15, 2.4, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 6.5, 2.5);
        glTranslatef(11, 2.4, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 7, 2.5);
        glTranslatef(7, 2.4, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
    glPushMatrix();
        glRotated(-90, 0.0, 1.0, 0.0);
        glScaled(0.7, 7.5, 2.5);
        glTranslatef(3, 2.4, 19.5);
        glutSolidCube(5.0);
    glPopMatrix();
}

void lampuMeja() {
    // Menggambar kap lampu
    glPushMatrix();
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); 
        glColor3ub(255, 255, 0);
        glRotated(-90.0, 1.0, 0.0, 0.0); 
        glutSolidCone(15.0, 20.0, 15, 15); 
    glPopMatrix();

    // Menggambar bagian tengah lampu
    glPushMatrix();
        glRotatef(90, 1, 0, 0); 
        glTranslatef(0.0, 0, -2); 
        glScalef(1.4, 2, 30);
        glColor3ub(255, 250, 250); 
        glutSolidTorus(0.4, 0.4, 60, 80); 
    glPopMatrix();

    // Menggambar dasar lampu
    glPushMatrix();
        glColor3ub(255, 250, 250); 
        glTranslatef(0, -9.1, -0.05); 
        glScalef(2, 0.1, 2); 
        glutSolidSphere(6, 25, 25); 
    glPopMatrix();
}


void lemari(void){
     //isi atau inti lemari
    glColor3d(0.88,0.72,0.53);
    glPushMatrix();
        glTranslated(-31.0,43.0,8.0);
        glScaled(1.5,2.5,6.0);
        glutSolidCube(10);
    glPopMatrix();

    //pintu atau kerangka lemari
    glColor3d(0.75,0.59,0.4);
    glPushMatrix();
        glTranslated(-30.0,43.0,20.0);
        glScaled(1.5,2.0,2.0);
        glutSolidCube(10);
    glPopMatrix();
	
	glColor3d(0.75,0.59,0.4);
    glPushMatrix();
        glTranslated(-30.0,43.0,-5.0);
        glScaled(1.5,2.0,2.0);
        glutSolidCube(10);
    glPopMatrix();
    
}
	
void mejaMakan(void){
		// lingkaran meja
		glPushMatrix();
		glColor3ub(139,69,19);
		glTranslatef(0, 1.5, -1);
		glScaled(1, 0.1, 1);
		glutSolidSphere(6, 25, 25);
		glPopMatrix();
		// kaki meja kiri depan
		glPushMatrix();
		glScaled(0.1, 0.6, 0.1);
		glTranslatef(33, 0, 30);
		glColor3ub(139,69,19);
		glutSolidCube(5.0);
		glPopMatrix();
		// kaki meja kiri belakang
		glPushMatrix();
		glScaled(0.1, 0.6, 0.1);
		glTranslatef(-33, 0, 30);
		glColor3ub(139,69,19);
		glutSolidCube(5.0);
		glPopMatrix();
		// kaki meja kanan depan
		glPushMatrix();
		glScaled(0.1, 0.6, 0.1);
		glTranslatef(33, 0, -50);
		glColor3ub(139,69,19);
		glutSolidCube(5.0);
		glPopMatrix();
		// kaki meja kanan belakang
		glPushMatrix();
		glScaled(0.1, 0.6, 0.1);
		glTranslatef(-33, 0, -50);
		glColor3ub(139,69,19);
		glutSolidCube(5.0);
		glPopMatrix();
}

void kursiMakan(void)
{
    // Menggambar kaki kursi
    glPushMatrix(); 
        glColor3ub(139,69,19); 
        glTranslatef(-5, -9.1, -0.05); 
        glScaled(0.2, 0.05, 0.2); 
        glutSolidSphere(6, 25, 25); 
    glPopMatrix(); 

    // Menggambar tempat duduk kursi
    glPushMatrix(); 
        glTranslatef(-5.0, -7.0, 0); 
        glScalef(3.0, 0.1, 3.0); 
        glutSolidCube(1.0); 
    glPopMatrix(); 

    // Menggambar sandaran kursi
    glPushMatrix(); 
        glTranslatef(-6.5, -5.5, 0); 
        glRotatef(90, 0.0, 0.0, 1.0); 
        glScalef(3.0, 0.1, 3.0); 
        glutSolidCube(1.0);
    glPopMatrix();

    // Menggambar penopang kursi
    glPushMatrix(); 
        glTranslatef(-5.0, -8.0, 0); 
        glScalef(0.5, 2.0, 0.5); 
        glutSolidCube(1.0); 
    glPopMatrix();
}

void display(void) {
	glClearStencil(0); //clear the stencil buffer
	glClearDepth(1.0f);//Fungsi menentukan nilai yang jelas untuk kedalaman
	glClearColor(0.0, 0.6, 0.8, 1);//mendefinisikan warna dari windows
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); //untuk membersihkan memori buffer warna atau memori buffer kedalaman dari keadaan sebelumnya.
	glLoadIdentity();//untuk memanggil matriks terakhir yang disimpan.
	gluLookAt(camx, camy, camz, 0.0, 0.0, 5.0, 0.0, 1.0, 0.0);//Fungsi mendefinisikan transformasi pandangan.

		glPushMatrix();
			glTranslatef(0,0,0);
			glScalef(15, 15, 15);
			bangunan(); //Bangunan
			mejakasur();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,0,0);
			pintuUtama();//2 Pintu utama
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,0,-5);
			tangga();// Tangga lantai 1 dan 2
		glPopMatrix();

		glPushMatrix();
			glScalef(2.5, 2.5, 2.5);
			glTranslatef(3, 2, -10);
			mejaMakan();// Meja makan
		glPopMatrix();

		glPushMatrix();
			glScalef(2.5, 2.5, 2.5);
		    glRotatef(90, 0, 1, 0);
		    glTranslatef(10, 9.5, 3);
		    kursiMakan();// Kursi meja makan

			glPushMatrix();
			glRotatef(-180, 0, 1, 0);
			glTranslatef(-2, 0, 0);
			kursiMakan();
			glPopMatrix();

			glPushMatrix();
			glRotatef(-90, 0, 1, 0);
			glTranslatef(-2, 0, -1);
			kursiMakan();
			glPopMatrix();

			glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glTranslatef(-1, 0, 0.6);
			kursiMakan();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
			glScalef(2.5, 2.5, 2.5);
			glRotatef(90, 0, 1, 0);
			glTranslatef(-1.6, 24.7, 5);
			tempatTidur();// Tempat tidur
		glPopMatrix();

		glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glTranslatef(-22.5, 15, 5);
			glScalef(1.5, 1.5, 1.5);
			mejasofa();// Meja ruang tamu
		glPopMatrix();

		glPushMatrix();
			glTranslatef(5, 13, 35);
			glScalef(1.3, 1.2, 1);
			sofaPanjang();// Sofa panjang ruang tamu
			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, 25);
				sofaPanjang();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90, 0, 1, 0);
			glTranslatef(22.5, 13, 15);
			glScalef(0.5, 1.2, 1);
			sofaPanjang();//Sofa panjang ruang tamu

			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, 40);
				sofaPanjang();
			glPopMatrix();

			//lemari 
			glPushMatrix();
				glRotatef(-90, 0, 1, 0);
				glTranslatef(-70, 30, 12);
			glPopMatrix();
		glPopMatrix();
		
		glPushMatrix();
        	glRotated(-90, 0.0, 1.0, 0.0);
			glScaled(0.5, 1.2, 1);
        	lemari();
        glPopMatrix();

		glPushMatrix();
			//lampu kiri
			glScalef(0.3, 0.3, 0.3);
			glTranslatef(-75, 155, 216);
			lampuMeja(); //Lampu ruang tidur
			// lampu kanan
			glPushMatrix();
			glTranslatef(0, 0, -156);
			lampuMeja();// Lampu ruang tidur
			glPopMatrix();
		glPopMatrix();
	    
	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
	rot++;
	angle++;

}


void keyboard(unsigned char key, int x, int y) {
    if (key == 'd') {
        spin -= 1.0f;
        if (spin < 0.0f) {
            spin += 360.0f;
        }
    }
    if (key == 'a') {
        spin += 1.0f;
        if (spin > 360.0f) {
            spin -= 360.0f;
        }
    }
    if (key == 'a') { // kiri
        camz++;
    }
    if (key == 'd') { // kanan
        camz--;
    }
    
    if (key == 'w') { // maju
        camx--;
    }
    if (key == 's') { // mundur
        camx++;
    }
}


void mouseWheel(int button, int dir, int x, int y) {
    if (dir > 0) { // Scroll ke atas
        camy++;
    } else { // Scroll ke bawah
        camy--;
    }
    glutPostRedisplay(); // Meminta redisplay untuk memperbarui tampilan
}



void reshape(int w, int h) {//Fungsi set up perspektif matriks proyeksi.
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat) w / (GLfloat) h, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL | GLUT_DEPTH); //add a stencil buffer to the window
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rumah Sederhana");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);	
	glutKeyboardFunc(keyboard);
	glutMouseWheelFunc(mouseWheel);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);//mengatur cahaya kilau pada objek
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);// mengkonfigurasi sumber cahaya
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);///mengatur cahaya kilau pada objek
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);// mengatur definisi kesilauan
	glColorMaterial(GL_FRONT, GL_DIFFUSE);

	glutMainLoop();
	return 0;
}
