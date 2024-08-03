#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <graphics.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int autoLanding(float h , float speed){
    int itrL = 1;
    float acc = 0;
    acc = (speed*speed)/(2*h);   // Code for calculating acceleration required for autonumous landing

    int gd = DETECT, gm, i, a;

    // Path of the program
    if (h == 0){
        initgraph(&gd, &gm, "C:\\MinGW\\BGI");
    }

    // Move the rocket
    while (h < 150001){

        cleardevice();

        // Telemetry
        char AheightText[10];
        sprintf(AheightText, "Altitude: %f", h);
        outtextxy(500, 10, AheightText);

        char speedText[10];
        sprintf(speedText, "Speed: %f", speed);
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

        if(h == 0 && (speed > -5 && speed < 5)){
            outtextxy(300, 100, "Successfully landed!");
            cout  << endl << "Successfully landed!" << endl;
            delay(2000);
            return 1;
        }

        if(h < 0 && speed < -5){
            outtextxy(300, 100, "Crash landing!");
            cout << endl << "Crash landing!" << endl;
            delay(2000);
            return 1;
        }

        speed = speed + acc;
        if(h<=50){
            h = round(h);
            speed = -1;
        }
        h = h + speed;
        delay(9);
    }
    return 0;
}