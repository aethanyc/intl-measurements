CXX := c++

all: locale pluralrules

locale: locale.cpp
	$(CXX) -Wall -static -std=c++17 -O3 -o locale locale.cpp `pkg-config --libs --cflags icu-uc icu-io icu-i18n` -ldl
pluralrules: pluralrules.cpp
	$(CXX) -Wall -static -std=c++17 -O3 -o pluralrules pluralrules.cpp `pkg-config --libs --cflags icu-uc icu-io icu-i18n` -ldl

clean:
	rm -f locale pluralrules
