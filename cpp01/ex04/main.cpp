#include <iostream>
#include <fstream>

std::string	replace_mine(std::string line, std::string s1, std::string s2)
{
	int	first = line.find(s1);
	while (first != -1)
	{
		line.erase(first, s1.length());
		line.insert(first, s2);
		first = line.find(s1, first);
	}
	return (line);
}

int main(int ac, char **av)
{
	
	std::string line;
	
	std::ifstream f_in(av[1]);
	if (ac != 4)
	{
		std::cout << "Error Args\n";
		return (0);
	}
	if (f_in.is_open())
	{
		std::string name(av[1]);
		name.append(".replace");
		std::ofstream f_out(name.c_str());
		while (getline(f_in, line))
		{
			line = replace_mine(line, av[2], av[3]);
			f_out << line;
			if (!f_in.eof())
				f_out << std::endl;
		}
		f_out.close();
		f_in.close();
	}
	else
		std::cout << "File Error!! " << std::endl;
}
