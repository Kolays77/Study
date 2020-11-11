import sys, os
from PIL import Image
import pyheif

def convert_heic_to_jpg(heic_file):
    heif_file = pyheif.read(heic_file)
    image = Image.frombytes(
        heif_file.mode, 
        heif_file.size, 
        heif_file.data,
        "raw",
        heif_file.mode,
        heif_file.stride,
    )
    return image


def heic_to_jpg(target):
    image_list = [convert_heic_to_jpg(x) for x in target]    
    image_list[0].save("output.pdf", save_all=True, append_images=image_list[1:])


def main():
    target = [a for a in os.listdir() if a.endswith(".HEIC")] 
    heic_to_jpg(target)

main()