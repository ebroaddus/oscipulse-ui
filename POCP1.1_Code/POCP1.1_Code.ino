// include proper libraries for LCD and motor
#include "ssd1306.h"
#include "nano_gfx.h"
#include "sova.h"
#include <Wire.h>
#include <AS5600.h> //Absolute encoder

#define bA 2 //button A (interrupt)
#define bB 3 //button B (- and select)
#define bC 4 //button C (+ and select)
#define bD 5 //button D (select and exit)
// Motorcontroller pins
#define IN1 9
#define IN2 6

AMS_5600 ams5600;

// declare all variables
int AState; //represents state of button A
int BState; //represents state of button B
int CState; //represents state of button C
int DState; //represents state of button D

//char digits used to print motor values
const char* numArray[] = {"0","1","2","3","4","5","6","7","8","9"};

int hundsPlace; //used for motor value printing
int tensPlace; //used for motor value printing
int onesPlace; //used for motor value printing
float motorSpeed = 100; //subject to change, values between 5 and  255
float motorPosition = 100.00; //subject to change, values between 10 and 270
unsigned long currTime; //used to keep tract of current time for wait function
unsigned long prevTime; //used as a reference time for wait function
int counter; //counter for most while loops

// motor code variables
float angle = 0.0;
unsigned long compressStart = 0;
int holdPosition;
int integer;
float output;
float zeroPosition;

// values for preset motor options
int speedOp1 = 80;
int speedOp2 = 160;
int speedOp3 = 240;
int posOp1 = 50;
int posOp2 = 150;
int posOp3 = 250;

void setup() {
  Wire.begin();
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  ssd1306_setFixedFont(ssd1306xled_font6x8); //initialize text printing with this size
  ssd1306_128x64_i2c_init();
  pinMode(bA, INPUT_PULLUP); //button A input declaration
  pinMode(bB, INPUT_PULLUP); //button B input declaration
  pinMode(bC, INPUT_PULLUP); //button C input declaration
  pinMode(bD, INPUT_PULLUP); //button D input declaration
  //attachInterrupt(digitalPinToInterrupt(bA), Menu(), RISING);

  //initialize the zero angle
  // --> if the angle is not in desired range, then print error message and hold in loop forever (until reset occurs)
  readEncoder();
  zeroPosition=angle;
  if ((zeroPosition>343.30+2)||(zeroPosition<343.30-2)){
    ssd1306_clearScreen();
    while (true){
      ssd1306_setFixedFont(ssd1306xled_font8x16);
      ssd1306_printFixed(44,  0, "ERROR", STYLE_NORMAL);
      ssd1306_setFixedFont(ssd1306xled_font6x8);
      ssd1306_printFixed(0,  32, "A hardware issue has occured. Please check the functionality of the encoder and restart device.", STYLE_NORMAL);
      }}
      
void loop() {
  // this loop might be a problem considering both functions will run for a significant length of time
  CompDecomp(); //controls the motor
  start_UI(); //starts the whole user interface
}
