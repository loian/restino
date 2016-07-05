//
// Created by Lorenzo Iannone on 02/07/2016.
//
#include "HeaderCollection.h"

#ifndef RESTINO_REQUEST_H
#define RESTINO_REQUEST_H

#define UNSUPPORTED_METHOD          -1;
#define INVALID_REQUEST         -2;
#define UNSUPPORTED_PROTOCOL    -3;

class Request {
private:
    char* rawUrl;
    HeaderCollection headers = HeaderCollection();
    char* body;
    char* method;

public:
    ~Request();
    void setMethod(char *method);
    void setRawUrl(char *url);
    void setBody(char *b);
    void setHeader(char *key, char *value);
    const char* getMethod();
    char* getRawUrl();
    char* getBody();
};


#endif //RESTINO_REQUEST_H
