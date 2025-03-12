import keyboard, time
from pynput.mouse import Controller, Button

mouse, clicking = Controller(), False

while True:
    if keyboard.is_pressed('`'):
        clicking = not clicking
        time.sleep(0.2)

    if clicking:
        mouse.click(Button.left)
        time.sleep(0.001)
    else:
        time.sleep(0.1)
