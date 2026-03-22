#include "ConsoleInterface.h"
#include "steam_api.h"

int main() {
	
	auto deals = findDeal();
	
	displayMenu(deals);

	



	return 0;
}





