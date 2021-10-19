// SDFSWrapper.h

#ifndef _SDFSWRAPPER_h
#define _SDFSWRAPPER_h

#include "ISDFS.h"
#include "SD.h"

class SDFSWrapper : public ISDFS
{
public:
    //FS
    File open(const char* path, const char* mode = FILE_READ);
    File open(const String& path, const char* mode = FILE_READ);

    bool exists(const char* path);
    bool exists(const String& path);

    bool remove(const char* path);
    bool remove(const String& path);

    bool rename(const char* pathFrom, const char* pathTo);
    bool rename(const String& pathFrom, const String& pathTo);

    bool mkdir(const char* path);
    bool mkdir(const String& path);

    bool rmdir(const char* path);
    bool rmdir(const String& path);

    //SDFS
    bool begin(uint8_t ssPin = SS, SPIClass& spi = SPI, uint32_t frequency = 4000000, const char* mountpoint = "/sd", uint8_t max_files = 5, bool format_if_empty = false);
    void end();
    sdcard_type_t cardType();
    uint64_t cardSize();
    uint64_t totalBytes();
    uint64_t usedBytes();
    bool readRAW(uint8_t* buffer, uint32_t sector);
    bool writeRAW(uint8_t* buffer, uint32_t sector);
};

#endif

