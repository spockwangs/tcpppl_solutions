##
# Begin of Makefile
##

CXX = g++
CPPFLAGS = -ansi -W -Wall -Wconversion

SOURCE_FILES = $(wildcard *.cpp)
OBJECT_FILES = $(SOURCE_FILES .cpp = .o)
PROGRAMS = ex4.1 ex4.3 ex4.4 ex4.5

CLEAN_FILES = core* *~ *.o
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
