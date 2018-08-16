
#include "logger/logger.hpp"
#include "resp_parser.hpp"
#include <stdio.h>
#include <assert.h>
#include <type_traits>
int main()
{
    set_log_level(logger_iface::log_level::debug);
    std::string test;
    std::pair<size_t, ParseResult> ret;

    test = "+OK\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "-Error message\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = ":1000\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "$6\r\nfoobar\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "$0\r\n\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "$-1\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "*0\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "*2\r\n$3\r\nfoo\r\n$3\r\nbar\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "*3\r\n:1\r\n:2\r\n:3\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "*5\r\n:1\r\n:2\r\n:3\r\n:4\r\n$6\r\nfoobar\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "*-1\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "*3\r\n$3\r\nfoo\r\n$-1\r\n$3\r\nbar\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    test = "*3\r\n$3\r\nfoo\r\n$-1\r\n$3\r\nbar\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

    // multi
    test = "+OK\r\n+OK\r\n+OK\r\n*3\r\n$3\r\nfoo\r\n$-1\r\n$3\r\nbar\r\n*3\r\n$3\r\nfoo\r\n$-1\r\n$3\r\nbar\r\n";
    ret = rasp_parser::process_resp(const_cast<char*>(test.c_str()), test.size(), [](char *buf, size_t len) {
        __LOG(debug, "buf is : " << (void *)buf << ", len is : " << len);
    });
    __LOG(debug, "size of string is : " << test.size() << ", size in the return is : " << std::get<0>(ret));
    assert(test.size() == std::get<0>(ret));

}
