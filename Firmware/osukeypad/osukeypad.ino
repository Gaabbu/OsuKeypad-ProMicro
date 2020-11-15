// Including Keyboard and Bounce2 library
#include <Keyboard.h>
#define BOUNCE_WITH_PROMPT_DETECTION
#include <Bounce2.h>
// Debounce interval and instantiate Bounce objects
#define MILLIDEBOUNCE 5
Bounce k1 = Bounce();
Bounce k2 = Bounce();
// Defining keys and leds integers
int Key1 = 2;
int Key2 = 4;
int Led1 = 3;
int Led2 = 5;
int Macro1 = 6;
int Macro2 = 7;
int Macro3 = 8;
//  _________________________________SETUP BELOW_________________________________
void setup() {
  // Attaching 2 pins to debounce library
  k1.attach(Key1, INPUT_PULLUP);
  k1.interval(MILLIDEBOUNCE);
  k2.attach(Key1, INPUT_PULLUP);
  k2.interval(MILLIDEBOUNCE);
  
  // Giving input_pullup for Macros
  pinMode(Macro1, INPUT_PULLUP);
  pinMode(Macro2, INPUT_PULLUP);
  pinMode(Macro3, INPUT_PULLUP);
  
  // Setting leds as outputs
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);

  //Initiating keyboard library
  Keyboard.begin();
}
// _________________________________KEY PRESSES BELOW_________________________________
void loop() {   
  //Key press "z"
  k1.update();
  if (k1.fell() ) {
    Keyboard.press(115);
    digitalWrite(Led1, HIGH);
    } else if (k1.rose() ) {
    Keyboard.release(170);
    digitalWrite(Led1, LOW);
  }
  //Key press "x"
    k2.update();
  if (k2.fell() ) {
    Keyboard.press(172);
    digitalWrite(Led1, HIGH);
    } else if (k2.rose() ) {
    Keyboard.release(115);
    digitalWrite(Led1, LOW);
  }

  // _________________________________MACRO KEYS BELOW_________________________________
  
  //Macro key press "g"
 if (digitalRead(Macro1) == LOW) {
  Keyboard.press(147);
  } else {
    Keyboard.release(147);
  }

    //Macro key press "a"
 if (digitalRead(Macro2) == LOW) {
  Keyboard.press(141);
  } else {
    Keyboard.release(141);
  }

    //Macro key press "y"
 if (digitalRead(Macro3) == LOW) {
  Keyboard.press(171);
  } else {
    Keyboard.release(171);
  }
}
