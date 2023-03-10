CC = g++
CFLAGS = -c -Ihash-library

all: release

release: main.o
	$(CC) -o checksum-tool main.o FileChunkReader.o checksum.o crc32.o md5.o sha1.o sha256.o

main.o: main.cpp
	$(CC) $(CFLAGS) -o crc32.o hash-library/crc32.cpp
	$(CC) $(CFLAGS) -o md5.o hash-library/md5.cpp
	$(CC) $(CFLAGS) -o sha1.o hash-library/sha1.cpp
	$(CC) $(CFLAGS) -o sha256.o hash-library/sha256.cpp
	$(CC) $(CFLAGS) -o checksum.o checksum.cpp
	$(CC) $(CFLAGS) -o FileChunkReader.o FileChunkReader.cpp
	$(CC) $(CFLAGS) -o main.o main.cpp

clean:
	rm -rf *.o checksum-tool
