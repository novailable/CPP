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
		std::cout << "Invalid arguments!" << std::endl;
		return (0);
	}

	std::string	file_name = argv[1];
	std::string	str1 = argv[2];
	std::string	str2 = argv[3];

	if (str1.empty())
		return (std::cerr << "First string cannot be an empty string!" << std::endl, 1);
	std::ifstream i_file(file_name);
	if (!i_file)
		return (std::cerr << "Error opening '" << file_name << "'!" <<std::endl, 1);

	std::ofstream o_file( file_name + ".replace");
	if (!o_file)
		return (std::cerr << "Error creating '" << file_name + ".replace'!" << std::endl, 1);

    while (std::getline(i_file, content))
    {
        size_t pos = 0;
        while ((pos = content.find(str1, pos)) != std::string::npos)
        {
            content.replace(pos, str1.length(), str2);
            pos += str2.length(); // Move past the replaced text
        }
        result << content << '\n';
    }

    o_file << result.str();
    return 0;
	i_file.close();
	o_file.close();
}