#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include <dos.h>
int d, shouldMove;
int sceneOneFlag=1,sceneTwoFlag=1,sceneThreeFlag=1,sceneFourFlag=1;

void displayMan(int x,int y,int colour)
{
    setcolor(colour);
    circle(x,y,20);         //face
    line(x,y+20,x,y+30);        //neck
    line(x,y+30,x-20,y+40);    //left hand
    line(x,y+30,x+20,y+40);    //right hand
    line(x,y+30,x,y+60);    //body
    setcolor(WHITE);
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

void drawPipe()
{
    outtextxy(355, 290, "I");
    outtextxy(355, 310, "U");
    outtextxy(355, 330, "P");
    outtextxy(355, 350, "A");
    outtextxy(355, 370, "C");

    line(330,250,330,430);
    line(380,250,380,430);

    line(320,250,390,250);
    line(320,220,390,220);
    line(320,220,320,250);
    line(390,220,390,250);

    setfillstyle(SOLID_FILL,GREEN);
    floodfill(350,300,WHITE);
    floodfill(350,230,WHITE);
}

void drawStaircase()
{

    line(200,390,260,390);
    line(260,350,320,350);
    line(320,310,380,310);
    line(380,270,440,270);
    line(440,230,getmaxx(),230);

    line(200,390,200,430);
    line(260,350,260,390);
    line(320,310,320,350);
    line(380,270,380,310);
    line(440,230,440,270);

    setfillstyle(INTERLEAVE_FILL,RED);
    floodfill(500,420,WHITE);

    outtextxy(210, 400, "Practicals");
    outtextxy(270, 360, "River-Boat Problem");
    outtextxy(330, 320, "Past Year Questions");
    outtextxy(390, 280, "HC Verma");
    outtextxy(450, 240, "Mock Tests");

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
    int i,x=50,y=340,z=50,page=0;

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

            // Dropping coin on man's head
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

            float temp2;
            while(x<=460)
            {
                line(0,430,640,430);

                drawBrickWall();
                drawPipe();
                //Display message
                outtextxy(280, 30, "Coins            X 10");
                circle(340,35,10);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(340,35,WHITE);

                 if(x<=355)
                 {
                    circle(355,200,15);
                    setfillstyle(SOLID_FILL,YELLOW);
                    floodfill(355,200,WHITE);
                 }
                 else{
                    outtextxy(280, 30, "Coins            X 20");
                    outtextxy(300, 450, "Tadaaa");
                    circle(340,35,10);
                    setfillstyle(SOLID_FILL,YELLOW);
                    floodfill(340,35,WHITE);
                 }

                 if(x<250)
                 {
                    circle(355,200,15);
                    setfillstyle(SOLID_FILL,YELLOW);
                    floodfill(355,200,WHITE);
                     displayMan(x,345,WHITE);
                     x=moveMan(x,y);
                 }

                else
                {
                    temp2=(0.0208*x*x)-(14.81*x)+(2744);
                    displayMan(x,temp2,WHITE);
                    line(x,temp2+60,x-8,temp2+85);
                    line(x,temp2+60,x+8,temp2+85);

                    delay(150);
                    x=x+10;
                }

            cleardevice();
            }

            float temp3;
             while(x<=570)
            {
                cleardevice();
                line(0,430,640,430);
                outtextxy(500, 440, "Kinematics");
                drawBrickWall();
                drawPipe();
                //Display message
                outtextxy(280, 30, "Coins            X 20");
                circle(340,35,10);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(340,35,WHITE);

                //Coin on top of block
                if(x<=560)
                {
                    circle(560,380,15);
                    setfillstyle(SOLID_FILL,YELLOW);
                    floodfill(560,380,WHITE);
                }

                 if(x<=470)
                 {
                    setfillstyle(HATCH_FILL,LIGHTCYAN);
                    bar(480,400,600,430);
                     displayMan(x,345,WHITE);
                     x=moveMan(x,y);
                 }

                else
                {
                    temp3=  (0.0585*x*x)-(60.6*x)+15870;
                    displayMan(x,temp3,WHITE);
                    line(x,temp3+60,x-8,temp3+85);
                    line(x,temp3+60,x+8,temp3+85);
                    if(x>560)
                    {
                        setfillstyle(HATCH_FILL,LIGHTCYAN);
                        bar(480,temp3+85,600,430);
                    }
                    else
                    {
                        setfillstyle(HATCH_FILL,LIGHTCYAN);
                        bar(480,400,600,430);
                    }

                    delay(200);
                    x=x+10;
                }

            }

            while(x<=getmaxx())
            {
                cleardevice();
                line(0,430,640,430);
                 outtextxy(500, 440, "Kinematics");

                drawBrickWall();
                drawPipe();
                setfillstyle(HATCH_FILL,LIGHTCYAN);
                bar(480,425,600,430);
                //Display message
                outtextxy(280, 30, "Coins            X 30");
                outtextxy(300, 450, "Yipee");
                circle(340,35,10);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(340,35,WHITE);
                displayMan(x,345,WHITE);
                x=moveMan(x,y);

            }
            sceneTwoFlag=0;
        }

        /********************************** SCENE THREE ****************************************************/
        d=0,x=50,y=340,z=50,shouldMove=1;

        if(sceneThreeFlag)
        {
            while(x<150)
            {
                cleardevice();
                line(0,430,640,430);
                drawStaircase();
                outtextxy(280, 30, "Coins            X 30");
                circle(340,35,10);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(340,35,WHITE);
                displayMan(x,345,WHITE);
                x=moveMan(x,y);
            }
            x=230;
            int temp4=305;
            while(x<=480)
            {
                cleardevice();
                line(0,430,640,430);
                drawStaircase();

                outtextxy(280, 30, "Coins            X 30");
                circle(340,35,10);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(340,35,WHITE);

                displayMan(x,temp4,WHITE);
                line(x,temp4+60,x-8,temp4+85);
                line(x,temp4+60,x+8,temp4+85);

                x+=60;
                temp4-=40;
                delay(700);
            }
            //Drawing end flag
            outtextxy(500,80,"Success");
            line(500,230,500,100);
            line(505,230,505,100);
            line(500,100,505,100);
            setfillstyle(SOLID_FILL,BROWN);
            floodfill(502,101,WHITE);

            line(505,100,575,125);
            line(575,125,505,150);
            setfillstyle(SOLID_FILL,RED);
            floodfill(510,110,WHITE);
            delay(400);

            x=470;
            while(x<=getmaxx())
            {

                line(0,430,640,430);
                drawStaircase();

                outtextxy(280, 30, "Coins            X 100");
                circle(340,35,10);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(340,35,WHITE);

                outtextxy(500,80,"Success");
                outtextxy(510,15,"Promoted to");
                outtextxy(510,35,"Standard 12");

                //Arrow
                line(590,30,610,30);
                line(590,35,610,35);
                line(590,30,590,35);

                line(610,30,610,25);
                line(610,35,610,40);

                line(610,25,630,32);
                line(610,40,630,32);

                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(600,32,WHITE);

                //Drawing end flag
                line(500,230,500,100);
                line(505,230,505,100);
                line(500,100,505,100);
                setfillstyle(SOLID_FILL,BROWN);
                floodfill(502,101,WHITE);

                line(505,100,575,125);
                line(575,125,505,150);
                setfillstyle(SOLID_FILL,RED);
                floodfill(510,110,WHITE);
                displayMan(x,145,WHITE);
                x=moveMan(x,140);
                cleardevice();

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
