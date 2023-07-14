import keyboard
import serial

car = serial.Serial("COM3", 9600)

while True:
    if keyboard.is_pressed("w"):
        car.write(b'f')
    elif keyboard.is_pressed("s"):
        car.write(b'b')
    elif keyboard.is_pressed("a"):
        car.write(b'l')
    elif keyboard.is_pressed("d"):
        car.write(b'r')

    # Check if all keys are released
    if not keyboard.is_pressed("w") and not keyboard.is_pressed("s") and not keyboard.is_pressed("a") and not keyboard.is_pressed("d"):
        car.write(b's')