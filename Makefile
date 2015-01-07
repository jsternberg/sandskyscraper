PROGRAMS=compress fisher-yates gcd vector-bigo

all: $(PROGRAMS)
.PHONY: all

clean:
	rm -f $(PROGRAMS) *.o
.PHONY: clean

%: %.o
	g++ $^ -o $@

%.o: %.cc
	g++ -c $^ -o $@
