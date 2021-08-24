
// hellogt.cxx

#include <libintl.h>

#include <locale.h>

#include <iostream>

#include <cstdlib>

int main (){

    char* cwd = getenv("PWD");

    std::cout << "getenv(PWD): " << (cwd?cwd:"NULL") << std::endl;

    char* l = getenv("LANG");

    std::cout << "getenv(LANG): " << (l?l:"NULL") << std::endl;

    char* s = setlocale(LC_ALL, "");

    std::cout << "setlocale(): " << (s?s:"NULL") << std::endl;

    std::cout << "bindtextdomain(): " << bindtextdomain("hellogt", cwd) << std::endl;

    std::cout << "textdomain(): " << textdomain( "hellogt") << std::endl;

    std::cout << gettext("hello, world!") << std::endl;

}

