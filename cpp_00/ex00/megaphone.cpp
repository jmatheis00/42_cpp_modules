#include <iostream>
#include <string>

// convert lowercase to uppercase
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int count = 0; argv[i][count]; count++)
                argv[i][count] = std::toupper(argv[i][count]);
            std::cout << argv[i];
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}