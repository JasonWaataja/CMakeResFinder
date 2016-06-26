#ifndef CMRF_H
#define CMRF_H

int
cmrf_init_relative (const char *dir_name);

int
cmrf_init_absolute (const char *dir_name);

int
cmrf_exit ();

/* Public function to return the value of has_custom_dir.  */
int
cmrf_has_custom_dir ();

/* Sets the custom directory to find files in relative to the default cmake
   installation prefix.  */
int
cmrf_set_custom_dir_relative (const char *dir_name);

/* Sets the custom directory to find files in the full path specified by
   dir_name.  */
int
cmrf_set_custom_dir_absolute (const char *dir_name);

const char *
cmrf_get_res_search_dir ();

const char *
cmrf_get_cmake_install_prefix ();

#endif /* CMRF_H */
