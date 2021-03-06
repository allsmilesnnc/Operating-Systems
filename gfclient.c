#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>

#include "gfclient.h"
#include "gfclient-student.h"

// optional function for cleaup processing.
void gfc_cleanup(gfcrequest_t *gfr){

}

gfcrequest_t *gfc_create(){
    // dummy for now - need to fill this part in

    return (gfcrequest_t *)NULL;

}

size_t gfc_get_bytesreceived(gfcrequest_t *gfr){
    // not yet implemented
    return -1;
}

size_t gfc_get_filelen(gfcrequest_t *gfr){
    // not yet implemented
    return -1;
}

gfstatus_t gfc_get_status(gfcrequest_t *gfr){
    // not yet implemented
    return -1;
}

void gfc_global_init(){
}

void gfc_global_cleanup(){
}

int gfc_perform(gfcrequest_t *gfr){
    // currently not implemented.  You fill this part in.
    return -1;
}

void gfc_set_headerarg(gfcrequest_t *gfr, void *headerarg){

}

void gfc_set_headerfunc(gfcrequest_t *gfr, void (*headerfunc)(void*, size_t, void *)){

}

void gfc_set_path(gfcrequest_t *gfr, char* path){

}

void gfc_set_port(gfcrequest_t *gfr, unsigned short port){

}

void gfc_set_server(gfcrequest_t *gfr, char* server){
  
}

void gfc_set_writearg(gfcrequest_t *gfr, void *writearg){

}

void gfc_set_writefunc(gfcrequest_t *gfr, void (*writefunc)(void*, size_t, void *)){
  
}

const char* gfc_strstatus(gfstatus_t status){
    const char *strstatus = "UNKNOWN";

    switch (status)
    {
        default:
        break;

        case GF_OK: {
            strstatus = "OK";
        }
        break;
        
        case GF_ERROR: {
            strstatus = "ERROR";
        }
        break;

        case GF_FILE_NOT_FOUND: {
            strstatus = "FILE_NOT_FOUND";
        }
        break;

        case GF_INVALID: {
            strstatus = "INVALID";
        }
        break;
    }

    return strstatus;
}

