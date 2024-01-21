/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   uibase4_png;
    const int            uibase4_pngSize = 166466;

    extern const char*   uibase3_png;
    const int            uibase3_pngSize = 175428;

    extern const char*   uibase2_png;
    const int            uibase2_pngSize = 145756;

    extern const char*   uibase_png;
    const int            uibase_pngSize = 69646;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 4;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
