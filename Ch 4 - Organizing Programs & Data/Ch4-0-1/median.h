#ifndef GUARD_median_h
#define GUARD_median_h

// The hashes above make it safe for this header to appear multiple times in a program compilation.
// The name chosen uses 'GUARD_' as a prefix in hopes that it keeps the name unique in the program.
// This causes the header file to define GUARD_median_h and the header file the first time it is encountered
//      as GUARD_median_h is undefined, but on later encounters it is skipped.

// Header files should use fully qualified names rather than 'using' declarations.

// median.h - final version
#include <vector>
double median(std::vector<double>);

#endif // GUARD_median_h
