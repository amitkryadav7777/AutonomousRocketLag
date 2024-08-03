// Rocket launching using computer graphics

//    ***** This is main file *****

#include "AutoRocket.cpp"
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <graphics.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int start = 1;
double s = 0;
float t = 0;

int speed = 0;
int height = 0;
int time = 0;
bool launch = false;
void flight(int i);

void flight(int h) // 0
{
    int gd = DETECT, gm, i, a;

    // Path of the program
    if (h == 0){
        initgraph(&gd, &gm, "C:\\MinGW\\BGI");
    }

        outtextxy(150, 70, "Press  l ( L )  for  Autonumous Landing!");
        outtextxy(200, 100, "Press  a  for  -2  speed (Downward)");
        outtextxy(200, 130, "Press  s  for  +8  speed (Upward)");
        outtextxy(200, 160, "Press  d  for  +14 speed (Upward)");
        delay(8000);
        cleardevice();

    // Move the rocket
    while (h < 150000){
        if(h>0){
            launch = true;
        }
        if(h > 140000){
            outtextxy(200, 150, "You have reached at maximum height");
            outtextxy(250, 170, "Don't go further!");
            delay(3000);
        }
        // cout << 450 + h;
        cleardevice();


        // Telemetry

        height = h;
        char heightText[10];
        sprintf(heightText, "Altitude: %d", height);
        outtextxy(500, 10, heightText);

        char speedText[10];
        sprintf(speedText, "Speed: %d", speed);
        outtextxy(500, 40, speedText);

        // Rocket body
        line(300, 435 - h, 330, 435 - h); // horizontal

        line(300, 435 - h, 300, 375 - h); // vertical
        line(330, 435 - h, 330, 375 - h); // vertical

        line(315, 340 - h, 300, 375 - h); // nose cone
        line(315, 340 - h, 330, 375 - h); // nose cone

        line(315, 435 - h, 305, 450 - h); // engine cone
        line(315, 435 - h, 325, 450 - h); // engine cone

        line(305, 450 - h, 325, 450 - h); // engine base

        //Jet flame of the engine's nozel
        int flameSize = 10;
        if (h > 10)
        {
            line(310, 450 - h, 310, 450 + flameSize - h); // flame
            line(315, 450 - h, 315, 450 + flameSize - h); // flame
            line(320, 450 - h, 320, 450 + flameSize - h); // flame
        }

        // Groud
        line(0, 450, getmaxx(), 450);

        if(h == 0 && start){
            start = 0;
            launch = false;
            // char* heightText = new char[30];
            char* heightText = "Will start in 2 sec.";
            outtextxy(250, 100, heightText);
            // delete heightText;
            delay(1000);
            heightText = "Will start in 1 sec.";
            outtextxy(250, 100, heightText);
            delay(1000);
            heightText = "... Press Button ...";
            outtextxy(250, 100, heightText);    
            delay(2000);
        }
        if(h == 0 && (speed > -5 && speed <= 0 && launch)){
            outtextxy(300, 100, "Successfully landed!");
            cout  << endl << "Successfully landed!" << endl;
            delay(2000);
            return;
        }

        if(h < 0 && speed < -5){
            outtextxy(300, 100, "Crash landing!");
            cout << endl << "Crash landing!" << endl;
            delay(2000);
            return;

        }

        int g = 10;
        int m = 10;

        if (kbhit())
        {
            char key = getch();
            t = 0;
            // Getting the pressed key
            switch (key){
                case 'a': 
                    speed = round(.5*10*.01 - .5*10*.5);     //  downward speed -2
                    if(h>=3 && h<15){
                        speed = -1;
                    }
                    s =  h + speed;                               
                    h = round(s);      
                    break;
           
                case 's': 
                speed = .5*10*2 - .5*10*.4;         // Upward speed +8
                    s = h + speed;
                    h = round(s);
                    break;
            
                case 'd':                           // Upward speed +14
                    speed = .5*10*3 - .5*10*.2;
                    s = h + speed;
                    h = round(s);
                    break;

                case 'l':
                    autoLanding(h, speed);
                    return;
                    break;
            }
        }
        else{        // else block execute 5 more time than if block even button is pressed. 
            t = t + .05;
            cout << t;
            // system("cls");
            speed = - .5*10*1*.2*t;
            s = h + speed;
            h = round(s);
        }
    }
}

// Driver code
int main()
{
    flight(0);

    // Close the graph
    closegraph();
}
