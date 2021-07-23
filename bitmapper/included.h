#pragma once

// ////
// /////
// //////  Included Source Code
// /////
// ////


//
/// Core Data
//

#include "core/core.h"



//
///  Platform Tools
//

// File I/O
#include "utility/platform.h"
#include "utility/utility.h"
#include "utility/data.h"



//
///  Cellular Automata
//

// Seasons
#include "environment/season.h"

// Cell Matrices And Dimensions
#include "environment/tile/cell.h"

// Tile Reference
#include "environment/tile/tile.h"

// Tile Tools
#include "environment/tile/tools.h"

// Rule References
#include "environment/tile/boom.h"
#include "environment/tile/critter.h"
#include "environment/tile/fluid.h"
#include "environment/tile/fume.h"
#include "environment/tile/gas.h"
#include "environment/tile/gel.h"
#include "environment/tile/gizmo.h"
#include "environment/tile/grain.h"
#include "environment/tile/logic.h"
#include "environment/tile/loose.h"
#include "environment/tile/plant.h"
#include "environment/tile/plant_product.h"
#include "environment/tile/plasma.h"
#include "environment/tile/plumbing.h"
#include "environment/tile/solid.h"



//
///  Environment
//

// Sky
#include "environment/sky.h"

// World
#include "environment/world.h"
#include "environment/procedural.h"



//
///  Magic
//

#include "magic/effect.h"
#include "magic/particle.h"



//
///  Items
//

// Tools
#include "item/tool/axe.h"
#include "item/tool/hammer.h"
#include "item/tool/pickaxe.h"
#include "item/tool/wand.h"
#include "item/tool/wrench.h"

// Inventory
#include "item/inventory.h"

// Item IDs
#include "item/item.h"


//
///  Entities
//

// Player
#include "entity/player.h"



//
///  User Interface
//

#include "ui/button.h"
#include "ui/camera.h"
#include "ui/icon.h"



//
/// Game
//

#include "core/instance.h"
