//
// Created by Lorenzo Iannone on 02/07/2016.
//
#include "Request.h"

#ifndef RESTINO_REQUESTBUILDER_H
#define RESTINO_REQUESTBUILDER_H


class RequestBuilder {

private:
    int state;
    const int STATE_FIRST_LINE = 1;
    const int STATE_HEADERS = 3;
    const int STATE_BODY = 3;
    int processFirstLine(char *line, Request *r);
    int processHeaderLine(char *line, Request *r);

public:
    int build(char* data, Request *request);

};


#endif //RESTINO_REQUESTBUILDER_H
