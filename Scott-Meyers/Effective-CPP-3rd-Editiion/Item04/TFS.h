#ifndef TFS_H
#define TFS_H

#include <iostream>

class FileSystem
{
public:
	FileSystem()
	{
		std::cout << "fs\n";
	}

	size_t numDisks() const;
};

//extern FileSystem tfs;

FileSystem &tfs();

#endif

