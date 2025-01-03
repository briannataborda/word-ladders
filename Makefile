#########################################################
#                 PROJECT 2: Ladders                    #
#########################################################

MAKEFLAGS += -L

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3

ladder: main.o Dictionary.o Ladder.o WordLadder.o
	$(CXX) $(CXXFLAGS) -o ladder $^

Dictionary.o: Dictionary.h Dictionary.cpp
	$(CXX) $(CXXFLAGS) -c Dictionary.cpp

Ladder.o: Ladder.h Ladder.cpp Dictionary.h
	$(CXX) $(CXXFLAGS) -c Ladder.cpp

WordLadder.o: WordLadder.h WordLadder.cpp Ladder.h Dictionary.h
	$(CXX) $(CXXFLAGS) -c WordLadder.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

#The below rule will be used by unit tests
unit_test: unit_test_driver.o Dictionary.o Ladder.o
	$(CXX) $(CXXFLAGS) $^

clean:
	rm *.o *~ a.out