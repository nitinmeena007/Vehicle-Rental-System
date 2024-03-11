// including custom headers
#include "application.h"

// including standard cpp headers
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
    Application * application = new Application();
    application->start();
}



/*

g++ -std=c++11 ./*.cpp -o application
chmod +x application
./application

*/