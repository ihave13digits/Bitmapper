#include "bitmapper/core/game.h"

int main()
{

    Game bitmapper;
    
    if (bitmapper.Construct(core::width, core::height, core::resolution, core::resolution))
    {
        bitmapper.Start();
    }

	return 0;
}
