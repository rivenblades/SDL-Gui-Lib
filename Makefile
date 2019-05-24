SOURCE_FILES:= main.cpp\
		SPainter.cpp\
		SPushButton.cpp\
		common.cpp\
		extern/tinyxml2/tinyxml2.cpp
make:main.cpp
	g++ -Wall -g -I/extern/tinyxml2/ $(SOURCE_FILES) -o main -lSDL2 -lSDL2_image 

clean:
	rm *.gch
	rm *.swp

MSG ?= $(shell bash -c 'read -s -p "Message: " msg; echo $$msg')
push:
	git add *
	git commit -m $(MSG)
	git push -u origin master

