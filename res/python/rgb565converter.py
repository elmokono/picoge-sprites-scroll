# rgb565converter.py

import sys
import os

from PIL import Image
from PIL import ImageDraw
import struct

isSWAP = False
#isSWAP = True

def convert_to_c(filename, var_name, src_x, src_y, src_w, src_h):

    try:
        im=Image.open(filename)
        #print ("/* Image Width:%d Height:%d */" % (im.size[0], im.size[1]))
    except:
        print ("Fail to open png file ", filename)
        sys.exit(0)

    image_height = im.size[1]
    image_width = im.size[0]

    print ('unsigned short '+var_name+'[] PROGMEM = {', end='')

    pix = im.load()  #load pixel array
    for h in range(image_height):
        if (h >= src_y and h < src_y + src_h):
            for w in range(image_width):
                if (w >= src_x and w < src_x + src_w):
                    if ((h * 16 + w) % 16 == 0):
                        print (" ")
                        print ("\t\t", end = '')

                    if w < im.size[0]:
                        R=pix[w,h][0]>>3
                        G=pix[w,h][1]>>2
                        B=pix[w,h][2]>>3

                        rgb = (R<<11) | (G<<5) | B

                        if (isSWAP == True):
                            swap_string_low = rgb >> 8
                            swap_string_high = (rgb & 0x00FF) << 8
                            swap_string = swap_string_low | swap_string_high
                            print ("0x%04x," %(swap_string), end = '')
                        else:
                            print ("0x%04x," %(rgb), end = '')
                    else:
                        rgb = 0
            #
    print ("};")
