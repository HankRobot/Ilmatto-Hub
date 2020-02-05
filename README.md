# Ilmatto Hub
This project is focused on documenting important tutorials of Embedded C projects and will be mostlikely used as a dumpster most of the time.

# About Folders
1. ECSPOV is POV(Open folder README for more details) by University of Southampton, I do not own it and I only use it for my own personal interests.
2. tests contains code for testing your Ilmatto hardware. masterpiece.hex tests your LCD to play pacman and prog.c checks your own board green LED.
3. Loops folder is my own code, please follow below instructions for testing.

# To upload code
1. To generate elf:
    avr-gcc -mmcu=atmega644p -DF_CPU=12000000 -Wall -Os prog.c -o prog.elf

2. To generate hex:
    avr-objcopy -O ihex prog.elf prog.hex

3. To upload (Go into bootloading mode first):
    avrdude -c usbasp -p m644p -U flash:w:prog.hex

4. If the following error occurs:
1) avrdude.exe: error: could not find USB device "USBasp" with vid=0x16c0 pid=0x5dc
a) https://rlogiacco.wordpress.com/2016/09/01/usbasp-windows-10/