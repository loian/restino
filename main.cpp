#include <iostream>
#include "RequestBuilder.h"

using namespace std;

int main() {


    char *rq = ""
            "GET /dumprequest HTTP/1.1\r\n"
            "Host: rve.org.uk\r\n"
            "CoMozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/5nnection: keep-alive\r\n"
            "Upgrade-Insecure-Requests: \r\n"
            "User-Agent: 1.0.2704.103 Safari/537.36\r\n"
            "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
            "Referer: https://www.google.co.uk/\r\n"
            "Accept-Language: en-US,en;q=0.8\r\n"
            "\r\n"
            "body if null then boh\r\npio pio pio pio\r\nciao";



    RequestBuilder r;
    Request x;
    r.build(rq, &x);

//    printf ("method  : %s \n", x.getMethod());
//    printf ("raw url : %s \n", x.getRawUrl());

    return 0;
}