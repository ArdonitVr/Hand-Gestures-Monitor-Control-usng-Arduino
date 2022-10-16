import serial #Serial imported for Serial communication
import time #Required to use delay functions
import pyautogui

ArduinoSerial = serial.Serial('com3',9600) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 seconds for the communication to get established

while 1:
    incoming = str (ArduinoSerial.readline()) #read the serial data and print it as line
    print incoming
    
  

    if 'Forward' in incoming:
        pyautogui.hotkey('ctrl', 'pgup') 

    if 'Vup' in incoming:
         pyautogui.scroll(100)
        

    if 'Vdown' in incoming:
        pyautogui.scroll(-100) 

    incoming = "";
    
