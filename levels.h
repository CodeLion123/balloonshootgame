#include<iostream>
#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
float PI=3.14;
void bitmap_output2(int x,int y,char *string,void *font)
{
    int len,i;
    glRasterPos2f(x,y);
    len=(int)strlen(string);
    for(i=0;i<len;i++)
    {
        glutBitmapCharacter(font,string[i]);
    }
    return;
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    //glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cos(theta);//calculate the x component
		float y = r * sin(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}


	void drawDart (float x_center, float y_center, float w, float h, int n)
	{
	    float theta, angle_increment;
	    float x, y;

	    if (n <= 0)
	        n = 1;

	    angle_increment = PI/ 500;
	    glPushMatrix ();

	    //  center the oval at x_center, y_center
	    glTranslatef (x_center, y_center, 0);

	    //  draw the oval using line segments
	    glBegin (GL_POLYGON);

	    for (theta = 0.0f; theta < 2*PI; theta += angle_increment)
	    {
	        x = w/2 * cos (theta);
	        y = h/2 * sin (theta);

	        //  Color the vertices!
	       // if (color[currentShape])
	          //  glColor3f (x, y, x*y);

	        glVertex2f (x, y);
	    }

	    glEnd ();
	    glPopMatrix ();
	}



void draw_target2(int count1,int count2,int count3,int count4,int count5,int count6,int count7,int count8,int count9,int y11,int y2,int y3,int y4,int y5,int y6,int y7,int y8,int y9)
{
    if(count1==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y11-2,"15",GLUT_BITMAP_HELVETICA_10);
    	glColor3f(0,0,1);


        DrawCircle(375,y11,8,100);
    }
    else
    {

    }
    if(count2==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y2-2,"20",GLUT_BITMAP_HELVETICA_10);
    	glColor3f(0,1,0);

         DrawCircle(375,y2,8,100);

    }
    else
    {

    }
    if(count3==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y3-2,"15",GLUT_BITMAP_HELVETICA_10);
        glColor3f(0,0,1);

        DrawCircle(375,y3,8,100);

    }
    else
    {

    }
    if(count4==0)
    {

    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y4-2,"10",GLUT_BITMAP_HELVETICA_10);

        glColor3f(1,0,0);

        DrawCircle(375,y4,8,100);

    }
    else
    {

    }
    if(count5==0)
    {

    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(370,y5-2,"10",GLUT_BITMAP_HELVETICA_10);
        glColor3f(1,0,0);
        DrawCircle(375,y5,8,100);
    }
    else
    {

    }
    if(count6==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y6-2,"20",GLUT_BITMAP_HELVETICA_10);

        glColor3f(0,1,0);
        DrawCircle(375,y6,8,100);
    }
    else
    {

    }
    if(count7==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y7-2,"10",GLUT_BITMAP_HELVETICA_10);
        glColor3f(1,0,0);
        DrawCircle(375,y7,8,100);
    }
    else
    {

    }
    if(count8==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y8-2,"15",GLUT_BITMAP_HELVETICA_10);
        glColor3f(0,0,1);
        DrawCircle(375,y8,8,100);
    }
    else
    {

    }
    if(count9==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y9-2,"20",GLUT_BITMAP_HELVETICA_10);
        glColor3f(0,1,0);
        DrawCircle(375,y9,8,100);
    }
    else
    {

    }

    glFlush();
}

void draw_target3(int count1,int count2,int count3,int count4,int count5,int count6,int count7,int count8,int count9,int y11,int y2,int y3,int y4,int y5,int y6,int y7,int y8,int y9)
{
    if(count1==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y11-2,"15",GLUT_BITMAP_HELVETICA_10);
    	glColor3f(0,0,1);


        DrawCircle(375,y11,8,100);
    }
    else
    {

    }
    if(count2==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y2-2,"20",GLUT_BITMAP_HELVETICA_10);
    	glColor3f(0,1,0);

         DrawCircle(375,y2,8,100);

    }
    else
    {

    }
    if(count3==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y3-2,"-10",GLUT_BITMAP_HELVETICA_10);
        glColor3f(1,0,0);

        DrawCircle(375,y3,9,100);

    }
    else
    {

    }
    if(count4==0)
    {

    	glColor3f(1,1,1);
    	glLineWidth(3);
    	bitmap_output2(372,y4-2,"10",GLUT_BITMAP_HELVETICA_10);

        glColor3f(1,0.5,0);

        DrawCircle(375,y4,8,100);

    }
    else
    {

    }
    if(count5==0)
    {

    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(370,y5-2,"-10",GLUT_BITMAP_HELVETICA_10);
        glColor3f(1,0,0);
        DrawCircle(375,y5,9,100);
    }
    else
    {

    }
    if(count6==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y6-2,"20",GLUT_BITMAP_HELVETICA_10);

        glColor3f(0,1,0);
        DrawCircle(375,y6,8,100);
    }
    else
    {

    }
    if(count7==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y7-2,"10",GLUT_BITMAP_HELVETICA_10);
        glColor3f(1,0.5,0);
        DrawCircle(375,y7,8,100);
    }
    else
    {

    }
    if(count8==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y8-2,"15",GLUT_BITMAP_HELVETICA_10);
        glColor3f(0,0,1);
        DrawCircle(375,y8,8,100);
    }
    else
    {

    }
    if(count9==0)
    {
    	glColor3f(1,1,1);
    	glLineWidth(3);
    	    	bitmap_output2(372,y9-2,"-10",GLUT_BITMAP_HELVETICA_10);
        glColor3f(1,0,0);
        DrawCircle(375,y9,9,100);
    }
    else
    {

    }

    glFlush();
}
void scoreValuel4(int score,int visib){

	char str[100];
	if(visib==1)
	{
	 sprintf(str,"POINT : %d",score);
	 bitmap_output2(400,200,str,GLUT_BITMAP_HELVETICA_18);
	}
}

void draw_target4(int x,int y)
{
	glTranslatef(x,y,0);
	int width;
	int height;

	//drawDart(375,250,2,20,20);
	for(int i=0;i<5;i++)
	{

		glPushMatrix();

	if(i==0)
	{
		glColor3f(0,0,0);
		width=2;
		height=20;
	}
	else if(i==1)
	{
		width=5;
		height=50;
	 glColor3f(1,0,0);
	}
	 else if(i==2)
		glColor3f(0,1,0);
	else if(i==3)
			glColor3f(0,0,1);
	else if(i==4)
			glColor3f(1,1,1);
	        drawDart(0,0,width,height,20);
	        glPopMatrix();
	        width+=5;
	        height+=20;

	}
	}
