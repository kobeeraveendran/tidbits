import pyautogui
import time

i = 1

while True:

    curr_mouse_x, curr_mouse_y = pyautogui.position()
    x_offset = 5 if i % 2 else -5

    pyautogui.moveTo(curr_mouse_x + x_offset, curr_mouse_y)

    i += 1
    time.sleep(300)