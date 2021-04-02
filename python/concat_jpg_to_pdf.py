import sys, os
from PIL import Image


def main():
    files = [a for a in os.listdir(sys.argv[1]) if a.endswith(".jpg")] 
    files.sort()
    image_list = [Image.open(sys.argv[1] + fl) for fl in files]
    image_list[0].save("output.pdf", save_all=True, append_images=image_list[1:])

