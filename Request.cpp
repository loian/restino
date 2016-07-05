//
// Created by Lorenzo Iannone on 02/07/2016.
//
#include "restino.h"
#include "Request.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




Request::~Request() {
    //free(method);
    //free(rawUrl);
}

void Request::setMethod(char *m) {
    method = (char *) malloc(sizeof(char) * strlen(m));
    strcpy(method, m);
}

void Request::setBody(char *b) {
    body = (char *) malloc(sizeof(char) * strlen(b));
    strcpy(body, b);
}

void Request::setRawUrl(char *u) {
    rawUrl = (char *) malloc(sizeof(char) * strlen(u));
    strcpy(rawUrl, u);
}

void Request::setHeader(char *key, char *value) {
    headers.setHeader(key, value);
}

const char* Request::getMethod() {
    return method;
}

char* Request::getRawUrl() {
    return rawUrl;
}
