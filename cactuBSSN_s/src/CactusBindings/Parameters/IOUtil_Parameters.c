/*@@
   @file    IOUtil_Parameters.c
   @author  Automatically generated by CreateParameterBindings.pl
   @desc
            Creates/extends parameters for this thorn
   @enddesc
 @@*/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "cctk_Config.h"
#include "cctk_Constants.h"
#include "ParameterBindings.h"
#include "CParameterStructNames.h"

/* structure containing all private parameters of thorn IOUtil */
struct
{
  CCTK_INT truncate_files;
  CCTK_INT truncate_files_after_recovering;
} PRIVATE_IOUTIL_STRUCT;


/* structure containing all restricted parameters of thorn IOUtil */
struct
{
  CCTK_REAL checkpoint_every_walltime_hours;
  CCTK_REAL out_dt;
  CCTK_REAL out_xline_y;
  CCTK_REAL out_xline_z;
  CCTK_REAL out_xyplane_z;
  CCTK_REAL out_xzplane_y;
  CCTK_REAL out_yline_x;
  CCTK_REAL out_yline_z;
  CCTK_REAL out_yzplane_x;
  CCTK_REAL out_zline_x;
  CCTK_REAL out_zline_y;
  const char * checkpoint_ID_file;
  const char * checkpoint_dir;
  const char * checkpoint_file;
  const char * filereader_ID_dir;
  const char * filereader_ID_files;
  const char * filereader_ID_vars;
  const char * out_criterion;
  const char * out_dir;
  const char * out_fileinfo;
  const char * out_mode;
  const char * out_save_parameters;
  const char * parfile_name;
  const char * parfile_write;
  const char * recover;
  const char * recover_dir;
  const char * recover_file;
  const char * verbose;
  CCTK_INT abort_on_io_errors;
  CCTK_INT checkpoint_ID;
  CCTK_INT checkpoint_every;
  CCTK_INT checkpoint_keep;
  CCTK_INT checkpoint_on_terminate;
  CCTK_INT new_filename_scheme;
  CCTK_INT out3D_septimefiles;
  CCTK_INT out_downsample_x;
  CCTK_INT out_downsample_y;
  CCTK_INT out_downsample_z;
  CCTK_INT out_every;
  CCTK_INT out_proc_every;
  CCTK_INT out_single_precision;
  CCTK_INT out_timesteps_per_file;
  CCTK_INT out_unchunked;
  CCTK_INT out_xline_yi;
  CCTK_INT out_xline_zi;
  CCTK_INT out_xyplane_zi;
  CCTK_INT out_xzplane_yi;
  CCTK_INT out_yline_xi;
  CCTK_INT out_yline_zi;
  CCTK_INT out_yzplane_xi;
  CCTK_INT out_zline_xi;
  CCTK_INT out_zline_yi;
  CCTK_INT parfile_update_every;
  CCTK_INT print_timing_info;
  CCTK_INT recover_and_remove;
  CCTK_INT require_empty_output_directory;
  CCTK_INT strict_io_parameter_check;
} RESTRICTED_IO_STRUCT;


int CCTKi_BindingsCreateIOUtilParameters(void);
int CCTKi_BindingsCreateIOUtilParameters(void)
{
  CCTKi_ParameterCreate("abort_on_io_errors",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Abort on I/O errors (rather than just print a warning) ?",
                        "no",
                        &(RESTRICTED_IO_STRUCT.abort_on_io_errors),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("checkpoint_ID",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Checkpoint initial data ?",
                        "no",
                        &(RESTRICTED_IO_STRUCT.checkpoint_ID),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("checkpoint_ID_file",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "File name for initial data checkpoint",
                        "checkpoint.chkpt",
                        &(RESTRICTED_IO_STRUCT.checkpoint_ID_file),
                        0,
                        NULL,
                        1,
                        ".+", "A valid filename");

  CCTKi_ParameterCreate("checkpoint_dir",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Output directory for checkpoint files",
                        ".",
                        &(RESTRICTED_IO_STRUCT.checkpoint_dir),
                        0,
                        NULL,
                        1,
                        ".+", "A valid directory name");

  CCTKi_ParameterCreate("checkpoint_every",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "How often to checkpoint",
                        "-1",
                        &(RESTRICTED_IO_STRUCT.checkpoint_every),
                        0,
                        NULL,
                        2,
                        "1:*", "Every so many iterations",
                        "-1:0", "Disable periodic checkpointing");

  CCTKi_ParameterCreate("checkpoint_every_walltime_hours",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "How often to checkpoint",
                        "-1",
                        &(RESTRICTED_IO_STRUCT.checkpoint_every_walltime_hours),
                        0,
                        NULL,
                        2,
                        "(0:*", "After so much walltime has passed",
                        "-1", "Disable periodic walltime checkpointing");

  CCTKi_ParameterCreate("checkpoint_file",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "File name for regular checkpoint",
                        "checkpoint.chkpt",
                        &(RESTRICTED_IO_STRUCT.checkpoint_file),
                        0,
                        NULL,
                        1,
                        ".+", "A valid filename");

  CCTKi_ParameterCreate("checkpoint_keep",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "How many checkpoint files to keep",
                        "1",
                        &(RESTRICTED_IO_STRUCT.checkpoint_keep),
                        0,
                        NULL,
                        2,
                        "1:*", "1 overwrites the latest checkpoint file",
                        "-1:", "Keep all checkpoint files");

  CCTKi_ParameterCreate("checkpoint_on_terminate",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Checkpoint after last iteration",
                        "no",
                        &(RESTRICTED_IO_STRUCT.checkpoint_on_terminate),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("filereader_ID_dir",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Directory to look for input files",
                        ".",
                        &(RESTRICTED_IO_STRUCT.filereader_ID_dir),
                        0,
                        NULL,
                        1,
                        ".+", "A valid directory name");

  CCTKi_ParameterCreate("filereader_ID_files",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "List of basenames of files to read in as initial data (e.g. omit the filename extention here)",
                        "",
                        &(RESTRICTED_IO_STRUCT.filereader_ID_files),
                        0,
                        NULL,
                        2,
                        ".+", "Space-separated list of initial data filenames (basenames, e.g. excluding the file name extention)",
                        "^$", "An empty string for not recovering initial data");

  CCTKi_ParameterCreate("filereader_ID_vars",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "List of variables to read in from the given initial data files",
                        "all",
                        &(RESTRICTED_IO_STRUCT.filereader_ID_vars),
                        0,
                        NULL,
                        3,
                        "all", "Read all variables contained in the initial data files",
                        ".+", "Space-separated list of fully qualified variable/group names",
                        "^$", "An empty string for not recovering initial data");

  CCTKi_ParameterCreate("new_filename_scheme",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Use the new filename scheme for output files ?",
                        "yes",
                        &(RESTRICTED_IO_STRUCT.new_filename_scheme),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("out3D_septimefiles",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Write one file per time slice, as opposed to all data in one file",
                        "no",
                        &(RESTRICTED_IO_STRUCT.out3D_septimefiles),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("out_criterion",
                        "IOUtil",
                        "KEYWORD",
                        "RESTRICTED",
                        CCTK_STEERABLE_NEVER,
                        "Criterion to select output intervals",
                        "iteration",
                        &(RESTRICTED_IO_STRUCT.out_criterion),
                        0,
                        NULL,
                        3,
                        "never", "Never output",
                        "iteration", "Output every so many iterations",
                        "time", "Output every that much coordinate time");

  CCTKi_ParameterCreate("out_dir",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Default output directory",
                        ".",
                        &(RESTRICTED_IO_STRUCT.out_dir),
                        0,
                        NULL,
                        1,
                        ".+", "A valid directory name");

  CCTKi_ParameterCreate("out_downsample_x",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Factor by which to downsample output in x direction. Point (0,0,0) is always included.",
                        "1",
                        &(RESTRICTED_IO_STRUCT.out_downsample_x),
                        0,
                        NULL,
                        1,
                        "1:*", "A positive integer");

  CCTKi_ParameterCreate("out_downsample_y",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Factor by which to downsample output in y direction. Point (0,0,0) is always included.",
                        "1",
                        &(RESTRICTED_IO_STRUCT.out_downsample_y),
                        0,
                        NULL,
                        1,
                        "1:*", "A positive integer");

  CCTKi_ParameterCreate("out_downsample_z",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Factor by which to downsample output in z direction. Point (0,0,0) is always included.",
                        "1",
                        &(RESTRICTED_IO_STRUCT.out_downsample_z),
                        0,
                        NULL,
                        1,
                        "1:*", "A positive integer");

  CCTKi_ParameterCreate("out_dt",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "How often to do output by default",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_dt),
                        0,
                        NULL,
                        4,
                        "(0:*", "In intervals of that much coordinate time",
                        "0", "As often as possible",
                        "-1", "Disable output",
                        "-2", "Disable output");

  CCTKi_ParameterCreate("out_every",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "How often to do output by default",
                        "-1",
                        &(RESTRICTED_IO_STRUCT.out_every),
                        0,
                        NULL,
                        2,
                        "1:*", "Every so many iterations",
                        "-1:0", "Disable output");

  CCTKi_ParameterCreate("out_fileinfo",
                        "IOUtil",
                        "KEYWORD",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Add some useful file information to output files ?",
                        "all",
                        &(RESTRICTED_IO_STRUCT.out_fileinfo),
                        0,
                        NULL,
                        5,
                        "none", "no file information",
                        "creation date", "add creation date",
                        "parameter filename", "add parameter filename",
                        "axis labels", "add axis labels information to output files",
                        "all", "add all available file information");

  CCTKi_ParameterCreate("out_mode",
                        "IOUtil",
                        "KEYWORD",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Which mode to use for output",
                        "proc",
                        &(RESTRICTED_IO_STRUCT.out_mode),
                        0,
                        NULL,
                        3,
                        "proc", "Every processor writes its share of data into a separate file",
                        "np", "Data is collected and written by every N'th processor into a separate file, where N is specified by the parameter IO::out_proc_every",
                        "onefile", "All output is written into a single file by processor 0");

  CCTKi_ParameterCreate("out_proc_every",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Do output on every N processors",
                        "8",
                        &(RESTRICTED_IO_STRUCT.out_proc_every),
                        0,
                        NULL,
                        1,
                        "1:*", "A number between [1, nprocs)");

  CCTKi_ParameterCreate("out_save_parameters",
                        "IOUtil",
                        "KEYWORD",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Save current parameter settings in output files ?",
                        "only set",
                        &(RESTRICTED_IO_STRUCT.out_save_parameters),
                        0,
                        NULL,
                        3,
                        "all", "Save all parameter settings",
                        "only set", "Only save parameters which have been set before",
                        "no", "Don't save parameter settings");

  CCTKi_ParameterCreate("out_single_precision",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Output data in single precision ?",
                        "no",
                        &(RESTRICTED_IO_STRUCT.out_single_precision),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("out_timesteps_per_file",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "How many timesteps to write to a single file",
                        "-1",
                        &(RESTRICTED_IO_STRUCT.out_timesteps_per_file),
                        0,
                        NULL,
                        2,
                        "1:1", "Number of timesteps per file (can only be 1 so far)",
                        "-1:", "All timesteps in a single file");

  CCTKi_ParameterCreate("out_unchunked",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Don't write data in chunks. This parameter is ignored for single-processor runs where output is always done in unchunked mode.",
                        "no",
                        &(RESTRICTED_IO_STRUCT.out_unchunked),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("out_xline_y",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "y-coord for 1D lines in x-direction",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_xline_y),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [ymin, ymax]");

  CCTKi_ParameterCreate("out_xline_yi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "y-index (from 0) for 1D lines in x-direction, overrides IO::out_xline_y",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_xline_yi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, ny)",
                        "-1:", "Default to physical coordinate IO::out_xline_y if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_xline_y if it is within grid bounds, otherwise revert to using the y-center of the box");

  CCTKi_ParameterCreate("out_xline_z",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "z-coord for 1D lines in x-direction",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_xline_z),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [zmin, zmax]");

  CCTKi_ParameterCreate("out_xline_zi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "z-index (from 0) for 1D lines in x-direction, overrides IO::out_xline_z",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_xline_zi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, nz)",
                        "-1:", "Default to physical coordinate IO::out_xline_z if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_xline_z if it is within grid bounds, otherwise revert to using the z-center of the box");

  CCTKi_ParameterCreate("out_xyplane_z",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "z-coord for 2D planes in xy",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_xyplane_z),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [zmin, zmax]");

  CCTKi_ParameterCreate("out_xyplane_zi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "z-index (from 0) for 2D planes in xy, overrrides IO::out_xyplane_z",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_xyplane_zi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, nz)",
                        "-1:", "Default to physical coordinate IO::out_xyplane_z if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_xyplane_z if it is within grid bounds, otherwise revert to using the z-center of the box");

  CCTKi_ParameterCreate("out_xzplane_y",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "y-coord for 2D planes in xz",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_xzplane_y),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [ymin, ymax]");

  CCTKi_ParameterCreate("out_xzplane_yi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "y-index (from 0) for 2D planes in xz, overrrides IO::out_xzplane_y",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_xzplane_yi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, ny)",
                        "-1:", "Default to physical coordinate IO::out_xzplane_y if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_xzplane_y if it is within grid bounds, otherwise revert to using the y-center of the box");

  CCTKi_ParameterCreate("out_yline_x",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "x-coord for 1D lines in y-direction",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_yline_x),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [xmin, xmax]");

  CCTKi_ParameterCreate("out_yline_xi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "x-index (from 0) for 1D lines in y-direction, overrides IO::out_yline_x",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_yline_xi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, nx)",
                        "-1:", "Default to physical coordinate IO::out_yline_x if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_yline_x if it is within grid bounds, otherwise revert to using the x-center of the box");

  CCTKi_ParameterCreate("out_yline_z",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "z-coord for 1D lines in y-direction",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_yline_z),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [zmin, zmax]");

  CCTKi_ParameterCreate("out_yline_zi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "z-index (from 0) for 1D lines in y-direction, overrides IO::out_yline_z",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_yline_zi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, nz)",
                        "-1:", "Default to physical coordinate IO::out_yline_z if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_yline_z if it is within grid bounds, otherwise revert to using the z-center of the box");

  CCTKi_ParameterCreate("out_yzplane_x",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "x-coord for 2D planes in yz",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_yzplane_x),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [xmin, xmax]");

  CCTKi_ParameterCreate("out_yzplane_xi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "x-index (from 0) for 2D planes in yz, overrrides IO::out_yzplane_x",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_yzplane_xi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, nx)",
                        "-1:", "Default to physical coordinate IO::out_yzplane_x if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_yzplane_x if it is within grid bounds, otherwise revert to using the x-center of the box");

  CCTKi_ParameterCreate("out_zline_x",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "x-coord for 1D lines in z-direction",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_zline_x),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [xmin, xmax]");

  CCTKi_ParameterCreate("out_zline_xi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "x-index (from 0) for 1D lines in z-direction, overrides IO::out_zline_x",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_zline_xi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, nx)",
                        "-1:", "Default to physical coordinate IO::out_zline_x if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_zline_x if it is within grid bounds, otherwise revert to using the x-center of the box");

  CCTKi_ParameterCreate("out_zline_y",
                        "IOUtil",
                        "REAL",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "y-coord for 1D lines in z-direction",
                        "0.0",
                        &(RESTRICTED_IO_STRUCT.out_zline_y),
                        0,
                        NULL,
                        1,
                        "*:*", "A value between [ymin, ymax]");

  CCTKi_ParameterCreate("out_zline_yi",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "y-index (from 0) for 1D lines in z-direction, overrides IO::out_zline_y",
                        "-2",
                        &(RESTRICTED_IO_STRUCT.out_zline_yi),
                        0,
                        NULL,
                        3,
                        "0:*", "An index between [0, ny)",
                        "-1:", "Default to physical coordinate IO::out_zline_y if it is within grid bounds, otherwise revert to using 0",
                        "-2:", "Default to physical coordinate IO::out_zline_y if it is within grid bounds, otherwise revert to using the y-center of the box");

  CCTKi_ParameterCreate("parfile_name",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Filename for the parameter file to be written",
                        "",
                        &(RESTRICTED_IO_STRUCT.parfile_name),
                        0,
                        NULL,
                        2,
                        ".+", "A valid filename",
                        "^$", "An empty string to choose the original parameter filename");

  CCTKi_ParameterCreate("parfile_update_every",
                        "IOUtil",
                        "INT",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "How often to update the parameter file for steered parameters",
                        "0",
                        &(RESTRICTED_IO_STRUCT.parfile_update_every),
                        0,
                        NULL,
                        2,
                        "1:*", "Every so many iterations",
                        "0:", "Disable updating");

  CCTKi_ParameterCreate("parfile_write",
                        "IOUtil",
                        "KEYWORD",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Write a parameter file to 'IO::out_dir'",
                        "copy",
                        &(RESTRICTED_IO_STRUCT.parfile_write),
                        0,
                        NULL,
                        3,
                        "no", "Do not write a parameter file",
                        "copy", "Copy the original parameter file",
                        "generate", "Generate a parameter file from the current settings");

  CCTKi_ParameterCreate("print_timing_info",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Print timing information on I/O operations.",
                        "no",
                        &(RESTRICTED_IO_STRUCT.print_timing_info),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("recover",
                        "IOUtil",
                        "KEYWORD",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Recover from a checkpoint file ?",
                        "no",
                        &(RESTRICTED_IO_STRUCT.recover),
                        0,
                        NULL,
                        4,
                        "no", "Don't recover",
                        "manual", "Recover from the checkpoint file as given in IO::recover_dir and IO::recover_file",
                        "auto", "Automatically recover from the latest checkpoint file found in <recover_dir>",
                        "autoprobe", "Probe for checkpoint files and automatically recover, continue as usual if nothing was found");

  CCTKi_ParameterCreate("recover_and_remove",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Remove checkpoint file after successful recovery ?",
                        "no",
                        &(RESTRICTED_IO_STRUCT.recover_and_remove),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("recover_dir",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Directory to look for recovery files",
                        ".",
                        &(RESTRICTED_IO_STRUCT.recover_dir),
                        0,
                        NULL,
                        1,
                        ".+", "A valid directory name");

  CCTKi_ParameterCreate("recover_file",
                        "IOUtil",
                        "STRING",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Basename of recovery file",
                        "checkpoint.chkpt",
                        &(RESTRICTED_IO_STRUCT.recover_file),
                        0,
                        NULL,
                        1,
                        ".+", "A valid filename");

  CCTKi_ParameterCreate("require_empty_output_directory",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Require that IO::out_dir is empty at startup ?",
                        "no",
                        &(RESTRICTED_IO_STRUCT.require_empty_output_directory),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("strict_io_parameter_check",
                        "IOUtil",
                        "BOOLEAN",
                        "RESTRICTED",
                        CCTK_STEERABLE_RECOVER,
                        "Stop on errors while parsing I/O parameters from parameter file ?",
                        "yes",
                        &(RESTRICTED_IO_STRUCT.strict_io_parameter_check),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("verbose",
                        "IOUtil",
                        "KEYWORD",
                        "RESTRICTED",
                        CCTK_STEERABLE_ALWAYS,
                        "Level of screen output for I/O",
                        "standard",
                        &(RESTRICTED_IO_STRUCT.verbose),
                        0,
                        NULL,
                        3,
                        "none", "No output",
                        "standard", "Initial description for each I/O method",
                        "full", "Maximal output");

  CCTKi_ParameterCreate("truncate_files",
                        "IOUtil",
                        "BOOLEAN",
                        "PRIVATE",
                        CCTK_STEERABLE_ALWAYS,
                        "Truncate existing output files from previous runs (except when recovering) ?",
                        "yes",
                        &(PRIVATE_IOUTIL_STRUCT.truncate_files),
                        0,
                        NULL,
                        0);

  CCTKi_ParameterCreate("truncate_files_after_recovering",
                        "IOUtil",
                        "BOOLEAN",
                        "PRIVATE",
                        CCTK_STEERABLE_RECOVER,
                        "Truncate existing output files after recovering ?",
                        "no",
                        &(PRIVATE_IOUTIL_STRUCT.truncate_files_after_recovering),
                        0,
                        NULL,
                        0);

  return 0;
}

int CCTKi_BindingsIOUtilParameterExtensions(void);
int CCTKi_BindingsIOUtilParameterExtensions(void)
{
  return 0;
}
