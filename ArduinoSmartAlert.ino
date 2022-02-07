#define trigPin 7 //TRIG INPUT
#define echoPin 6 //ECHO OUTPUT
#define led 13 //LED BLUE
#define led2 12 //LED BLUE
#define led3 11 //LED YELLOW
#define led4 10 //LED YELLOW
#define led5 9 //LED RED
#define led6 8 //LED RED
#define buzzer 3 //BUZZER

int sound = 150;

void setup() 
{
    Serial.begin (19200); //Opens Serial Port at 19200
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() 
{
    long duration, distance;
    digitalWrite(trigPin, LOW); //Set the trig pin to LOW state
    delayMicroseconds(2); //Halt the program for specified microseconds
    digitalWrite(trigPin, HIGH); //Set the trig pin to HIGH state
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW) ; //Set the trig pin to LOW state
    duration = pulseIn(echoPin, HIGH); //Finding the duration taken by the wave in traveling
    distance = (duration/2) / 29.1; //Finding the distance in cm using the extracted data using formula

    if (distance <= 60) //When distance is 50 - 60,Single LED (0 Red, 0 Green, 1Blue) light up with very low sound alert
    {  system
        digitalWrite(led, HIGH);
        sound = 50;
    }
    else 
    {
        digitalWrite(led,LOW);
    }
    if (distance < 50) //When distance is 40 - 50, 2 LED’s ( 0 Red,0 Green,2 Blue) light up with low sound alert
    { 
        digitalWrite(led2, HIGH);
        sound = 200;
    }
    else 
    {
        digitalWrite(led2, LOW);
    }
    if (distance < 40) //When distance is 30 - 40, 3 LED’s (0 Red,1 Green,2 Blue) light up with medium-low sound alert
    { 
        digitalWrite(led3, HIGH);
        sound = 350;
    }
    else 
    {
        digitalWrite(led3, LOW);
    }
    if (distance < 30) //When distance is 20 - 30, 4 LED’s (0 Red,2 Green,2 Blue) light up with medium sound alert
    { 
        digitalWrite(led4, HIGH);
        sound = 500;
    }
    else 
    {
        digitalWrite(led4,LOW);
    }
    if (distance < 20) //When distance is 10 - 20, 5 LED’s (1 Red,2 Green,2 Blue) light up with high-medium sound alert
    { 
        digitalWrite(led5, HIGH);
        sound = 650;
    }
    else 
    {
        digitalWrite(led5,LOW);
    }
    if (distance < 10) //When distance is 0 - 10, All 6 LED’s (2 Red,2 Green,2 Blue) light up with high sound alert
    { 
        digitalWrite(led6, HIGH);
        sound = 800;
    }
    else 
    {
        digitalWrite(led6,LOW);
    }
    if (distance > 60 || distance <= 0) //When distance is > 60 (No Target), Intermediate LED’s flash with a short recurring sound alert
    { 
        //LED animation for showing no target
        digitalWrite(led,HIGH);
        digitalWrite(led3,HIGH);
        digitalWrite(led5,HIGH);
        delay(250);
        digitalWrite (led,LOW);
        digitalWrite(led3,LOW); 
        digitalWrite(led5,LOW);
        delay(300);
        digitalWrite(led2,HIGH);
        digitalWrite(led4,HIGH);
        digitalWrite(led6,HIGH);
        Serial.println("\nSNAP :( Target is Out Of Range \n");
        tone(buzzer,10500);
    }
    else 
    {
        Serial.print("Target is now ");
        Serial.print(distance);
        Serial.println(" cm away :)\n");
        tone(buzzer, sound); //Trigger the sound
    }
    delay(333); //Time to wait until next refresh of data
}