Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

void setup()
{
    Particle.function("push", push);  // create a function called "push" that
                                      // can be called from the cloud
                                      // connect it to the gong function below

    myservo.attach(D0);   // attach the servo on the D0 pin to the servo object
    myservo.write(145);
    pinMode(D7, OUTPUT);  // set D7 as an output so we can flash the onboard LED
}

int push(String command)   // when "push" is called from the cloud, it will
{                          // be accompanied by a string.
    myservo.write(0);      // move servo to 0°
    digitalWrite(D7, HIGH); // flash the LED (as an indicator)
    delay(1000);
    myservo.write(145);     // move servo to 145°
    digitalWrite(D7, LOW);  // turn off LED
    return 1;               // return a status of "1"
}

void loop()
{
  // empty because we call the push function via the cloud
}
