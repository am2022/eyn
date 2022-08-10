## eyn is an encryption software.
### you can use eyn to encrypt your files.

## how to install eyn:
* first you should clone the project
* you should install gcc
* and then use gcc eyn.c -std=c99 -o eyn for execute the code, and for windows use gcc eyn.c -std=c99 -o eyn.exe command.

## how to use argv in eyn:
* first you should run program by ./eyn (or each file name that you save).
* after that in the same line for enter file name that you want to encrypt you should use -fname_in and after that a space and then enter your file name.
* in the same line enter -fname_out is for enter output file name, after that space and then enter your output file name.
* enter -key1 and after the space and then enter the key1(password1) that you want
* enter -key2 and after the space and then enter the key2(password2) that you want
* example: ./eyn -fname_in file.txt -fname_out file.txt -key1 10 -key2 20
