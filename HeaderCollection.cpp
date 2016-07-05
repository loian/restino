//
// Created by Lorenzo Iannone on 04/07/2016.
//

#include "HeaderCollection.h"

/**
 * Default constructor
 */
HeaderCollection::HeaderCollection() {}

/**
 * Get a header
 * @param key the header to get
 * @return char* | null
 */
char* HeaderCollection::getHeader(char *key) {
    for (int x=0; x<headers.size(); x++) {
        if (strcmp(headers[x].key, key)) {
            return headers[x].value;
        }
    }
    return NULL;
}

/**
 * Set a header
 * @param key the header name
 * @param value the value of the header
 * @return void
 */
void HeaderCollection::setHeader(char *key, char *value) {
    Header t = Header();
    t.key = key;
    t.value = value;
    headers.push_back(t);
}

/**
 * get all header
 * return headers
 */
Vector<Header> HeaderCollection::getHeaders() {
    return headers;
}