
#include<iostream>
#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include"levels.h"
using namespace std;
int level=1;
int maxy=600, count, maxx=500, n=3, m=3,r,q,limit=20,score=0;
float xmin = -50.0, xmax = 5, ymin = -50.0, ymax = 5;
int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,status=0;
int x=25,y=50,T=25,x1,x2,x3,x4,x5,x6,x7,x8,x9,y2,y3,y4,y5,y6,y7,y8,y9,y11,lx4,ly4,visibleFlag=0,points=0;
int t=0,lStatus=0;
char str[10];
const int numOfStars = 100;
float starX[numOfStars];	//arrays for to store star coords
float starY[numOfStars];
void id1();
void id();
void ida();
void id1a();

void draw_target();
//void draw_target2();
void redraw();
void keys(unsigned char,int,int);

/*to display bitmap char*/
void bitmap_output(int x,int y,char *string,void *font)
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

float random(int range) //create a random number in a specified range
{
	float randNum;
	randNum = (rand() % range);
	return randNum;
}

void setUpStarCoords()	//to initialise array of random coords for star within coordinate space
{
	for ( int i=0; i < numOfStars; i++)
	{
		starX[i] = (random(500) + xmax);
		starY[i] = (random(500) + ymax);
	}
}

void drawStar()		//draws stars in coordinate space using coords from arrays
{
    glPointSize(2.0);	//sets size of stars
	glLoadIdentity();

	for (int i=0; i<numOfStars; i++)
	{
		glBegin(GL_POINTS);
		glVertex2f(starX[i], starY[i]);
		glEnd();
	}
}

//set key to perform desired operation
void keys(unsigned char k,int r,int q)
{
    if(k==' ')
    {
    	if(level==1)
        glutIdleFunc(id1);
    	else
            glutIdleFunc(id1a);
    }
    if(k=='l')
    {
    	if(lStatus==1)
    	    	{
    	    		lStatus=0;
    	    		level=level+1;
    	    		score=0;
    	    		if(level==2)
    	    		limit=20;
    	    		else if(level==3||level==4)
    	    			limit=15;
    	    		count=limit;
    	    		    		t=0;
    	    		    		y11=450;y2=400;y3=350;y4=300;y5=250;y6=200;y7=150;y8=100;y9=50;
    	    		    		count1=0;count2=0;count3=0;count4=0;count5=0;count6=0;count7=0;count8=0;count9=0;
    	    		    		//if(level==2||level==3)
    	    		    		glutIdleFunc(ida);

    	    	}
    }
    if(k=='r')
    {
    	if(status==1)
    	{

    		t=0;
    		limit=20;
    		status=0;
    		count=limit;
    		score=0;
    		y11=450;y2=400;y3=350;y4=300;y5=250;y6=200;y7=150;y8=100;y9=50;
    		count1=0;count2=0;count3=0;count4=0;count5=0;count6=0;count7=0;count8=0;count9=0;
    		level=1;
    		glutIdleFunc(id);
    	}
    }
    if(k=='q')
        return;
}

//sub menu to display instructions
void demo_menu(int i)
{
    switch(i)
    {
        case 5:
        case 6:
        case 7:
        case 8:break;
    }
}

/*based on count display no of arrows and result of game*/
void counting()
{
    sprintf(str,"Bullets left:%d",count);
    char levelString[100];
    sprintf(levelString,"CONGRATULATIONS, Be ready for Level %d Enter L",level+1);
    bitmap_output(400,40,str,GLUT_BITMAP_HELVETICA_18);
    if(level==1||level==2)
    {
    if(count1==1 && count2==1 && count3==1 && count4==1 && count5==1 && count6==1 && count7==1 && count8==1 && count9==1)
    {

        bitmap_output(5,300,levelString,GLUT_BITMAP_TIMES_ROMAN_24);
        lStatus=1;
        glutKeyboardFunc(keys);
        glutIdleFunc(NULL);
    }
    else if(count<=0)
    {
       // sprintf(str,"NO of arrows:%d,NO OF ARROWS OVER GAME LOST \n Enter R to start",count);
        status=1;

        bitmap_output(5,300,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
        bitmap_output(5,280,"ENTER R TO RESTART",GLUT_BITMAP_TIMES_ROMAN_24);
        while(t){}
        glutKeyboardFunc(keys);
       glutIdleFunc(NULL);
    }
    }
    else if(level==3)
    {
    	if(score>=100)
    	{
    	 bitmap_output(5,300,levelString,GLUT_BITMAP_TIMES_ROMAN_24);
    	        lStatus=1;
    	        glutKeyboardFunc(keys);
    	        glutIdleFunc(NULL);
    	}
    	else if(count<=0)
    	{
    		 status=1;

    		        bitmap_output(5,300,"GAME OVER ",GLUT_BITMAP_TIMES_ROMAN_24);
    		        bitmap_output(5,280,"ENTER R TO RESTART",GLUT_BITMAP_TIMES_ROMAN_24);
    		        while(t){}
    		        glutKeyboardFunc(keys);
    		       glutIdleFunc(NULL);
    	}

    }
    else if(level==4)
     {
     	if(score>=500)
     	{
     	 bitmap_output(5,300,levelString,GLUT_BITMAP_TIMES_ROMAN_24);
     	        lStatus=1;
     	        glutKeyboardFunc(keys);
     	        glutIdleFunc(NULL);
     	}
     	else if(count<=0)
     	{
     		 status=1;

     		        bitmap_output(5,300,"GAME OVER ",GLUT_BITMAP_TIMES_ROMAN_24);
     		        bitmap_output(5,280,"ENTER R TO RESTART",GLUT_BITMAP_TIMES_ROMAN_24);
     		        while(t){}
     		        glutKeyboardFunc(keys);
     		       glutIdleFunc(NULL);
     	}

     }
}



//TO CHECK WHETHER ARROW HITS TARGET
void disa()
{
    if((x+100>=x1-8 && x+100<=x1+8) && (y>=442 && y<=458) && (!count1))
    {
        count1=1;
        x=25;
        y=0;
        score+=10;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x2-8 && x+100<=x2+8)&&(y>=392&&y<=408) && (!count2))
    {
        count2=1;
        score+=10;
        x=25;
        y=0;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x3-8 && x+100<=x3+8)&&(y>=342 &&y<=358)&&(!count3))
    {
        count3=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x4-8 && x+100<=x4+8)&&(y>=292&&y<=308)&&(!count4))

    {
        count4=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x5-8 && x+100<=x5+8)&&(y>=242&&y<=258)&&(!count5))
    {
        count5=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x6-8 && x+100<=x6+8)&&(y>=192&&y<=208)&&(!count6))
    {
        count6=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x7-8 && x+100<=x7+8)&&(y>=142&&y<=158)&&(!count7))
    {
        count7=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x8-8 && x+100<=x8+8)&&(y>=92&&y<=108)&&(!count8))
    {
        count8=1;
        score+=10;
        x=25;
        y=0;
        count--;
        glutIdleFunc(id);
    }
    else if((x+100>=x9-8 && x+100<=x9+8)&&(y>=42&&y<=58)&&(!count9))
    {
        count9=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(id);
    }

}
//TO CHECK WHETHER ARROW HITS TARGET
void disa2()
{
	if(level<4)
	{
    if((x+100>=367 && x+100<=383) && (y>=y11-8 && y<=y11+8) && (!count1))
    {
        count1=1;
        x=25;
        score+=15;
        y=0;
        count--;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y2-8&&y<=y2+8) && (!count2))
    {
        count2=1;
        x=25;
        y=0;
        count--;
        score+=20;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y3-8&&y<=y3+8)&&(!count3))
    {
        count3=1;
        x=25;
        y=0;
        if(level==2)
        score+=15;
        else if(level==3)
        	score-=10;
        count--;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y4-8&&y<=y4+8)&&(!count4))

    {
        count4=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y5-8&&y<=y5+8)&&(!count5))
    {
        count5=1;
     //   score+=10;
        if(level==2)
               score+=10;
               else if(level==3)
               	score-=10;
        x=25;
        y=0;
        count--;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y6-8&&y<=y6+8)&&(!count6))
    {
        count6=1;
        x=25;
        score+=20;
        y=0;
        count--;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y7-8&&y<=y+8)&&(!count7))
    {
        count7=1;
        x=25;
        score+=10;
        y=0;
        count--;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y8-8&&y<=y8+8)&&(!count8))
    {
        count8=1;
        x=25;
        score+=15;
        y=0;
        count--;
        glutIdleFunc(ida);
    }
    else if((x+100>=367 && x+100<=383)&&(y>=y9-8&&y<=y9+8)&&(!count9))
    {
        count9=1;
        x=25;
        //score+=20;
        if(level==2)
               score+=20;
               else if(level==3)
               	score-=10;
        y=0;
        count--;
        glutIdleFunc(ida);
    }
	}
	else if(level==4)
	{
		 if((x+100==380) && (y>=ly4-10 && y<=ly4+10))
		    {
		        //count1=1;

		        x=25;
		        ly4=500;
		        points=50;
		        score+=50;
		        y=0;
		        count--;
		        glutIdleFunc(ida);
		    }
		 if((x+100==380) && ((y>=ly4-25 && y<ly4-10)||(y>ly4-10 && y<ly4+25)))
		 		    {
		 		        //count1=1;
		 		        x=25;
		 		       ly4=500;
		 		      points=25;

		 		        score+=25;
		 		        y=0;
		 		        count--;
		 		        glutIdleFunc(ida);
		 		    }
		 if((x+100==380) && ((y>=ly4-35 && y<ly4-25)||(y>ly4-25 && y<ly4+35)))
				 		    {
			 	 	 	 	 	 ly4=500;
				 		        //count1=1;
				 		        x=25;
				 		        score+=15;
				 		       points=15;
				 		        y=0;
				 		        count--;
				 		        glutIdleFunc(ida);
				 		    }
		 if((x+100==380) && ((y>=ly4-45 && y<ly4-35)||(y>ly4-35 && y<ly4+45)))
				 		    {
				 		        //count1=1;
				 		        x=25;
				 		       points=10;
				 		       ly4=500;
				 		        score+=10;
				 		        y=0;
				 		        count--;
				 		     //   glutIdleFunc(ida);
				 		    }
		 if((x+100==380) && ((y>=ly4-55 && y<ly4-45)||(y>ly4-45 && y<ly4+55)))
						 		    {
						 		        //count1=1;
						 		        x=25;
						 		        score+=5;
						 		       points=5;
						 		        y=0;
						 		       ly4=500;
						 		        count--;
						 		        glutIdleFunc(ida);
						 		    }
	}

}

/*to move arrow up*/
void id()
{
    y+=n;
    T=x;
    disa();
    if(y>maxy)
    {
        y=0;
        score-=5;
        count--;
    }
    glutPostRedisplay();
}

/*to move arrow up*/
void ida()
{
	 y+=n;
	    T=x;
	    disa2();
	    if(y>maxy)
	    {
	        y=0;
	        score-=5;
	        count--;
	        ly4=500;
	    }
	    if(level==2)
	    {
	    if(y11<40)y11=500;if(y2<40)y2=500;if(y3<40)y3=500;if(y4<40)y4=500;
	        if(y5<40)y5=500;if(y6<40)y6=500;if(y7<40)y7=500;if(y8<40)y8=500;if(y9<40)y9=500;
	    }
    else if(level==3)
	    {
	    	    	if(y11<40)
	    	    	{
	    	    		y11=500;
	    	    		if(count1==1)count1=0;
	    	    	}
	    	    	if(y2<40)
	    	    		    	{
	    	    		    		y2=500;
	    	    		    		if(count2==1)count2=0;
	    	    		    	}
	    	    	if(y3<40)
	    	    	{
	    	    		    y3=500;
	    	    		    if(count3==1)count3=0;
	    	    	}
	    	    	if(y4<40)
	    	    		    	{
	    	    		    		    y4=500;
	    	    		    		    if(count4==1)count4=0;
	    	    		    	}
	    	    	if(y5<40)
	    	    		    	{
	    	    		    		    y5=500;
	    	    		    		    if(count5==1)count5=0;
	    	    		    	}
	    	    	if(y6<40)
	    	    		    	{
	    	    		    		    y6=500;
	    	    		    		    if(count6==1)count6=0;
	    	    		    	}
	    	    	if(y7<40)
	    	    		    	{
	    	    		    		    y7=500;
	    	    		    		    if(count7==1)count7=0;
	    	    		    	}
	    	    	if(y8<40)
	    	    		    	{
	    	    		    		    y8=500;
	    	    		    		    if(count8==1)count8=0;
	    	    		    	}
	    	    	if(y9<40)
	    	    		    	{
	    	    		    		    y9=500;
	    	    		    		    if(count9==1)count9=0;
	    	    		    	}


	    }
    else if(level==4)
    	    { ly4-=n;
    	    }

	    y11=y11-m;y2=y2-m;y3=y3-m;y4=y4-m;y5=y5-m;y6=y6-m;y7=y7-m;y8=y8-m;y9=y9-m;
	    glutPostRedisplay();
}



void DrawSquare(float cx, float cy)
{
    glColor3f(1,0,1);
    glColor3f(0.0, 1.0, 0.0);
   // glGenTextures();
    glBegin(GL_POLYGON);
     glVertex3f(cx-8, cy+8, 0.0);
     glVertex3f(cx+8, cy+8, 0.0);
     glVertex3f(cx+8, cy-8, 0.0);
     glVertex3f(cx-8, cy-8, 0.0);
    glEnd();

}
//to draw arrow
void disp()
{



	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   // gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 400.0, 0.0, 1.0, 0.0);
    // Drawing  of arrow
    glColor3f(1,1,1);
    drawStar();
        glColor3f(0,1,1);
        glBegin(GL_POLYGON);
        //glVertex2d(T,y);
        //glVertex2d(T+100,y);
        glVertex2d(T,y);
        glVertex2d(T+5,y+8);
        glVertex2d(T+60,y);
        glVertex2d(T+90,y);
        glColor3f(1,0,0);
        glVertex2d(T+90,y-1);
        glVertex2d(T+90,y-5);

       // glVertex2d(T+90,y-10);
        //glVertex2d(T+90,y);
        glVertex2d(T+10,y-5);
        glVertex2d(T-5,y-15);
        glVertex2d(T-15,y-15);


        glEnd();
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
        glVertex2d(T+12,y);
        glVertex2d(T+14,y-10);
        glVertex2d(T+6,y-6);
        glVertex2d(T,y);
        glEnd();
        glBegin(GL_LINES);
        glVertex2d(T,y-2);
        glVertex2d(T+90,y-2);
        glEnd();
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex2d (x+90,y);
        glVertex2d(x+100,y-2);
        glVertex2d(x+90,y-4);
        glEnd();

    glColor3f(1,1,1);

    if(level==1){
    	bitmap_output(420,450,"SHOOTING",GLUT_BITMAP_TIMES_ROMAN_24);
    	    	    bitmap_output(420,430,"GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    	    	    bitmap_output(420,410,"LEVEL 1",GLUT_BITMAP_TIMES_ROMAN_24);
    	    	    sprintf(str,"SCORE : %d",score);
    	    	        bitmap_output(420,390,str,GLUT_BITMAP_HELVETICA_18);
    	    counting();

    draw_target();
    glFlush();
    glutSwapBuffers();
    }
    else if(level==2)
    {
    	//glColor3f(1,1,1);
    	 bitmap_output(420,450,"SHOOTING",GLUT_BITMAP_TIMES_ROMAN_24);
    	    bitmap_output(420,430,"GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    	    bitmap_output(420,410,"LEVEL 2",GLUT_BITMAP_TIMES_ROMAN_24);
    	    sprintf(str,"SCORE : %d",score);
   	        bitmap_output(420,390,str,GLUT_BITMAP_HELVETICA_18);
    	    counting();
    	      	    draw_target2(count1,count2,count3,count4,count5,count6,count7,count8,count9,y11,y2,y3,y4,y5,y6,y7,y8,y9);
    	    glFlush();
    	    glutSwapBuffers();

    }
    else if(level==3)
    {
    	if(count>18)
    	bitmap_output(20,450,"Minimun score 70 is required to clear this level",GLUT_BITMAP_TIMES_ROMAN_24);
    	 bitmap_output(420,450,"SHOOTING",GLUT_BITMAP_TIMES_ROMAN_24);
    	    bitmap_output(420,430,"GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    	    bitmap_output(420,410,"LEVEL 3",GLUT_BITMAP_TIMES_ROMAN_24);
    	    sprintf(str,"SCORE : %d",score);
   	        bitmap_output(420,390,str,GLUT_BITMAP_HELVETICA_18);
    	    counting();
    	      	    draw_target3(count1,count2,count3,count4,count5,count6,count7,count8,count9,y11,y2,y3,y4,y5,y6,y7,y8,y9);
    	    glFlush();
    	    glutSwapBuffers();

    }
    else if(level==4)
    {
    	if(count>18)
    	bitmap_output(20,450,"Minimun score 500 is required to clear this level",GLUT_BITMAP_TIMES_ROMAN_24);
    	 bitmap_output(420,450,"SHOOTING",GLUT_BITMAP_TIMES_ROMAN_24);
    	    bitmap_output(420,430,"GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    	    bitmap_output(420,410,"LEVEL 4",GLUT_BITMAP_TIMES_ROMAN_24);
    	    sprintf(str,"SCORE : %d",score);
   	        bitmap_output(420,390,str,GLUT_BITMAP_HELVETICA_18);
   	     //visibleFlag=1;
   	     scoreValuel4(points,1);
    	    counting();
    	    glColor3f(1,1,1);
    	      	    //draw_target3(count1,count2,count3,count4,count5,count6,count7,count8,count9,y11,y2,y3,y4,y5,y6,y7,y8,y9);
    	    draw_target4(lx4,ly4);
    	    glFlush();
    	    glutSwapBuffers();

    }
    }



void init()
{
	x1=rand() % 100 + 300;x2=rand() % 100 + 300;x3=rand() % 100 + 300;x4=rand() % 100 + 300;x5=rand() % 100 + 300;x6=rand() % 100 + 300;x7=rand() % 100 + 300;x8=rand() % 100 + 300;x9=rand() % 100 + 300;
	y11=450;y2=400;y3=350;y4=300;y5=250;y6=200;y7=150;y8=100;y9=50;
	ly4=450;
	lx4=375;
	setUpStarCoords();
	glClearColor(0,0,0,1);
    glColor3f(1,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

//to draw the target inside the loop

void draw_target()
{
    if(count1==0)
    {
        glColor3f(1,0,1);
        DrawSquare(x1,y11);
    }
    else
    {

    }
    if(count2==0)
    {
        glColor3f(1,0,1);
        DrawSquare(x2,y2);

    }
    else
    {

    }
    if(count3==0)
    {

        glColor3f(1,0,1);
        DrawSquare(x3,y3);
        //DrawCircle(375,350,8,100);

    }
    else
    {

    }
    if(count4==0)
    {



        glColor3f(1,0,1);
        DrawSquare(x4,y4);
        //DrawCircle(375,300,8,100);

    }
    else
    {

    }
    if(count5==0)
    {


        glColor3f(1,0,1);
        DrawSquare(x5,y5);
       // DrawCircle(375,250,8,100);
    }
    else
    {

    }
    if(count6==0)
    {

        glColor3f(1,0,1);
        DrawSquare(x6,y6);
        //DrawCircle(375,200,8,100);
    }
    else
    {

    }
    if(count7==0)
    {

        glColor3f(1,0,1);
        DrawSquare(x7,y7);
        //DrawCircle(375,150,8,100);
    }
    else
    {

    }
    if(count8==0)
    {

        glColor3f(1,0,1);
        DrawSquare(x8,y8);
        //DrawCircle(375,100,8,100);
    }
    else
    {

    }
    if(count9==0)
    {

        glColor3f(1,0,1);
		DrawSquare(x9,y9);
       // DrawCircle(375,50,8,100);
    }
    else
    {

    }
    glFlush();
}

//to move the arrow left
void id1()
{
    x+=m;
    disa();
    if(x+110>maxx)
    {
        x=25;
        y=0;
        score-=5;
        count--;
        glutIdleFunc(id);
    }
    glutPostRedisplay();
}
void id1a()
{
	 x+=m;
	    disa2();
	    if(x+110>maxx)
	    {
	        x=25;
	        score-=5;
	        y=0;
	        ly4=500;
	        count--;
	        glutIdleFunc(ida);
	    }
	    if(level==2)
	    {
	    if(y11<40)y11=500;if(y2<40)y2=500;if(y3<40)y3=500;if(y4<40)y4=500;
	    if(y5<40)y5=500;if(y6<40)y6=500;if(y7<40)y7=500;if(y8<40)y8=500;if(y9<40)y9=500;
	    }
	    else if(level==3)
	    	    {
	    	    	if(y11<40)
	    	    	{
	    	    		y11=500;
	    	    		if(count1==1)count1=0;
	    	    	}
	    	    	if(y2<40)
	    	    		    	{
	    	    		    		y2=500;
	    	    		    		if(count2==1)count2=0;
	    	    		    	}
	    	    	if(y3<40)
	    	    	{
	    	    		    y3=500;
	    	    		    if(count3==1)count3=0;
	    	    	}
	    	    	if(y4<40)
	    	    		    	{
	    	    		    		    y4=500;
	    	    		    		    if(count4==1)count4=0;
	    	    		    	}
	    	    	if(y5<40)
	    	    		    	{
	    	    		    		    y5=500;
	    	    		    		    if(count5==1)count5=0;
	    	    		    	}
	    	    	if(y6<40)
	    	    		    	{
	    	    		    		    y6=500;
	    	    		    		    if(count6==1)count6=0;
	    	    		    	}
	    	    	if(y7<40)
	    	    		    	{
	    	    		    		    y7=500;
	    	    		    		    if(count7==1)count7=0;
	    	    		    	}
	    	    	if(y8<40)
	    	    		    	{
	    	    		    		    y8=500;
	    	    		    		    if(count8==1)count8=0;
	    	    		    	}
	    	    	if(y9<40)
	    	    		    	{
	    	    		    		    y9=500;
	    	    		    		    if(count9==1)count9=0;
	    	    		    	}


	    	    }
	    else if(level==4)
	    {ly4-=n;
	    }

	    y11=y11-m;y2=y2-m;y3=y3-m;y4=y4-m;y5=y5-m;y6

	    =y6-m;y7=y7-m;y8=y8-m;y9=y9-m;
	    glutPostRedisplay();
}

//sub menu to display designer names
void demo(int i)
{
    switch(i)
    {
        case 9:
        case 10:
        case 11:break;
    }
}
void game(int id)
{
    switch(id);
    {
    }
}
int main(int argc,char **argv)
{

    int sub_menu;

    count=limit;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(900,900);
    glutCreateWindow("SHOOTING GAME");
    sub_menu=glutCreateMenu(demo_menu);
    glutAddMenuEntry(" space  to move right",5);
    glutAddMenuEntry("A total of i5 arrows and 10 blocks are present",6);
    glutAddMenuEntry("You loose the game if the bullet count reaches to zero",7);
    glutAddMenuEntry("or else you win",8);
    glutCreateMenu(game);
    glutAddSubMenu("INSTRUCTIONS",sub_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    if(level==4)
    	n=2;
    glutDisplayFunc(disp);
    if(level==1)
    glutIdleFunc(id);
    else
    glutIdleFunc(ida);
    glutKeyboardFunc(keys);
    init();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}



















