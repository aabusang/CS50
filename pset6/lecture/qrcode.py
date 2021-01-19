import os
import qrcode

img = qrcode.make("put video link here")
img.save("qr.png", "PNG")
os.system("open qr.png")