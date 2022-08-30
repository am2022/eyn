## eyn is an encryption software.
### you can use eyn to encrypt your files.

## how to install eyn:
* first you should clone the project
* you should install gcc
* and then use gcc eyn.c -std=c11 -o eyn for execute the code, and for windows use gcc eyn.c -std=c99 -o eyn.exe command.

## how to use argv in eyn:
* first you should run program by ./eyn (or each file name that you save).
* after that in the same line for enter file name that you want to encrypt you should use -fname_in or -i and after that a space and then enter your file name.
* in the same line enter -fname_out or -o is for enter output file name, after that space and then enter your output file name.
* enter -key1 or -k1 and after the space and then enter the key1(password1) that you want
* enter -key2 or -k2 and after the space and then enter the key2(password2) that you want
* example: ./eyn -fname_in file.txt -fname_out file.txt -key1 10 -key2 20
* and for help you can use --help or -help or -h command for get help for argv part

## how to use argv for save passwords in eyn:
* you can use -txt_o and put the name of file that you want to see the output in txt format, that will give you your password that you enter for encryption.
* for html format you can use -html_o and the file name.
* and for md(markdown) format you can use -md_o and after the file name.
* example: ./eyn -fname_in file.txt -fname_out file.txt -key1 10 -key2 20 -html_o h.html -md_o md.md -txt_o txt.txt
* you can use -key command to save password in key format, and another time you can import it to the program.
