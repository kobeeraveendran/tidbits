import pyautogui
import time
import argparse

parser = argparse.ArgumentParser()

parser.add_argument('--num_clicks', type = int, default = 5, help = "Number of times you'd like the left-mouse button to be pressed")

args = parser.parse_args()
num_clicks = args.num_clicks

time.sleep(5)
mouse_pos = pyautogui.position()

pyautogui.click(x = mouse_pos[0], y = mouse_pos[1], clicks = num_clicks)