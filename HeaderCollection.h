//
// Created by Lorenzo Iannone on 04/07/2016.
//
#include "TypeCollection.h"

#ifndef RESTINO_HEADERCOLLECTION_H
#define RESTINO_HEADERCOLLECTION_H

class Header {
public:
    char* key;
    char* value;
};

class HeaderCollection {
    private:
    Vector<Header> headers = Vector<Header>();
    public:
    HeaderCollection();
    void setHeader(char *key, char *value);
    char* getHeader(char *key);
    Vector<Header> getHeaders();
};


#endif //RESTINO_HEADERCOLLECTION_H
