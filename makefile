CC := g++
MYDIR := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
SRCDIR := src
BIN := bin
BUILDDIR := build
TARGET := main

SRCEXT := cpp
CFLAGS := --coverage -g -Wall -Wno-unknown-pragmas -O3 -std=c++11
T_CFLAGS := --coverage -g -Wall -O3
INC := -I include -I third-party


MODULES = generator QC QM3
SOURCES = $(addsuffix .cpp,$(MODULES))
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
TESTS = $(addprefix test_,$(SOURCES))
TESTSEXE = $(addsuffix .exe,$(TESTS))
TESTSEXEDIR = $(addprefix bin/,$(TESTSEXE))
COVER = $(addsuffix .gcov,$(SOURCES))

SOURCEDIR = $(addprefix $(MYDIR)src/,$(SOURCES))
OBJDIR = $(addprefix build/,$(OBJECTS))
TSTDIR = $(addprefix tests/test_,$(SOURCES))
TGTDIR = $(BIN)/$(TARGET)

all: $(TGTDIR)

$(OBJDIR): build/%.o : src/%.cpp
	@echo ""
	@echo OBJETO: $@
	$(shell mkdir -p build)
	#@mkdir -p ../build
	$(CC) $(INC) $(CFLAGS) -c $(patsubst build/%.o,src/%.cpp,$@) -o $@

$(TGTDIR): $(OBJDIR)
	@echo ""
	@echo COMPILANDO MAIN
	@mkdir -p bin
	$(CC) $(INC) $(CFLAGS) $(OBJDIR) program/$(TARGET).cpp -o $(TGTDIR)


tester: $(TESTS)
$(TESTS): tests/test_%.o : tests/test_%.cpp
	$(shell mkdir -p tests)
	@echo ""
	@echo TESTE: $@
	$(CC) $(INC) $(T_CFLAGS) tests/$@ $(OBJDIR) -o bin/$@.exe
	bin/$@.exe
	$(RM) test_*.gcno

comp: $(TGTDIR)
	$(CC) $(INC) $(CFLAGS) $(OBJDIR) program/$(TARGET).cpp -o $(TGTDIR)
	#@bin/main.exe
	#$(RM) main.gcno
	#$(RM) main.gcda

run:
	@bin/main.exe
	$(RM) main.gcno
	$(RM) main.gcda

test:
	$(shell mkdir -p result)
	number=1 ; while [[ $$number -le 25 ]] ; do\
		$(shell bin/main.exe QC Ale 50000 -p > result/qc_ale_50.txt)\
		#@bin/main.exe QC Ale 100000 -p > result/qc_ale_100.txt \
		#@bin/main.exe QC Ale 150000 -p > result/qc_ale_150.txt \
		#@bin/main.exe QC Ale 200000 -p > result/qc_ale_200.txt \
		#@bin/main.exe QC Ale 250000 -p > result/qc_ale_250.txt \
		#@bin/main.exe QC Ale 300000 -p > result/qc_ale_300.txt \
		#@bin/main.exe QC Ale 350000 -p > result/qc_ale_350.txt \
		#@bin/main.exe QC Ale 400000 -p > result/qc_ale_400.txt \
		#@bin/main.exe QC Ale 450000 -p > result/qc_ale_450.txt \
		#@bin/main.exe QC Ale 500000 -p > result/qc_ale_500.txt \
		((number = number + 1)); \
	done


debug:
	@gdb $(BIN)/main.exe

coverage: $(COVER)
$(COVER): src/%.gcov : src/%.cpp
	@echo ""
	@echo POSIÇAO: $@
	@gcov src/$(patsubst %.cpp.gcov,%.cpp,$@) -l -p -o build
	
	$(RM) src#$(patsubst %.cpp.gcov,%.cpp,$@)#*.gcov
	$(RM) #usr#lib*.gcov
	$(RM) *.gcda *.gcno

clean:
	$(RM) -r build/* coverage/* *.gcda *.gcno *.gcov *.exe *.o bin/* result/*

.PHONY: clean coverage



