/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:45 by jmatheis          #+#    #+#             */
/*   Updated: 2023/04/12 14:35:04 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// find() returns std::string::npos if nothing found
void myreplace(std::ifstream& infile, char *argv[])
{
	std::string outfile = argv[1];
	std::string	old_str = argv[2];
	std::string buff;

	outfile.append(".replace");
	std::ofstream newfile(outfile);
	while(getline(infile, buff))
	{
		std::size_t found_pos;
		while(buff.find(argv[2]) != std::string::npos)
		{
			found_pos = buff.find(old_str);
			buff.erase(found_pos, old_str.length());
			buff.insert(found_pos, argv[3]);
		}
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
			myreplace(infile, argv);
			infile.close();
		}
		else
			std::cout << "problem with opening infile" << std::endl;
    }
    else
        std::cout << "wrong number of arguments" << std::endl;
    return (0);
}