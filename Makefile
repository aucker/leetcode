# default: run the name shell in daily/ directory
default:
	./daily/name

# git add all files under daily/
add:
	clang-format -i daily/*.cpp
	git add daily/*

# git add all files under daily/ directory and commit
commit:
	git commit --verbose

clean:
	rm -rf daily/*.o
	rm -rf daily/*.out

# cpp: 
cppp:
	./cpp/name
