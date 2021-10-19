#include "SDFSWrapper.h"

File SDFSWrapper::open(const char* path, const char* mode)
{
	return SD.open(path, mode);
}

File SDFSWrapper::open(const String& path, const char* mode)
{
	return SD.open(path, mode);
}

bool SDFSWrapper::exists(const char* path)
{
	return SD.exists(path);
}

bool SDFSWrapper::exists(const String& path)
{
	return SD.exists(path);
}

bool SDFSWrapper::remove(const char* path)
{
	return SD.remove(path);
}

bool SDFSWrapper::remove(const String& path)
{
	return SD.remove(path);
}

bool SDFSWrapper::rename(const char* pathFrom, const char* pathTo)
{
	return SD.rename(pathFrom, pathTo);
}

bool SDFSWrapper::rename(const String& pathFrom, const String& pathTo)
{
	return SD.rename(pathFrom, pathTo);
}

bool SDFSWrapper::mkdir(const char* path)
{
	return SD.mkdir(path);
}

bool SDFSWrapper::mkdir(const String& path)
{
	return SD.mkdir(path);
}

bool SDFSWrapper::rmdir(const char* path)
{
	return SD.rmdir(path);
}

bool SDFSWrapper::rmdir(const String& path)
{
	return SD.rmdir(path);
}

bool SDFSWrapper::begin(uint8_t ssPin, SPIClass& spi, uint32_t frequency, const char* mountpoint, uint8_t max_files, bool format_if_empty)
{
	return SD.begin(ssPin, spi, frequency, mountpoint, max_files, format_if_empty);
}

void SDFSWrapper::end()
{
	SD.end();
}

sdcard_type_t SDFSWrapper::cardType()
{
	return SD.cardType();
}

uint64_t SDFSWrapper::cardSize()
{
	return SD.cardSize();
}

uint64_t SDFSWrapper::totalBytes()
{
	return SD.totalBytes();
}

uint64_t SDFSWrapper::usedBytes()
{
	return SD.usedBytes();
}

bool SDFSWrapper::readRAW(uint8_t* buffer, uint32_t sector)
{
	return SD.readRAW(buffer, sector);
}

bool SDFSWrapper::writeRAW(uint8_t* buffer, uint32_t sector)
{
	return SD.writeRAW(buffer, sector);
}
