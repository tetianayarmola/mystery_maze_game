#include <stdio.h>

namespace mz
{
	//creating a macro for logging
	//M = printf()
	// ## is used to stick things together
	// ... means variadic arguments, whatever is there will be put on the second place
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}

//note: macro is useful for faster commands changing, 
//but can be bad for debugging because compiler will refer to the original command error, not a macro.