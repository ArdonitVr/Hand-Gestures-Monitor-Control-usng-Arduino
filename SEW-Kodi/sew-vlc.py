import serial                        #Shton Serial Library per komunikim serik
import time                          #Kerkohet per funksionin e voneses
import pyautogui                     #Perdoret per kontrollimin e tastieres dhe miut.

ArduinoSerial = serial.Serial('com3',9600) #Inicializimi i serialit ArduinoSerial
time.sleep(2)                        #prisni 2 sekonda që komunikimi të vendoset

while 1:
    incoming = str (ArduinoSerial.readline()) #lexon të dhënat serike dhe i printon ato si rresht
    print incoming                    # printon të dhënat serike në hyrje
    
    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in incoming:
        pyautogui.hotkey('ctrl', 'left')  

    if 'Forward' in incoming:
        pyautogui.hotkey('ctrl', 'right') 

    if 'Vup' in incoming:
        pyautogui.hotkey('ctrl', 'down')
        

    if 'Vdown' in incoming:
        pyautogui.hotkey('ctrl', 'up')

    incoming = "";                        # pastron të dhënat
    
