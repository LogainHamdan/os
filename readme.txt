Produced by: Logain, Nuha, Samar, and Doaa 
Class: Operating Systems Lab (ECOM4001-4063)

myshell supports the following commands:
    cd    clr      dir    echo  environ
    help  myshell  pause  pwd   quit   exit   cat   ls

-------------------------------------------------------------------------------
How to Run the Shell
-------------------------------------------------------------------------------

To start using our shell, follow these simple steps:

1. Make sure you have GCC and Make installed on your Unix system.

   To install them, run the following command in your terminal:

       sudo apt update
       sudo apt install build-essential

2. Go to the project directory using the terminal.

3. Now simply run:

       make

This will compile the project using the existing Makefile.  
Once compiled, the shell program is ready to use and will work directly.

No need to use any other command.

-------------------------------------------------------------------------------
Help Command
-------------------------------------------------------------------------------

* When you type `help`, a list of supported commands will appear on the screen.

    Example:
        [Abdelrahman@debian] /home/Abdelrahman/ECOM4001/OSproject $ help

-------------------------------------------------------------------------------
ls Command
-------------------------------------------------------------------------------

* `ls` alone: shows files in the current directory  
* `ls .`     : same as above (current directory)  
* `ls ..`    : shows files in the parent directory

    Example:
        [Abdelrahman@debian] /home/Abdelrahman/ECOM4001/OSproject $ ls
        file.bat  makefile  readme  s1  shellfinal.c  shellpro.c

-------------------------------------------------------------------------------
dir Command
-------------------------------------------------------------------------------

* Works just like `ls`:
    - `dir`      → current directory  
    - `dir .`    → current directory  
    - `dir ..`   → parent directory

    Example:
        [Abdelrahman@debian] /home/Abdelrahman/ECOM4001/OSproject $ dir ..
        Lab1011  Lab2  Lab3  Lab4  Lab5  Lab6  Lab8  Lab9  OSproject

-------------------------------------------------------------------------------
echo Command
-------------------------------------------------------------------------------

* `echo <text>`: prints the given text to the screen.

    Example:
        [Abdelrahman@debian] $ echo Thank you Eng
        Thank you Eng

-------------------------------------------------------------------------------
cd Command
-------------------------------------------------------------------------------

* `cd <directory>`: changes your current directory.

    Example:
        [Abdelrahman@debian] $ cd ..
        [Abdelrahman@debian] /home/Abdelrahman/ECOM4001 $

Note: After using `cd`, your terminal path updates to reflect the change.

-------------------------------------------------------------------------------
clr Command
-------------------------------------------------------------------------------

* Clears the terminal screen.

    Usage:
        clr

-------------------------------------------------------------------------------
myshell Command
-------------------------------------------------------------------------------

* Executes commands from a file (e.g., batch file).

    Example:
        myshell ./file.bat

-------------------------------------------------------------------------------
cat Command
-------------------------------------------------------------------------------

* `cat <file>`: displays the contents of the file.  
* If the file does not exist, it will be created.

    Example:
        [Abdelrahman@debian] $ cat OSproject

-------------------------------------------------------------------------------
pwd Command
-------------------------------------------------------------------------------

* Shows the current working directory.

    Example:
        [Abdelrahman@debian] $ pwd
        /home/Abdelrahman/ECOM4001

-------------------------------------------------------------------------------
pause Command
-------------------------------------------------------------------------------

* Stops program execution until the user presses Enter.

    Example:
        [Abdelrahman@debian] $ pause
        Paused  
        Press <Enter> key to continue

-------------------------------------------------------------------------------
environ Command
-------------------------------------------------------------------------------

* Displays a list of all environment variables.

    Usage:
        environ

-------------------------------------------------------------------------------
quit Command
-------------------------------------------------------------------------------

* Exits the shell.

    Example:
        [Abdelrahman@debian] $ quit
        Leaving...

-------------------------------------------------------------------------------
exit Command
-------------------------------------------------------------------------------

* Also exits the shell, same as `quit`.

    Example:
        [Abdelrahman@debian] $ exit
        Leaving...

-------------------------------------------------------------------------------

Enjoy using Simple Shell!  
Developed with by Abdelrahman, Hani, and Karam
