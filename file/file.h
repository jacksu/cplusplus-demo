/*
 * file.h
 *
 *  Created on: 2018年8月8日
 *      Author: jacksu
 */

#ifndef SRC_MAIN_C___PROPHET_SO_FILE_H_
#define SRC_MAIN_C___PROPHET_SO_FILE_H_
#include <string>
/*
 *
 */
class File {
public:
	File();
	virtual ~File();
	static bool is_exist(const std::string &file);
	static bool is_link(const std::string &file);
	static bool link(const std::string &old, const std::string &now);
	/***
	 * can not use remove, remove is use in C lib
	 * @param file
	 * @return
	 */
	static bool remove(const std::string &file);
	static std::string get_real_file_path(const std::string &link);
	static std::string get_file_name(const std::string& path);
	static std::string get_path(const std::string &file);
};

#endif /* SRC_MAIN_C___PROPHET_SO_FILE_H_ */
