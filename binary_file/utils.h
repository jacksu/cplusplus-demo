#ifndef BAYMAX_UTIL_UTILS_
#define BAYMAX_UTIL_UTILS_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#include <string>
#include <string.h>
#include <vector>

using std::vector;

namespace util {
  char* get_exe_dir();

  void split(char const *text, char const *separator,
             std::vector<std::string> *result);

  double get_current_time();

  bool my_system(const char * command);

  std::string get_local_ip();

  //  little-endian
  inline int bytes_to_int_little(char *buf) {
    int val = (buf[0] & 0xFF) |
              ((buf[1] << 8) & 0xFF00) |
              ((buf[2] << 16) & 0xFF0000) |
              ((buf[3] << 24) & 0xFF000000);
    return val;
  }
}

#endif
