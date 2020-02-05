//
// SerialSend.c - This program sends text via serial port
// Written by Ted Burke - last updated 6-12-2011
//
// Command line arguments are used to specify the text
// to send and the serial port to use. The baud rate used
// is currently always 38400 baud. The text cannot contain
// any spaces.
//
//      argv[1] = device name
//      argv[2] = text to send
//
// To compile with MinGW:
//
//      gcc -o SerialSend.exe SerialSend.c
//
// To compile with cl, the Microsoft compiler:
//
//      cl SerialSend.c
//
// To run (this example sends the characters "S365" via COM1):
//
//      SerialSend COM3 5
//
// References:
//
//  Robertson Bayer, "Windows Serial Port Programming", March 30, 2008
//  (I used code from Bayer's serial port tutorial as my starting point)
//
 
#include <windows.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    // Declare variables and structures
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};
    DWORD dwBytesWritten = 0;
 
    char dev_name[MAX_PATH];
    char text_to_send[MAX_PATH];
 
    // Parse command line arguments
    if (argc < 3)
    {
        fprintf(stderr, "Usage:\n\n\tSerialSend DEVICE_NAME TEXT_TO_SEND\n");
        return 1;
    }
    strcpy(dev_name, argv[1]);
    strcpy(text_to_send, argv[2]);
 
    // Open the specified serial port (first command line argument)
    fprintf(stderr, "Opening serial port %s...", dev_name);
    hSerial = CreateFile(argv[1], GENERIC_READ|GENERIC_WRITE, 0, 0,
                            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial==INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    fprintf(stderr, "OK\n");
 
    // Set device parameters (9600 baud, 1 start bit,
    // 1 stop bit, no parity)
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (GetCommState(hSerial, &dcbSerialParams) == 0)
    {
        fprintf(stderr, "Error getting device state\n");
        CloseHandle(hSerial);
        return 1;
    }
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if(SetCommState(hSerial, &dcbSerialParams) == 0)
    {
        fprintf(stderr, "Error setting device parameters\n");
        CloseHandle(hSerial);
        return 1;
    }
 
    // Set COM port timeout settings
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if(SetCommTimeouts(hSerial, &timeouts) == 0)
    {
        fprintf(stderr, "Error setting timeouts\n");
        CloseHandle(hSerial);
        return 1;
    }
 
    // Send specified text (second command line argument;
    // cannot contain spaces)
    fprintf(stderr, "Sending text: %s\n", text_to_send);
    if(!WriteFile(hSerial, text_to_send, strlen(text_to_send),
                    &dwBytesWritten, NULL))
    {
        fprintf(stderr, "Error writing text to %s\n", dev_name);
    }
    else
    {
        fprintf(stderr, "%d bytes written to %s\n",
                dwBytesWritten, dev_name);
    }
 
    // Close serial port
    
    fprintf(stderr, "Closing serial port...");
    if (CloseHandle(hSerial) == 0)
    {
        fprintf(stderr, "Error\n", dev_name);
        return 1;
    }
    fprintf(stderr, "OK\n");
    
    // exit normally
    
    return 0;
}