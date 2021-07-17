#include "bitmapper/core/game.h"

int main()
{
	Game demo;
	//if (demo.Construct(256, 144, 4, 4, false, false, false))
    if (demo.Construct(core::width, core::height, core::resolution, core::resolution))
		demo.Start();

	return 0;
}
