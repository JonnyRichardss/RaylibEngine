#ifndef USE_ENGINE_EXPORTS
#define USE_ENGINE_EXPORTS
namespace JREngine {
	/// this is the namespace/header that defines the "API" for the static library
	/// technically all the headers can be accessed because its a staticlib but this is the one that is intended to be included and used
	// TODO! add engine functions once i have written the header
	namespace Engine {
		extern void Init();
		extern void Loop();
		extern void EndGame();
	}
	///other namespaces
	/*
	namespace Foo{
			extern void Foo();
			extern Bar* Baz();
	}
	*/
}
#endif // !USE_ENGINE_EXPORTS
