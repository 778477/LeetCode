CXX = clang++
CXXFLAGS = -std=c++11
OBJECTS = leetcode.o

leetcode: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@ 

clean:
	rm $(OBJECTS) leetcode

format:
	clang-format -i -style=google *.cpp