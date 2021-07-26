# SALAD
> Nice hustle, tons-o-fun! Next time, eat a salad!

SALAD is an OpenAL loader library which is made specifically to avoid _any_ licensing issues caused by OpenAL-soft being licensed under LGPL.  

SALAD named after GLAD just becase I thought it would be funny.  

## Usage
In order to use SALAD you need a working C99 compiler (with extensions (Visual C/C++ and GNU extensions are supported)).
#### Via copying files
You can just copy files in yours source tree, then add `salad.c` as a source and append a new directory to the include path.
#### Via CMake and Git submodules
1. `git submodule add https://github.com/undnull/salad.git`
2. `add_subdirectory(salad)`
3. OPTIONAL: `set(SALAD_PARANOID OFF CACHE BOOL "" FORCE)`
4. OPTIONAL: `set(SALAD_EXAMPLES OFF CACHE BOOL "" FORCE)`
5. `target_link_libraries(my_game salad)`

## Licensing
I wrote all the headers (myself with a bit of help from regular expressions) based on OpenAL-soft ones but using SALAD's header. So the entirety of this repo is licensed under Simplified BSD license (see [LICENSE](blob/master/LICENSE) for details).

## Abstract examples
#### Generic C example
```c
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/salad.h>
#include <stddef.h>

int main(void)
{
    if(!saladLoadAL())
        return 1;
    
    ALCdevice *dev = alcOpenDevice(NULL);
    // ....

    return 0;
}
```

#### Source SDK
I was writing this in order to implement a better sound system for my Source Engine mod/game so this one is probably reasonable:
```cpp
#include "AL/al.h"
#include "AL/alc.h"
#include "AL/salad.h"
#include "tier1/interface.h"

static CDllDemandLoader al_dll("OpenAL32");

static void *SALAD_LoadFunc(const char *procname, void *arg)
{
    return al_dll.GetProcAddress(procname);
}

bool InitSomething()
{
    if(!saladLoadALFunc(SALAD_LoadFunc, NULL)) {
        // Crash the game?
        return false;
    }

    ALCdevice *dev = alcOpenDevice(NULL);
    // ...

    return true;
}
```
