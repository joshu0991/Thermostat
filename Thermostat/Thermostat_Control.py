import serial
from threading import Thread
from tkinter import *
from time import sleep
import sys

################################################################################################################

try:
    ser = serial.Serial('COM4', 9600)
    sleep(2)
except:
    ser.close()
    ser = serial.Serial('COM4', 9600)
    sleep(2)
    
##################################################################################################################

class Temperature_Driver:
    
##################################################################################################################    
    
    def __init__(self, master=None):
        master.geometry('600x350+400+150')
        frame = Frame(master)
        frame.pack()
        self.ud_temp = StringVar()
        self.m_temp = StringVar()
        Label(frame, textvariable=self.m_temp, font=('Helvetica', 40)).grid(row=2, column=0)
        Label(frame, textvariable=self.ud_temp, font=('Helvetica', 40)).grid(row=4, column=0)
        
##################################################################################################################    
    
    def read_temp(self): 
        global ser
        counter = 0
        while True:
            optimal_temp_in = ser.readline()
            newOTemp = optimal_temp_in.decode('utf-8')
            oTemp = newOTemp.translate(newOTemp.maketrans("\n\t\r", "   ")) 
            
            if counter == 0:
                self.ud_temp.set('Set Temperature\n ' + str(oTemp) + ' F')
                counter += 1 
            else:
                farenheit = self.cal_farenheit(oTemp)
                temp = ('Measured Temperature\n ' + str(oTemp) + 'C' + '\n'  + str(farenheit) + '  F' )
                self.m_temp.set(temp)
                counter -= 1
                
##################################################################################################################                
                
    def cal_farenheit(self, valC):
        valC = float(valC)
        farenheit = ((valC * 1.8) + 32)
        faren = str(farenheit)
        faren = faren[0:5]
        return faren
    
#######################################################################################################################    
    
def main():
    root = Tk()
    root.wm_title('Thermostat')
    driver = Temperature_Driver(root)
    Thread(target=driver.read_temp).start()
    root.mainloop()
    sys.exit()
    if ser.isOpen():
        ser.close()
if __name__=='__main__':main()                
