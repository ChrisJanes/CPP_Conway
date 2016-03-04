#include <iostream>
#include <string>
#include <chrono>
#include <thread>


#include "Conway.h"

int main(int argc, char *argv)
{
	Conway life = Conway();

	while (true)
	{
		life.Update();
		life.Draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}