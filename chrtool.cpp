#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string_view>

std::string charToBin(unsigned char c)
{
    std::string s;
    s.reserve(8);
    int i;
    unsigned char c2;

    for (i = 0; i < 8; i++)
    {
        c2 = 1;
        c2 <<= (7 - i);

        if ((c & c2) > 0)
        {
            s.append("1");
        }
        else
        {
            s.append("0");
        }
    }

    return s;
}

void printbuf(char *buffer, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (i % 8 == 0)
        {
            printf("\n");
        }

        printf(".byte %%%s\n", charToBin(buffer[i]).c_str());
    }
}

void loadfile(std::string_view filename)
{
    std::fstream fstrim(filename.data(), std::_Ios_Openmode::_S_in);
    char buffer[1024];
    size_t len;
    printf(".segment \"CHARS\"\n");
    while ((len = fstrim.readsome(buffer, 1024)) == 1024)
    {
        printbuf(buffer, len);
    }

    if (len > 0)
    {
        printbuf(buffer, len);
    }
}

int main(int argc, char **argv)
{
    std::string filename;
    if (argc == 2)
    {
        filename = argv[1];
    }
    else
    {
        std::cout << "err\n";
        return 1;
    }

    loadfile(filename);
}
