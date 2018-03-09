enum button_state {
   none,
   one,
   two, 
   three, 
   four
};

#define ARRAYSIZE 4
String antenna[ARRAYSIZE] = { "Antenna  1", "Antenna 2", "Antenna 3", "Antenna 4" };

pin_base = 29; // outputs will start at Pin 30
button_base = 13; // inputs will start at Pin 14

button_state new_pressed;
button_state last_pressed;

setup()	{
   // set up all the things
   last_pressed = none;
   for (button_state b = one; b < 5; b++)  {
       pinMode(button_base + b, INPUT_PULLUP);
       pinMode(pin_base + b, OUTPUT); 
   }
}

loop() {
    new_pressed = button_pressed();
    if (new_pressed != none) {   // a button has been pressed
        if (last_pressed != new_pressed)  {    // and it is a differnt button from previously
            last_pressed = new_pressed;
            switch_antenna(new_pressed);       
         }
    }
    // other things go here...
}

button_state button_pressed()  {
    for (button_state b = one; b < 5; b++)  {
        if (digitalRead(button_base + b) == HIGH;
            return b;
    }
    return none;
}


void switch_antenna(button_state b)	{
    // set the pin associated with the pressed button to HIGH, all others to LOW
    b==one?digitalWrite(pin_base + b, HIGH):digitalWrite(pin_base + b, LOW);
    b==two?digitalWrite(pin_base + b, HIGH):digitalWrite(pin_base + b, LOW);
    b==three?digitalWrite(pin_base + b, HIGH):digitalWrite(pin_base + b, LOW);
    b==four?digitalWrite(pin_base + b, HIGH):digitalWrite(pin_base + b, LOW);
    lcd.print(amtenna[b+1]);
}
   
    
  
