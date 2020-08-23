# Refreshable-Braille-Display

ECE Dept project in an electronic device capable of reading text from an app, and translating it from English characters to a Braille pattern which can be easily felt by a blind user.

*Note: bluetooth code is for app named 'Braille App' for other apps modify it according to the output of the said app*

![gif of model](Refreshable_Braille_Display.gif)

## Softwares Required
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Braille App](https://drive.google.com/file/d/1J4qEIaJ0qcIv7b7UjU67EF6Y-HYO6rsn/view?usp=drivesdk)
## Code

- [braille_bluetooth](https://github.com/Shrutii07/Refreshable-braille-display/blob/master/braille_bluetooth.ino) : The text is received from a mobile app via HC05 then each character is cross-referenced with its equivalent Braille pattern from a table. The resulting pattern is  sent to the output to actuate the braille pin and the process repeated over again for the next characters. 
- [braille](https://github.com/Shrutii07/Refreshable-braille-display/blob/master/braille.ino) : Code to convert ASCII to Braille language(Capital Characters only).
- [braille_advance](https://github.com/Shrutii07/Refreshable-braille-display/blob/master/braille_advance.ino) : Code to convert ASCII to Braille Language (Capital & small characters).
- [braille_servo](https://github.com/Shrutii07/Refreshable-braille-display/blob/master/braille_servo.ino) : Code to convert ASCII to Braille for servo motors.

## Video
Video for the project : [Video](https://youtu.be/7I6bJF0T2Q0)
## Report
Report for the project : [Report](https://docs.google.com/document/d/1jFBnajXjlG_So482YT4tQGygz_mABlTJZRvJyg4ndZo/edit?usp=sharing)
