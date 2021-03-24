#ifndef UTILS_H
#define UTILS_H

// Terminal ANSI color codes
#define RESET "\033[0m"
#define BRIGHTRED "\033[1;31m"  
#define BRIGHTYELLOW "\033[1;33m"  
#define BOLDYELLOW "\033[33m" 
#define BRIGHTCYAN "\033[1;36m" 
#define BRIGHTGREEN "\033[1;32m"

namespace Utils
{
    int getch();
}

#endif