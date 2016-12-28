#ifndef FileLocker_H
#define FileLocker_H

#include <sys/types.h>
#include <sys/file.h>
#include <exception>
#include <string>


class LockedException {};

struct FileLocker {
	std::string file_name;
	int fd;
	FileLocker(std::string fn) throw (LockedException) : file_name(fn){
		fd = open(file_name.c_str(), O_RDWR | O_CREAT, S_IRWXU);
		//try to lock file
		int lock = flock(fd, LOCK_EX | LOCK_NB);
		if (lock != 0) { throw LockedException(); }
	}
	~FileLocker() { flock(fd, LOCK_UN); }
};

#endif
