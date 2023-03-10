/*
* This file is part of Project SkyFire https://www.projectskyfire.org. 
* See LICENSE.md file for Copyright information
*/
 
#include <string>
#include <iostream>

#include "TileAssembler.h"

int main(int argc, char* argv[])
{
    std::string src = "Buildings";
    std::string dest = "vmaps";
    if(argc > 3)
    {
        //printf("\nusage: %s <raw data dir> <vmap dest dir> [config file name]\n", argv[0]);
        std::cout << "usage: " << argv[0] << " <raw data dir> <vmap dest dir>" << std::endl;
        return 1;
    }
    else
    {
        if (argc > 1)
            src = argv[1];
        if (argc > 2)
            dest = argv[2];
    }
    
    std::cout << "using " << src << " as source directory and writing output to " << dest << std::endl;

    VMAP::TileAssembler* ta = new VMAP::TileAssembler(src, dest);

    if(!ta->convertWorld2())
    {
        std::cout << "exit with errors" << std::endl;
        delete ta;
        return 1;
    }

    delete ta;
    std::cout << "Ok, all done" << std::endl;
    return 0;
}
