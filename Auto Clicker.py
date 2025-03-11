import keyboard, time
from pynput.mouse import Controller, Button

mouse, clicking = Controller(), False

def toggle_clicking():
    global clicking
    clicking = not clicking

keyboard.add_hotkey('`', toggle_clicking)

while True:
    if clicking:
        mouse.click(Button.left)
        time.sleep(0.001)
    else:
        time.sleep(0.1)
