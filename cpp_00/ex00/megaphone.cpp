#include <iostream>

using namespace std;

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

int main(int argc, char **argv)
{
    int i = 0;
    int len = 0;
    if (argc > 1)
    {
        while (i++ < argc - 1)
        {
            int count = -1;
            len = ft_strlen(argv[i]);
            while (count++ < len)
            {
                if (argv[i][count] >= 'a' || argv[i][count] >= 'z')
                    argv[i][count] -= 32;
                cout << argv[i][count];
            }
        }
        cout << endl;
    }
    else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    return (0);
}