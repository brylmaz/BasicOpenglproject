#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>





using namespace std;


int secim, kenarsayisi;
float x, y, xd[30], yd[30], xoteleme, yoteleme, xolcekleme, yolcekleme, zolcekleme, dondurmeacisi, yansimadegeri, egimmik, egimyon;



void oteleme() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i], yd[i]);

	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i] + xoteleme, yd[i] + yoteleme);

	}
	glEnd();
	glFlush();
}

void olcekleme() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i], yd[i]);

	}
	glEnd();

	glColor3f(0, 1, 0);
	glScalef(xolcekleme, yolcekleme, zolcekleme);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i], yd[i]);

	}
	glEnd();
	glFlush();
}

void dondurme() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i], yd[i]);

	}
	glEnd();

	glColor3f(0, 1, 0);
	glRotatef(dondurmeacisi, 0, 0, 1);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i], yd[i]);

	}
	glEnd();
	glFlush();
}

void yansima() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i], yd[i]);

	}
	glEnd();


	glColor3f(0, 1, 0);
	glRotatef(dondurmeacisi, 0, 0, 1);
	glBegin(GL_POLYGON);
	if (yansimadegeri == 1) {
		for (int i = 0; i < kenarsayisi; i++) {


			glVertex2f(-xd[i], yd[i]);

		}
	}

	else if (yansimadegeri == 2) {
		for (int i = 0; i < kenarsayisi; i++) {


			glVertex2f(xd[i], -yd[i]);

		}
	}

	if (yansimadegeri == 3) {
		for (int i = 0; i < kenarsayisi; i++) {


			glVertex2f(-xd[i], -yd[i]);

		}
	}
	glEnd();
	glFlush();
}

void egme() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);

	for (int i = 0; i < kenarsayisi; i++) {


		glVertex2f(xd[i], yd[i]);

	}
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);

	if (egimyon == 1)
	{
		glVertex2f(xd[0], yd[0]);

		glVertex2f(xd[1] + egimmik, yd[1]);
		glVertex2f(xd[2] + egimmik, yd[2]);

		glVertex2f(xd[3], yd[3]);
	}
	else if (egimyon ==2)
	{
		glVertex2f(xd[0], yd[0]);
		glVertex2f(xd[1], yd[1]);

		glVertex2f(xd[2], yd[2] + egimmik);
		glVertex2f(xd[3], yd[3] + egimmik);
	}
	glEnd();

	glFlush();

}


void main(int argc, char** argv) {



	printf("\n\n");
	printf("******************************************************************************\n");
	printf("Bu uygulama ile,istediginiz bir poligona sectiginiz islemi uygulayabilirsiniz.\n");
	printf("******************************************************************************\n\n\n");

	printf("1. Translation (Oteleme)\n");
	printf("2. Scaling (Olcekleme)\n");
	printf("3. Rotation (Dondurme)\n");
	printf("4. Mirror Reflection (Yansima)\n");
	printf("5. Shearing (Egme)\n");
	printf("6. Exit - CIKIS\n\n\n");

	

	secim = 0;
	printf("Seciminizi Giriniz:");
	scanf_s("%d", &secim);
	printf("\n\n");

	if (secim == 6) {

		exit(0);

	}
	
	
	
	kenarsayisi = 0;
	printf("Poligonun Kenar Sayisini Giriniz:");
	scanf_s("%d", &kenarsayisi);
	printf("\n\n");



	printf("Lutfen degerleri (0.0-1.0) araliginda olacak sekilde giriniz. yeni resim yesil ile gosterilecek.\n\n");


	for (int i = 0; i < kenarsayisi; i++) {

		++i;
		printf("%d. noktanin koordinatlari (x y) \n", i);
		--i;

		printf("x degeri : ");

		scanf_s("%f", &x);

		printf("y degeri : ");

		scanf_s("%f", &y);

		xd[i] = x;
		yd[i] = y;




	}



	if (secim == 1) {



		printf("\nx degeri icin ne kadar otelensin ==");
		scanf_s("%f", &xoteleme);


		printf("y degeri icin ne kadar otelensin ==");
		scanf_s("%f", &yoteleme);

		glutInit(&argc, argv);
		glutCreateWindow("OTELEME!");
		glutDisplayFunc(oteleme);
		glutMainLoop();


	}

	else if (secim == 2) {

		printf("\nx degeri icin ne kadar olceklensin == ");
		scanf_s("%f", &xolcekleme);

		printf("\ny degeri icin ne kadar olceklensin == ");
		scanf_s("%f", &yolcekleme);

		printf("\nz degeri icin ne kadar olceklensin == ");
		scanf_s("%f", &zolcekleme);

		

		glutInit(&argc, argv);
		glutCreateWindow("OLCEKLEME!");
		glutDisplayFunc(olcekleme);
		glutMainLoop();

	}

	else if (secim == 3) {

		printf("\nkac derece dondurulsun? == ");
		scanf_s("%f", &dondurmeacisi);




		glutInit(&argc, argv);
		glutCreateWindow("DONDURME!");
		glutDisplayFunc(dondurme);
		glutMainLoop();

	}

	else if (secim == 4) {

		printf("\nHangi Eksende Yansima Yapilsin.\n X icin '1'\n Y icin '2' \n hem X hem Y icin '3'\n Deger: ");
		scanf_s("%f", &yansimadegeri);




		glutInit(&argc, argv);
		glutCreateWindow("YANSÝMA!");
		glutDisplayFunc(yansima);
		glutMainLoop();

	}

	else if (secim == 5) {

		printf("\n egim ne tarafa dogru olsun\n x icin 1 degerini, \n y icin 2 degerini giriniz.\n");
		scanf_s("%f", &egimyon);

		printf("\n egim miktarini yaziniz :  ");
		scanf_s("%f", &egimmik);




		glutInit(&argc, argv);
		glutCreateWindow("EGME!");
		glutDisplayFunc(egme);
		glutMainLoop();

	}



	else {
		printf("Yanlýþ Deðer Girdiniz.");
	}









}



