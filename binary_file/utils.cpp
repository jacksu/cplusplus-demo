#include "utils.h"
#include <errno.h>

namespace util {


double get_current_time() {
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}

// 获取当前程序绝对路径
char* get_exe_dir() {
  static char current_absolute_path[1024];
  int cnt = readlink("/proc/self/exe", current_absolute_path, 1024);
  if (cnt < 0 || cnt >= 1024) {
    printf("cnt=%d, not in [0,1024]", cnt);
  }

  // 获取当前目录绝对路径，即去掉程序名
  for (int i = cnt; i >= 0; --i) {
    if (current_absolute_path[i] == '/') {
      current_absolute_path[i+1] = '\0';
      break;
    }
  }
  return current_absolute_path;
}


void split(char const *text, char const *separator,
           std::vector<std::string> *result) {
  char *tmp = strdup(text);
  char *s, *c;
  for (s = strtok_r(tmp, separator, &c); s != NULL;
       s = strtok_r(NULL, separator, &c))
    result->push_back(s);
  free(tmp);
}

bool my_system(const char * command) {
  if (NULL == command) {
    printf("command is null"); return false;
  }

  int status = system(command);
  if (status < 0) {
    printf("cmd: %s, error: %d", command, errno);
    return false;
  }

  if (WIFEXITED(status)) { // 取得command执行结果
    printf("normal termination, exit status = %d", WEXITSTATUS(status));
    return true;
  } else if (WIFSIGNALED(status)) { // 如果command被信号中断，取得信号值
    printf("abnormal termination,signal number = %d", WTERMSIG(status));
    return false;
  } else if (WIFSTOPPED(status)) { // 如果command被信号暂停执行，取得信号值
    printf("process stopped, signal number = %d", WSTOPSIG(status));
    return false;
  }
  return true;
}

std::string get_local_ip() {
  char hname[128];
  struct hostent *hent;
  int i;

  gethostname(hname, sizeof(hname));
  hent = gethostbyname(hname);

  printf("hostname: %s\naddress list: ", hent->h_name);
  for (i = 0; hent->h_addr_list[i]; i++) {
    if (NULL != inet_ntoa(*(struct in_addr*)(hent->h_addr_list[i]))) {
      return inet_ntoa(*(struct in_addr*)(hent->h_addr_list[i]));
    }
  }
  return "";
}



}
