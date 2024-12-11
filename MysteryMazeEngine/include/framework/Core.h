#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>

//here we create macro and tempates definitions to improve code readability and make it shorter.     
//definition of templates and macro can be changed later to smth else if needed for entire game in this one single file.

namespace mz
{
	
	//define unique pointer template
	//whenever we use "unique" compiler will read it as "std::unique_ptr"
	template<typename T>
	using unique = std::unique_ptr<T>;
	                      

	//define shared pointer template
	//whenever we use "shared" compiler will read it as "std::shared_ptr"
	template<typename T>
	using shared = std::shared_ptr<T>; 
	

	//define weak pointer template
	//whenever we use "weak" compiler will read it as "std::weak_ptr"
	template<typename T>
	using weak = std::weak_ptr<T>;



	// <-- define basic containers templates -->
	
	//define list template
	//whenever we use "List" compiler will read it as "std::vector"
	template<typename T>
	using List = std::vector<T>;

	//define map template (ordered): 
	// keyType, alueType and Pr (Predicate) are added because std::map requires 2 arguments 
	// Predicate Pr = std::less<keyType determines the order of the arguments, "less"/small one will be in the front and bigger one on the back.
	// e.g., keyType = 1 will be placed first before keyValue = 2, ensuring that our data is ordered by the value of the keyType
	//slower than unordered, use if we care about the order
	template<typename keyType, typename valueType, typename Pr = std::less<keyType>>
	using Map = std::map<keyType, valueType, Pr>;

	//define unordered map template:
	//Different from Map, the order is not guaranteed, it can be anything.
	//Hasher (hash function) determines the unique index for the keyType value and use it to store the value.
	//Order here based on the index given by hash(), but not on the value of the keyType.
	//faster than ordered, use if we do NOT care about the order
	template<typename keyType, typename valueType, typename Hasher = std::hash<keyType>>
	using Dictionary = std::unordered_map<keyType, valueType, Hasher>;



	// <-- creating a macro for logging -->
	
	//M = printf()
	// ## is used to stick things together
	// ... means variadic arguments, whatever is there will be put on the second place
	//e.g.: LOG("Text: %f", 1.f );
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

	//note: macro is useful for faster commands changing, 
	//but can be bad for debugging because compiler will refer to the original command error, not a macro.

}

