# Overview
`printfc` wraps `printf(<format>, ...)` to include color specification for each paramater. The API is identical, but with a small extention. 



# Sample Usage
```
// Just like printf...
printfc("[r]%s", "red text");
printfc("[g]%s", "green text");
printfc("[r]%s [g]%s", "red", "green");

// Other type specifiers work too.
printf("[y]%d", 52334);
```



# Available Colors
Each color is specified with its first character (in lowercase, i.e. `[r]` for red). The following are currently available:
+ red
+ green
+ yellow
+ blue
+ magenta
+ cyan
+ normal
 
More will be added soon.



# Installation
This project is managed by [Kit](https://github.com/dasmithii/kit). If you use Kit in your developement workflow, simply `#include <kit/printfc.h>` to import necessary symbols. If not, just grab these source files directly.