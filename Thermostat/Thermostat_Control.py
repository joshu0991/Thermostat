import serial
#from tkinter import *
from time import sleep

ser = serial.Serial('COM3', 9600)
sleep(2)
class Temperature_Driver:
    def __init__(self):
        return
        
    def read_optimal_temp(self): 
        global ser
        while True:
            optimal_temp_in = ser.readline()
            newOTemp = optimal_temp_in.decode('utf-8')
            oTemp = newOTemp.translate(newOTemp.maketrans("\n\t\r", "   "))
            print(oTemp)
    #Not needed do thermostat controlling in arduino
    def turn_on_Heat(self):
        global ser
        if ser.closed:
            ser = serial.Serial('COM3', 9600)
            sleep(2)
            ser.write(b'1')   
    #Not needed do thermostat controlling in arduino
    def turn_on_ac(self):
        global ser
        ser.write(b'2')        

def main():
    driver = Temperature_Driver()
    driver.read_optimal_temp()
    driver.turn_on_Heat()
    sleep(5000)
    driver.turn_on_ac()
if __name__=='__main__':main()                