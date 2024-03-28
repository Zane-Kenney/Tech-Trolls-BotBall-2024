#include <kipr/wombat.h>

/* ----------------------------- VARIABLES -----------------------------*/
//Ir Sensor Variable
int darkThreshold = 4000;  //Higher is darker

//Motor Variables
int lM = 1;
int rM = 0;
int rMS = 1000;
int lMS = 958;

//Claw Variables
int close = 1870;
int down = 990;
int up = 600;
int arm = 0;
int claw = 1;


/* ----------------------------- FUNCTIONS -----------------------------*/
void drive(float speed, int distance);                      //Speed as % of max speed, distance in cm
void driveAdv(float speedLeft, float speedRight, int distance);   //Drive function, but with each speed available
void turnOld(float speed, float angle);     	                  //-speed for left turn, +speed for right turn, angle in degrees
void turn(float speed, float angle);

/*----------------------------- TEST CODE ------------------------------*/
int main()
{
    //TEST CODE BELOW
 
    drive(1, 20);    //drive 20 cm max speed
    drive(0.5, 30);  //drive 30 cm half speed
    turn(-0.5, 90);  // turn 90 degrees left half speed
    turn (1, 90);    // turn 90 degrees right full speed


    return 0;
}


/*------------------------- FUNCTION DETAILS ---------------------------*/
void drive(float speed, int distance) {
    mav(rM,speed*rMS);
    mav(lM,speed*lMS);
    msleep(distance/speed/0.0111);
    ao();
    msleep(10);
}

void driveAdv(float speedLeft, float speedRight, int  distance) {
    mav(rM,speedRight*rMS);
    mav(lM,speedLeft*lMS);
    msleep(distance/((speedLeft+speedRight)/2)/0.0111);
    ao();
    msleep(10);
}

void turnOld(float speed, float angle) {
    mav(rM,-speed*rMS);
    mav(lM,speed*lMS);
    msleep(angle*(1000/90));  //Conversion factor is 1000 ms / 90 degrees
    ao();
    msleep(10);
}

void turn(float speed, float angle) {
    mav(rM,-speed*rMS);
    mav(lM,speed*lMS);
    msleep(angle/speed*(1000/90));  //Conversion factor is 1000 ms / 90 degrees
    ao();
    msleep(10);
}