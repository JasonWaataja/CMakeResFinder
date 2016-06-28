#ifndef CMRF_H
#define CMRF_H

#include <stdarg.h>


int cmrf_init (int n_args, ...);

int cmrf_exit ();

int cmrf_add_path_cmake_prefix (const char *dir_name);

int cmrf_add_path_relative (const char *dir_name);

int cmrf_add_path_absolute (const char *dir_name);

int cmrf_is_in_search_paths (const char *dir_name);

const char *cmrf_find_resource (const char *res_name);

const char *
cmrf_get_cmake_install_prefix ();

#endif /* CMRF_H */
