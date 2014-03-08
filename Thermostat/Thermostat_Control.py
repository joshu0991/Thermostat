import serial
from time import sleep


class Temperature_Driver:
    
    def __init__(self):
        return
        
    def read_optimal_temp(self):    
        ser = serial.Serial('COM3', 9600) # Establish the connection on a specific port
        while True:
            optimal_temp_in = ser.readline()
            newOTemp = optimal_temp_in.decode('utf-8')
            oTemp = newOTemp.translate(newOTemp.maketrans("\n\t\r", "   "))
            print(oTemp)
            
def main():
    driver = Temperature_Driver()
    driver.read_optimal_temp()
if __name__=='__main__':main()                