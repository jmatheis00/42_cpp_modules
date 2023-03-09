/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:45 by jmatheis          #+#    #+#             */
/*   Updated: 2023/03/09 17:45:47 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void fill_newfile(std::ifstream& infile, char *argv[])
{
	std::string outfile = argv[1];

	outfile.append(".replace");
	std::ofstream newfile(outfile);
	std::string buff;
	while(getline(infile, buff))
	{
		if (!buff.compare(argv[2]))
			newfile << argv[3];
		else
			newfile << buff;
		if (!infile.eof())
			newfile << std::endl;
	}
	newfile.close();
}

// arguments: ./ex04 "filename" "string1" "string2"
// copy filename content into a new file
// replace every occurence of s1 with s2
// ifstream ->reads from a file
// ofstream -> creates and writes to a file;
int main(int argc, char *argv[])
{
    if (argc == 4)
    {
		std::ifstream infile;
        infile.open(argv[1]);
		if (infile.is_open())
		{
			fill_newfile(infile, argv);
			infile.close();
		}
		else
			std::cout << "problem with opening infile" << std::endl;
    }
    else
        std::cout << "wrong number of arguments" << std::endl;
    return (0);
}