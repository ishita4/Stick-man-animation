#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include <dos.h>
int d, shouldMove;
int sceneOneFlag=1,sceneTwoFlag=1;
void displayMan(int x,int y,int colour)
{
    setcolor(colour);
    circle(x,y,20);         //face
    line(x,y+20,x,y+30);        //neck
    line(x,y+30,x-20,y+40);    //left hand
    line(x,y+30,x+20,y+40);    //right hand
    line(x,y+30,x,y+60);    //body
    setcolor(WHITE);
//line(x+30,y+30,x+30,y-90);  //umbrella
//pieslice(x+30,y-30,0,180,55);
}

void drawFlag()
{
    //Pole
    line(220,430,220,250);
    line(225,430,225,250);
    line(220,250,225,250);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(222,300,WHITE);

    //Flag
    line(225,250,300,275);
    line(225,300,300,275);
    setfillstyle(SOLID_FILL,RED);
    floodfill(230,260,WHITE);
}

void drawCastle()
{
    outtextxy(220, 230, "Standard 11");

    //Castle Wall
    line(420,250,420,430);
    line(600,250,600,430);
    int a,b,c,d;
    a=420;
    for(int i=0;i<5;i++)
    {
        b=a+20;
        c=b;
        d=c+20;
        line(a,250,b,250);
        line(b,250,b,270);
        if(i==4)
            continue;
        line(c,270,d,270);
        line(d,250,d,270);
        a=d;
    }

    //Door
    line(480,305,480,430);
    line(540,305,540,430);
    line(480,305,540,305);


    setfillstyle(WIDE_DOT_FILL,RED);
    floodfill(500,300,WHITE);

}

void drawBrickWall()
{
    outtextxy(75, 200, "Trigonometry");
    line(50,220,200,220);
    line(50,250,200,250);
    line(50,220,50,250);
    line(200,220,200,250);
    setfillstyle(INTERLEAVE_FILL,RED);
    floodfill(100,240,WHITE);
    line(160,220,160,250);

    setfillstyle(SOLID_FILL,BROWN);
    floodfill(180,240,WHITE);

}

void jump(int x, int y,int factor)
{
    for(int i=0;i<factor;i+=2)
    {
        drawBrickWall();
        displayMan(x,y,WHITE);
        //legs
        line(x,y+60,x-8,y+90);
        line(x,y+60,x+8,y+90);
        y-=i;
        line(0,430,640,430);
        delay(100);
        cleardevice();
    }

    for(int i=0;i<factor;i+=2)
    {
        drawBrickWall();
        displayMan(x,y,WHITE);
        //COIN
        circle(x+5,200,15);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(x+5,200,WHITE);
        //legs
        line(x,y+60,x-8,y+90);
        line(x,y+60,x+8,y+90);

        y+=i;
        line(0,430,640,430);
        delay(100);
        cleardevice();
    }
}

int moveMan(int x, int y)
{
    //legs
        if(shouldMove)
        {
            if(d<20)
                d+=4;
            else
                shouldMove=0;
            line(x,y+65,x-d,y+90);
            line(x,y+65,x+d,y+90);
        }
        else
        {
            if(d>0)
                d-=4;
            else
                shouldMove=1;
            line(x,y+65,x-d,y+90);
            line(x,y+65,x+d,y+90);
        }
        delay(200);
        x=(x+10);
        return x;

}

void levelTwo()
{
    //int i,d=0,x=50,y=340,z=50,shouldMove=1;
    int i,x=50,y=340,z=50;

    while(!kbhit())
    {
        /********************************** SCENE ONE ****************************************************/
        //Flags to ensure that the previous scene do not repeat
        if(sceneOneFlag)
        {
            //Movement before flag
            while(x<200)
            {
                cleardevice();
                line(0,430,640,430);
                displayMan(x,345,WHITE);
                x=moveMan(x,y);

            }
            //Flag appears
            drawFlag();
            outtextxy(220, 230, "Standard 11");
            delay(800);

            //Movement after flag
            while(x<=510)
            {
                cleardevice();
                line(0,430,640,430);
                displayMan(x,345,WHITE);

                drawFlag();
                outtextxy(220, 230, "Standard 11");

                drawCastle();
                outtextxy(480, 230, "IIT COACHING");

                x=moveMan(x,y);

            }

           //Make man disappear through door
            displayMan(x-10,345,BLACK);
            setcolor(BLACK);
            line(x-10,y+65,x-10-4,y+90);
            line(x-10,y+65,x-10+4,y+90);
            setcolor(WHITE);
            delay(400);
            sceneOneFlag=0;
            cleardevice();
        }


 /********************************** SCENE TWO ****************************************************/
        d=0,x=50,y=340,z=50,shouldMove=1;

        if(sceneTwoFlag)
        {
            while(x<180)
            {
                cleardevice();
                line(0,430,640,430);
                displayMan(x,345,WHITE);
                drawBrickWall();
                x=moveMan(x,y);
            }

            jump(x-10,y,15);
           // drawCoin(x,200);

            while(x<=240)
            {
                cleardevice();
                line(0,430,640,430);
                displayMan(x,345,WHITE);
                drawBrickWall();
                //Move coin along with man
                circle(x,200,15);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(x,210,WHITE);
                x=moveMan(x,y);

            }

            //Dropping coin on man's head
            int temp=200;
            for(int i=0;i<11;i++)
            {
                cleardevice();
                temp+=10;
                circle(240,temp,15);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(240,temp,WHITE);
                line(0,430,640,430);

                displayMan(240,345,WHITE);
                line(x-10,345+60,x-8-10,345+85);
                line(x-10,345+60,x+8-10,345+85);

                drawBrickWall();
                delay(100);
            }
            outtextxy(300, 450, "Hurray");
            outtextxy(280, 30, "Coins            X 10");
            circle(340,35,10);
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(340,35,WHITE);
            delay(1000);

            while(x<=510)
            {
                cleardevice();
                line(0,430,640,430);
                displayMan(x,345,WHITE);
                drawBrickWall();
                outtextxy(280, 30, "Coins            X 10");
                circle(340,35,10);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(340,35,WHITE);
                x=moveMan(x,y);

            }
        }
    }

}

int main()
{
    int gd=DETECT, gm;
    int rx,ry;
    initgraph(&gd,&gm,"\\TURBOC3\\BGI");

    levelTwo();
    getch();
    return 0;
}
