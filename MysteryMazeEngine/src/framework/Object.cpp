#include "framework/Object.h"
#include "framework/Core.h"

namespace mz
{
	Object::Object()
		: _mIsPendingDestroy{false}

	{

	}

	//destructor
	Object::~Object()
	{
		LOG("Object destroyed.");
	}

	//customer modifiable 
	void Object::Destroy()
	{
		_mIsPendingDestroy = true;
	}
}
