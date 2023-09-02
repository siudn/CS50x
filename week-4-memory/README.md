# Week 4 - Memory
## Topics
This week introduced memory management and usage, covering topics such as pointers, pointer arithmetic, different kinds of syntax used to reference addresses, and buffer overflows. We gained a conceptual understanding of how and where different values are stored in memory, through the lens of C.

## Programs
recover - recovers lost images/files from a damaged or corrupted file in the same directory. To use, compile and run `./recover "filename"` (no quotes, input your file).

filter - applies filters to a given image and produces a new image with the selected filer. To use, compile and run `./filter -g|-s|-r|-b "bmp.h" "outfile"`. -g for grayscale, -s for sepia, -r to reflect horizontally, -b for blur. Replace bmp.h with desired image file, replace outfile with the name of the filtered image you would like to produce.

smiley - in an image of a smiley face, changes the pixels which actually make the face to a different color.