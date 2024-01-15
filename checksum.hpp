#include "FileChunkReader.hpp"
#include "ProgressIndicator.hpp"
#include "crc32.h"
#include "md5.h"
#include "sha1.h"
#include "sha256.h"

enum Checksum { CHECKSUM_CRC32, CHECKSUM_MD5, CHECKSUM_SHA1, CHECKSUM_SHA256 };

std::string generateChecksum(FileChunkReader& reader, Checksum checksum);