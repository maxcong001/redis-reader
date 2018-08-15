
#include "logger/logger.hpp"
#include "resp_parser.hpp"
#include <stdio.h>
int main()
{
    set_log_level(logger_iface::log_level::debug);

    std::string test = "+OK\r\naaaa";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "-Error message\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = ":1000\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "$6\r\nfoobar\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "$0\r\n\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "$-1\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "*0\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "*2\r\n$3\r\nfoo\r\n$3\r\nbar\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "*3\r\n:1\r\n:2\r\n:3\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });

    test = "*5\r\n:1\r\n:2\r\n:3\r\n:4\r\n$6\r\nfoobar\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "*-1\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "*2\r\n*3\r\n:1\r\n:2\r\n:3\r\n*2\r\n+Foo\r\n-Bar\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    test = "*3\r\n$3\r\nfoo\r\n$-1\r\n$3\r\nbar\r\n";
    rasp_parser::process_resp(test, [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });


    getchar();
}
