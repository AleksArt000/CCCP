#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// class stuff

#include "../../include/globals.h"
#include "../../include/utils.h"

// This function is moving the binaries to the correct locations
void move_binaries(char** locations,long loc_size)
{
    /*

    // check if all locations are empty
    msg(DBG1,"Checking if all locations are empty");Z
     For now , this checking part is completely useless 
     i plan to use it to do some checks on the system.
     I will leave it like that for now 
    */
    for (int i = 0; i < loc_size; i++)
    {
        if (!(access(locations[i],F_OK) == 0))
        {   if (locations[i] == NULL)
            {
                msg(ERROR,"Location is NULL");
                exit(1);
            }
            printf("[%d/%ld] - %s/%s to => %s\n",i,loc_size, BUILD_DIR,locations[i],locations[i]);
            fflush(stdout);
            // now that we know it is empty , mov the stuff
            rename(format("%s/%s",BUILD_DIR,locations[i]),locations[i]);
            
            msg(DBG1,"Moved %s/%s to %s",BUILD_DIR,locations[i],locations[i]);
        }
        else 
        {

            msg(WARNING,"%s is already here",locations[i]);

            if (OVERWRITE) 
            {
                rename(format("%s/%s",BUILD_DIR,locations[i]),locations[i]);
            }
            else {
                msg(FATAL, "Terminating the program");
            }
        }
    }
    return;


}