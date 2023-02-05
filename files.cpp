//
// Created by Stephane Walter on 2/3/23.
//
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <deque>
#include <list>
#include <map>
#include "includes/map.hpp"
#include <stack>
#include "includes/stack.hpp"
#include <vector>
#include "includes/vector.hpp"
//#include <set>
//#include "includes/set.hpp"
typedef struct s_data
{
	std::fstream	file;
	std::streambuf	*buffer_cout;
	std::streambuf	*buffer_file;
}				t_data;

void	close_file(t_data *data)
{
	std::cout.rdbuf(data->buffer_cout);
	data->file.close();
}

s_data	*open_file(t_data *data, std::string path)
{
	data->file.open(path, std::iostream::out);
	data->buffer_cout = std::cout.rdbuf();
	data->buffer_file = data->file.rdbuf();
	std::cout.rdbuf(data->buffer_file);
	return (data);
}