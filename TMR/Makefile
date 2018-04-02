
MODULE=run.x

WORK=.
SYSTEMC_LIB=$(firstword $(wildcard $(SYSTEMC)/lib*))

.PHONY: all clean

all:
	@echo "+++++++++++++++++++++++++++++++++"
	@echo "Compiling a SystemC example"
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -c $(WORK)/matrix_mult.cpp
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -c $(WORK)/voter.cpp
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -c $(WORK)/main.cpp
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -L$(WORK)/ -L$(SYSTEMC_LIB)\
            -o $(WORK)/$(MODULE) \
            $(WORK)/matrix_mult.o $(WORK)/voter.o $(WORK)/main.o\
            -lsystemc -lm   2>&1 | c++filt
	@echo "+++ Executing +++++++++++++++++++"
	$(WORK)/$(MODULE)

clean:
	rm -fr *.o *.x *.deps dependencies.mk *~
