#include "TFS.h"

size_t FileSystem::numDisks() const
{
	return 0;
}

//FileSystem tfs;

FileSystem &tfs()
{
	static FileSystem fs;
	return fs;
}