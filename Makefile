SOURCE_FILES:= main.cpp\
		SPainter.cpp\
		SPushButton.cpp
make:main.cpp
	g++ -Wall -g $(SOURCE_FILES) -o main -lSDL2 -lSDL2_image


MSG ?= $(shell bash -c 'read -s -p "Message: " msg; echo $$msg')
push:
	git add *
	git commit -m $(MSG)
	git push -u origin master

