#include <iostream>
#include <string>

// convert lowercase to uppercase
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; argv[i]; i++)
        {
            std::string str = argv[i];
            for (int count = 0; str[count]; count++)
                str[count] = std::toupper(str[count]);
            std::cout << str;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}