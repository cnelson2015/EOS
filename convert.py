import numpy as np
from PIL import Image

# load the image
img = Image.open("bitmap.png")
pixels = img.load()

###########################################
# convert an RGB array to hex array
###########################################

# array to hold all hex codes
hex_values = []
# for each x pixel in the image
for x in range(img.size[0]):
    arr = []
    # for each y pixel in the image
    for y in range(img.size[1]):
        # convert RGB to hex
        arr.append("%02x%02x%02x" % pixels[x, y])
    # add the hex to the arr
    hex_values.append(arr)

###########################################
# convert a hex array to RGB array
###########################################

rgbArr = np.zeros((img.size[0], img.size[1], 3), 'uint8')
# x only goes to half the image to show proof of concept
for x in range(len(hex_values)//2):
    pix_values = np.array([], 'uint8')
    for y in range(len(hex_values)):
        value = hex_values[x][y]
        # convert hex to RGB tuple
        pix_values = np.append(pix_values,
                               tuple(int(value[i:i+2], 16) for i in (0, 2, 4)))
    pix_values = pix_values.reshape(len(pix_values)//3, 3)
    rgbArr[x] = pix_values

# save the image
img_out = Image.fromarray(rgbArr)
img_out.save("test.jpg")
