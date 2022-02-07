# **Smart Intruder Alert System that comprises a combo of HC-SRO4 Ultrasonic Sensor, a Buzzer, LED's & a Arduino Uno**

## Component List 

```
Breadboard 1
Arduino Uno 1
Jumper Wire’s 15
Colored LED 6
USB Data Cable for Arduino 1
HC-SR04 Ultrasonic Sensor 1
9V Battery 1
Buzzer 1
330 ohm Resistor’s 7
```

## Circuit Diagram

![Circuit](https://user-images.githubusercontent.com/33223665/152725931-343f5f06-a1f7-4781-aeaa-592e3322d9e0.jpg)

## Working 

*Once the code is uploaded ,the sensor will start to read the distance and the appropriate signal/alert combination of buzzer & LED’s are applied. 
If we have connected to the arduino using a serial cable then, the distance is showed up on the serial monitor on the computer .
The code will first make the HC-SR04 to send a wave of ultrasound which will travel and reflect back to the sensor after interacting with any body. The sensor will also start a timer which measure’s how much time the wave took back and forth.
This duration will be converted into distance, and the code will pass it on to our function which control’s the alert system which comprises of LED's and Buzzers.*

*According to the distance the relevant alert system mentioned below is triggered :*

![TriggerTable](https://user-images.githubusercontent.com/33223665/152726286-ac1ddc4f-97e1-4db8-816b-8ca7c351f76a.png)

*Our code is configured to trigger the HC-SR04 3 times/second so that the user can always get updated reading's.*

## Use Case

This setup can be easily applied into :


1. Smart Guide Sticks for the blind/elderly - Signal system lets the user's know of any obstucles in their way
2. Personal Radar - Alert system that can help user's from keeping belongings safe
3. Vehicle Smart Sensor's - Can help the driver to park their vehicles more efficiently
