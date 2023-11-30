#include "CommandReader.hpp"
//#include <termios.h>
//#include <unistd.h>
#include <ncurses.h>
#include <iostream>


char CommandReader::readCommand() 
{
   // Чтение символа из стандартного ввода
   char sym;
   initscr();
   nocbreak();
   noecho();
   timeout(100);
   sym = getch();
   cbreak();
   echo();
   endwin();

   return sym;
}