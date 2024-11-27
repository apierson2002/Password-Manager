CXXFLAGS=-Wall -I/usr/local/include
SRCS= userList.cpp userList_unittest.cpp
OBJS= ${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

.PHONY: all clean

all: uLtest

uLtest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

userList.o: /home/dabell/passmang/gitRepo/src/model/userList.h /home/dabell/passmang/gitRepo/src/model/userList.cpp

clean:
	@rm -f uLtest *.o
