//
// Created by Lorenzo Iannone on 02/07/2016.
//
#include <stdio.h>
#include "RequestBuilder.h"
#include <string.h>
#include <ctype.h>
#include "http.h"
#include "Request.h"


/**
 * Parse the first line of a raw http request
 * @param line a const char pointer to the first line of the request
 * @param r a pointer to the Request object to populate
 * @return the error code
 */
int RequestBuilder::processFirstLine(char *line, Request *r) {
    char* copy = strdup(line);
    char* token;
    token = strtok(copy, " ");

    //get method
    //Restino supports only methods needed by a rest api
    if (
            0 == strcmp(token, HTTP_GET) ||
            0 == strcmp(token, HTTP_POST) ||
            0 == strcmp(token, HTTP_PUT) ||
            0 == strcmp(token, HTTP_PATCH) ||
            0 == strcmp(token, HTTP_DELETE)
        ) {
        r->setMethod(token);
    } else {
        return UNSUPPORTED_METHOD;
    }

    //get url
    token = strtok(NULL, " ");
    if (token) {
        r->setRawUrl(token);
    } else {
        return INVALID_REQUEST;
    }

    //get protocol
    token = strtok(NULL, " ");
    if (token) {
        if (token != HTTP_1_0) {
            return UNSUPPORTED_PROTOCOL;
        }
    } else {
        return INVALID_REQUEST;
    }

    //if any other token then invalid req
    token = strtok(NULL, "\n");
    if (token) {
        return INVALID_REQUEST;
    }

    return 1;
}


int processHeaderLine(char *line, Request *r) {

}
/**
 * Populate a request object parsing a raw http request
 * @param data a const char pointer to the raw request
 * @param request a pointer to the Request object to populate
 */
int RequestBuilder::build(char *data, Request *request) {

    char *copy = strdup(data);
    char *token, *firstLine, *header;


    printf("---");
    //first line
    token = strtok(copy, "\n");
    token[strlen(token)-1] = '\0';
    firstLine = strdup(token);
    printf("%s",firstLine);


    bool processingHeaders = true;
    while (token = strtok(NULL, "\n")) {
        token[strlen(token)-1] = '\0';
        if (0 == strcmp(token, "")) {
            processingHeaders = false;
        }

        if (processingHeaders) {
            printf("+");
           // processHeaderLine(token, request);
        } else {
            //save the body
            printf("*");
            request->setBody(strtok(NULL, "\0"));
            break;//printf ("--- %s ----",copy);
        }
    }
}

