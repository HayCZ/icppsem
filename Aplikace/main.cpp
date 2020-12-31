#include <iostream>
#include <api.h>
#include "Fleet.h"
#include "Car.h"
#include "Cmd.h"

int main()
{
	Fleet* fleet = new Fleet();
	Cmd* cmd = new Cmd(fleet);
	while (cmd->run)
	{
		cmd->displayMenu();
	}
	delete(fleet);
	delete(cmd);
	_CrtDumpMemoryLeaks();
}
