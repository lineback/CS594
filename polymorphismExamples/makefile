CC=g++
SOURCES= overloadTest.cc templateTest.cc subTypeTest.cc vectorEx.cc dequeEx.cc listEx.cc mapEx.cc setEx.cc functors.cc
EXECUTABLES= $(SOURCES:.cc=)

overloadTest:overloadTest.cc
	$(CC) -o $@ $<
templateTest:templateTest.cc
	$(CC) -o $@ $<
subTypeTest:subTypeTest.cc
	$(CC) -o $@ $<
vectorEx:vectorEx.cc
	$(CC) -o $@ $<
dequeEx:dequeEx.cc
	$(CC) -o $@ $<
listEx:listEx.cc
	$(CC) -o $@ $<
mapEx:mapEx.cc
	$(CC) -o $@ $<
setEx:setEx.cc
	$(CC) -o $@ $<
functors:functors.cc
	$(CC) -o $@ $<
clean:
	rm -f $(EXECUTABLES)