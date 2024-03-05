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
void drive(speed, distance);                      //Speed as % of max speed, distance in cm
void driveAdv(speedLeft, speedRight, distance);   //Drive function, but with each speed available
void turn(speed, angle);     	                  //-speed for left turn, +speed for right turn, angle in degrees

/*----------------------------- TEST CODE ------------------------------*/
int main()
{
    //TEST CODE BELOW
 
    
    
    
    return 0;
}


/*------------------------- FUNCTION DETAILS ---------------------------*/
void drive(speed, distance) {
    mav(rM,speed*rMS/100);
    mav(lM,speed*lMS/100);
    msleep(distance/0.0111);
    ao();
    msleep(10);
}

void driveAdv(speedLeft, speedRight, distance) {
    mav(rM,speedRight*rMS/100);
    mav(lM,speedLeft*lMS/100);
    msleep(distance/0.0111);
    ao();
    msleep(10);
}

void turn(speed, angle) {
    mav(rM,-speed*rMS/100);
    mav(lM,speed*lMS/100);
    msleep(angle*(1000/90));  //Conversion factor is 1000 ticks / 90 degrees
    ao();
    msleep(10);
}


