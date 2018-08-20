/*
 * file.cpp
 *
 *  Created on: 2018年8月8日
 *      Author: sunny.su
 */

#include "file.h"
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <glog/logging.h>

File::File() {
	// TODO Auto-generated constructor stub

}

File::~File() {
	// TODO Auto-generated destructor stub
}

bool File::is_exist(const std::string &file) {
	return (access(file.c_str(), F_OK) != -1);
}

bool File::is_link(const std::string &file) {
	struct stat st;
	if (lstat(file.c_str(), &st) == 0) {
		if (S_ISLNK(st.st_mode)) {
			return true;
		}
	}
	return false;
}

bool File::link(const std::string &old, const std::string &now) {
	int ret = symlink(old.c_str(), now.c_str());
	if (ret) {
		LOG(ERROR)<<"sym link error from ["<<old<<"] to ["<<now<<"]";
		return false;
	}
	return true;
}

bool File::remove(const std::string &file) {
	int ret = 0;
	LOG(INFO)<<"remove file ["<<file<<"]";
	if (is_exist(file)) {
		ret = remove(file.c_str());
	}
	if (ret) {
		LOG(ERROR)<<"delete file ["<<file<<"] error.";
		return false;
	}
	return true;
}

std::string File::get_real_file_path(const std::string &link) {
	if (!is_link(link)) {
		return link;
	}
	char buf[1024];
	int num = readlink(link.c_str(), buf, 1024);
	std::string result(buf, num);
	return result;
}
std::string File::get_file_name(const std::string& path) {

	char sep = '/';
#ifdef _WIN32
	sep = '\\';
#endif

	size_t i = path.rfind(sep, path.length());
	if (i != std::string::npos) {
		return (path.substr(i + 1, path.length() - i));
	}
	return ("");
}
std::string File::get_path(const std::string &file) {
	char sep = '/';
#ifdef _WIN32
	sep = '\\';
#endif

	size_t i = file.rfind(sep, file.length());
	if (i != std::string::npos) {
		return (file.substr(0, i+1));
	}
	return ("");
}
