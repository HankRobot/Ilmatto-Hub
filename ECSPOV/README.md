# ECSPOV
This project is by University of Southampton and is used to demonstrate Persistence of Vision using the Ilmatto Controller. You would need 8 LEDs to demonstrate this project.

# To upload code
1. To generate elf:
    avr-gcc -mmcu=atmega644p -DF_CPU=12000000 -Wall -Os ecspov.c -o ecspov.elf

2. To generate hex:
    avr-objcopy -O ihex ecspov.elf ecspov.hex

3. To upload (Go into bootloading mode first):
    avrdude -c usbasp -p m644p -U flash:w:ecspov.hex

4. If the following error occurs:
1) avrdude.exe: error: could not find USB device "USBasp" with vid=0x16c0 pid=0x5dc
a) https://rlogiacco.wordpress.com/2016/09/01/usbasp-windows-10/

# How to play with this project
1. To edit code, open ecspov.c and change the variable message from "Hank" into any word you desire.
2. Follow the "To upload code" instructions, and shake the Ilmatto once its compiled, you should see the letters flash in front of the LEDs.