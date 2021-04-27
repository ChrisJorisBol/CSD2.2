#define HI_Z 2

/*
 * Read a 3-state pin.
 * Put a 10 kOhm resistor between the output and input pins.
 */
int read3state(int pin)
{
    int reading1 = digitalRead(pin);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, !reading1);
    pinMode(pin, INPUT);
    int reading2 = digitalRead(pin);
    if (reading1 == reading2)
        return reading1;
    else
        return HI_Z;
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println(read3state(2));
}
