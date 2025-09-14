#include "PointerPlayground.hpp"

#include <string>

#include "fmt/core.h"

int RunPointerPlayground()
{
    fmt::println("Hello from pointer playground.");
    unsigned char whatever[] = "Hello";
    unsigned char* thePointer = &whatever[0];
    for (size_t i = 0; i + 1 < sizeof(whatever) / sizeof(whatever[0]); i++)
    {
        fmt::println(
            "address: {} | value(hex): 0x{:02x} | value(int): {:03} | "
            "value(txt) "
            "{:c}",
            (void*)thePointer, *thePointer, *thePointer, *thePointer);
        thePointer++;
    }

    fmt::println("Thing number two.. yay!!(?)");
    int a = 7;
    int* b = &a;

    std::string strTemplate = "a = {} | b = {} | *b = {}";
    fmt::println(strTemplate, a, (void*)b, *b);
    fmt::println(
        "Ok now I shall increment the derefenwughwgjced b just by a wee bit "
        ":)))))");
    (*b)++;
    fmt::println(strTemplate, a, (void*)b, *b);
    return 0;
}