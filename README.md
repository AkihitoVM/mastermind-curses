# Mastermind game in C language with curses library

---
## Requirements

For development, you will need `build-essential, libncurses` dependencies installed in your environement.

### Dependencies installation
    $ sudo apt update
    $ sudo apt upgrade
    $ sudo apt install build-essential make gcc libncurses5-dev libncursesw5-dev




## Install

    $ git clone https://github.com/AkihitoVM/mastermind-curses.git
    $ cd mastermind-curses
    $ make all
        gcc -c -std=c11 -Werror -Wall -lm main.c
        gcc -c -std=c11 -Werror -Wall -lm program.c
        gcc -c -std=c11 -Werror -Wall -lm ui.c 
        gcc main.o program.o ui.o -o game -lncurses

## Running the project

    $ ./game
