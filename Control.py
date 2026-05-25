import serial
import keyboard

arduino = serial.Serial('COM13', 9600)

keys = {
    "UP": "w",
    "DOWN": "s",
    "LEFT": "a",
    "RIGHT": "d",
    "A": ";",
    "S": "'",
    "Z": "down",
    "X": "up",
    "U": "space",
    "I": "l",
    "O": "h",
    "P": "backspace"
}

current_pressed = set()

while True:

    data = arduino.readline().decode().strip()

    print(data)

    # split support
    # example: UP,A
    active = set(data.split(","))

    # press new keys
    for key in active:
        if key in keys and key not in current_pressed:
            keyboard.press(keys[key])
            current_pressed.add(key)

    # release removed keys
    for key in list(current_pressed):
        if key not in active:
            keyboard.release(keys[key])
            current_pressed.remove(key)