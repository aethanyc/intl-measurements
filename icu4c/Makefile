CXX := c++

all: locale pluralrules

locale: locale.cpp
	$(CXX) -std=c++17 -O3 -o locale locale.cpp `pkg-config --libs --cflags icu-uc icu-io icu-i18n`
pluralrules: pluralrules.cpp
	$(CXX) -std=c++17 -O3 -o pluralrules pluralrules.cpp `pkg-config --libs --cflags icu-uc icu-io icu-i18n`

clean:
	rm -f locale pluralrules
