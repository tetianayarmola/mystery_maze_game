#include "player/PlayerGhost.h"

namespace mz
{
	PlayerGhost::PlayerGhost(World* ownedByWorld, const std::string& path)
		: Ghost{ownedByWorld, path}
	{
	}
}