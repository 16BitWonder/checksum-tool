#include <algorithm>
#include <iostream>
#include "FileChunkReader.hpp"
#include "crc32.h"
#include "md5.h"
#include "sha1.h"
#include "sha256.h"
using namespace std;

string generateCrc32(FileChunkReader &reader);
string generateMd5(FileChunkReader &reader);
string generateSha1(FileChunkReader &reader);
string generateSha256(FileChunkReader &reader);