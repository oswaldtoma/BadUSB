#ifndef _ISDFS_h
#define _ISDFS_h

#include <cstddef>
#include <cstdint>

class ISDFS
{
public:
	//FS
	virtual File open(const char* path, const char* mode = "r") = 0;
	virtual File open(const String& path, const char* mode = "r") = 0;

	virtual bool exists(const char* path) = 0;
	virtual bool exists(const String& path) = 0;

	virtual bool remove(const char* path) = 0;
	virtual bool remove(const String& path) = 0;
	
	virtual bool rename(const char* pathFrom, const char* pathTo) = 0;
	virtual bool rename(const String& pathFrom, const String& pathTo) = 0;

	virtual bool mkdir(const char* path) = 0;
	virtual bool mkdir(const String& path) = 0;

	virtual bool rmdir(const char* path) = 0;
	virtual bool rmdir(const String& path) = 0;

	//SDFS
	virtual uint64_t cardSize() = 0;
	virtual uint64_t totalBytes() = 0;
	virtual uint64_t usedBytes() = 0;

	virtual bool readRAW(uint8_t* buffer, uint32_t sector) = 0;
	virtual bool writeRAW(uint8_t* buffer, uint32_t sector) = 0;
};

#endif
