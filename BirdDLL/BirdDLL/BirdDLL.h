// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BIRDDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BIRDDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BIRDDLL_EXPORTS
#define BIRDDLL_API __declspec(dllexport)
#else
#define BIRDDLL_API __declspec(dllimport)
#endif

#include "utils.h"

// This class is exported from the dll
class BIRDDLL_API Bird : public Animal {
public:
	Bird() = default;
	void doThing() override;
};

extern "C" BIRDDLL_API Animal * createBird();

