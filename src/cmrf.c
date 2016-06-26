#include "cmrf.h"

#include "cmrfconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* True if the library init function has been called, false otherwise.  */
static int init_status;

/* Whether or not the user has set a cusom directory for searching for
   resources.  It's set to 0 by default.  */
static int has_custom_dir = 0;

/* The absolute path of the directory to search for resources in.  */
static char *res_search_dir = NULL;

static int check_for_init ();

int
cmrf_init_relative (const char *dir_name)
{
  if (dir_name == NULL)
    {
      res_search_dir = NULL;
      has_custom_dir = 0;
    }
  else
    {
      /* The +1 is for the slash in between.  */
      int prefix_len = strlen (CMAKE_INSTALL_PREFIX + 1);
      int dir_name_length = strlen (dir_name);

      int total_length = prefix_len + dir_name_length;

      res_search_dir = (char *) malloc (sizeof (char) * (total_length + 1));

      strcpy (res_search_dir, CMAKE_INSTALL_PREFIX);
      strcat (res_search_dir, "/");
      strcat (res_search_dir, dir_name);

      has_custom_dir = 1;
    }

  init_status = 1;
  return 1;
}

int
cmrf_init_absolute (const char *dir_name)
{
  if (dir_name == NULL)
    {
      res_search_dir = NULL;
      has_custom_dir = 0;
    }
  else
    {
      int dir_name_length = strlen (dir_name);

      res_search_dir = (char *) malloc (sizeof (char) * (dir_name_length + 1));

      if (!res_search_dir)
        {
          fprintf (stderr, "cmrf: Error allocating memory.");
          has_custom_dir = 0;
          init_status = 0;
          return 0;
        }

      strcpy (res_search_dir, dir_name);

      has_custom_dir = 1;
    }

  init_status = 1;
  return 1;
}

int
cmrf_exit ()
{
  /* I don't know if this should be called but it probably should.  */
  check_for_init ();
  /* I think it shouldn't matter because if it's NULL, then it junst won't do anything.  */
  free (res_search_dir);
  return 1;
}

int
cmrf_has_custom_dir ()
{
  check_for_init ();

  return has_custom_dir;
}

int
cmrf_set_custom_dir_relative (const char *dir_name)
{
  check_for_init ();

  free (res_search_dir);
  if (dir_name == NULL)
    {
      res_search_dir = NULL;
      has_custom_dir = 0;
    }
  else
    {
      int dir_name_length = strlen (dir_name);

      res_search_dir = (char *) malloc (sizeof (char) * (dir_name_length + 1));

      if (!res_search_dir)
        {
          fprintf (stderr, "cmrf: Error allocating memory.");
          has_custom_dir = 0;
          return 0;
        }

      strcpy (res_search_dir, dir_name);

      has_custom_dir = 1;
    }
  return 1;
}

int
cmrf_set_custom_dir_absolute (const char *dir_name)
{
  check_for_init ();

  free (res_search_dir);

  if (dir_name == NULL)
    {
      res_search_dir = NULL;
      has_custom_dir = 0;
    }
  else
    {
      int dir_name_length = strlen (dir_name);
      res_search_dir = (char *) malloc (sizeof (char) * (dir_name_length + 1));

      if (!res_search_dir)
        {
          fprintf (stderr, "cmrf: Error allocating memory.");
          has_custom_dir = 0;
          return 0;
        }

      strcpy (res_search_dir, dir_name);
    }
  return 1;
}

const char *
cmrf_get_res_search_dir ()
{
  check_for_init ();

  if (has_custom_dir)
    {
      return res_search_dir;
    }
  else
    {
      return CMRF_DEFAULT_DIRECTORY;
    }
}

const char *
cmrf_get_cmake_install_prefix ()
{
  return CMAKE_INSTALL_PREFIX;
}

static int
check_for_init ()
{
  assert (init_status != 0);
  return init_status;
}
