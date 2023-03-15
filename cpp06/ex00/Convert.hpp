#ifndef __CONVERT__HPP
#define __CONVERT__HPP
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

class Convert
{
public:
    std::string type;
    bool impossible;
    bool infi;
    int len;
    int n;
    double d;
    float f;
    char c;
    double precision;

public:
    Convert(void);
    Convert(Convert const &convert);
    Convert &operator=(Convert const &convert);
    std::string getType(void);

    void defineType(std::string line);
    void convert(const char *line);
    void printConverted();
    void printChar();
    void printInt();
    void printFloat();
    void printDouble();
    ~Convert(void) {};
};

#endif
