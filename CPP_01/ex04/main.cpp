#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	std::string	content;
	std::ostringstream result;

	if (argc != 4)
	{
		std::cout << "Invalid arguments!\n"
		<< "Usage : ./L_sed file str1 str2" << std::endl;
		return (0);
	}

	std::string	file_name = argv[1];
	std::string	str1 = argv[2];
	std::string	str2 = argv[3];

	if (str1.empty())
		return (std::cerr << "First string cannot be an empty string!" << std::endl, 1);
	
	std::ifstream i_file(file_name.c_str());
	if (!i_file)
		return (std::cerr << "Error opening '" << file_name << "'!" <<std::endl, 1);

	std::ofstream o_file((file_name + ".replace").c_str());
	if (!o_file)
		return (std::cerr << "Error creating '" << file_name + ".replace'!" << std::endl, 1);

	while (std::getline(i_file, content))
	{
		size_t pos = 0;
		while ((pos = content.find(str1, pos)) != std::string::npos)
		{
            content = content.substr(0, pos) + str2 + content.substr(pos + str1.length());
			pos += str2.length();
		}
		result << content << '\n';
	}

	o_file << result.str();
	return 0;
	i_file.close();
	o_file.close();
}