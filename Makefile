# default: run the name shell in daily/ directory
default:
	./daily/name

# git add all files under daily/ directory and commit
commit:
	git add daily/*
	git add cpp/*
	git commit

# cpp: 
cppp:
	./cpp/name