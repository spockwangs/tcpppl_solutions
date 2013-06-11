##
# Begin of Makefile
##

CXX = g++
CPPFLAGS = -ansi -pedantic -ggdb -W -Wall -Wconversion -Wno-deprecated

SOURCE_FILES = $(wildcard *.cpp)
OBJECT_FILES = $(SOURCE_FILES .cpp = .o)
PROGRAMS = ex17.3 ex17.6

CLEAN_FILES = core* *~ *.o a.out
CSCOPE_FILES = $(wildcard *.cpp) $(wildcard *.h)
CSCOPE_DATABASE = cscope.out


%.o: %.cpp
	@echo Compiling $^ ...
	@$(CXX) $(CPPFLAGS) -c -o $@ $^

%: %.cpp
	@echo Compiling $^ ...
	@$(CXX) $(CPPFLAGS) -o $@ $^

all: $(PROGRAMS)

clean:
	-$(RM) -f $(CLEAN_FILES)

dist-clean:
	$(MAKE) clean
	$(RM) -f $(PROGRAMS) $(CSCOPE_DATABASE)

cscope: $(CSCOPE_FILES)
	@echo Generating cscope database ...
	@cscope -bR -f$(CSCOPE_DATABASE) $^

.PHONY: clean dist-clean

##
# End of Makefile
##
