#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "Application.h"

using namespace std;


int main(){
	Application *application = new Application();
	
	while(true){
		application->mainScreen();
	}
	
	getch();
	return 0;
}

