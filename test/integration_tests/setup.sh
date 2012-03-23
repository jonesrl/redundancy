#!/bin/bash

# when determining if a file is readable, this table represents all of the
# meaningful combinations of permissions (i hope)
# directory is readable     directory is executable     file is readable
# 0                         0                            0
# 0                         0                            1
# 0                         1                            0
# 0                         1                            1
# 1                         0                            0
# 1                         0                            1
# 1                         1                            0
# 1                         1                            1

msg()
{
    if [ $VERBOSE -eq 1 ]
    then
        echo "$1"
    fi
}

msg "Starting setup script"
msg

msg "Creating test directory structure in $TEST_DIRECTORY"
mkdir $TEST_DIRECTORY
mkdir $TEST_DIRECTORY/non-readable_non-executable_directory
mkdir $TEST_DIRECTORY/non-readable_executable_directory
mkdir $TEST_DIRECTORY/readable_executable_directory
mkdir $TEST_DIRECTORY/readable_non-executable_directory


msg "Creating files within test directory structure"
touch $TEST_DIRECTORY/non-readable_non-executable_directory/readable_file
touch $TEST_DIRECTORY/non-readable_non-executable_directory/nonreadable_file

touch $TEST_DIRECTORY/non-readable_executable_directory/readable_file
touch $TEST_DIRECTORY/non-readable_executable_directory/nonreadable_file

touch $TEST_DIRECTORY/readable_executable_directory/readable_file
touch $TEST_DIRECTORY/readable_executable_directory/nonreadable_file

touch $TEST_DIRECTORY/readable_non-executable_directory/readable_file
touch $TEST_DIRECTORY/readable_non-executable_directory/nonreadable_file

touch $TEST_DIRECTORY/readable_executable_directory/readable_file
touch $TEST_DIRECTORY/readable_executable_directory/nonreadable_file

msg "Creating symlinks"
ln -s $TEST_DIRECTORY/readable_executable_directory/readable_file $TEST_DIRECTORY/link_to_readable_file
ln -s $TEST_DIRECTORY/readable_executable_directory/nonreadable_file $TEST_DIRECTORY/link_to_nonreadable_file

msg "Setting file permissions within test directory structure"
chmod +r $TEST_DIRECTORY/non-readable_non-executable_directory/readable_file
chmod -r $TEST_DIRECTORY/non-readable_non-executable_directory/nonreadable_file

chmod +r $TEST_DIRECTORY/non-readable_executable_directory/readable_file
chmod -r $TEST_DIRECTORY/non-readable_executable_directory/nonreadable_file

chmod +r $TEST_DIRECTORY/readable_executable_directory/readable_file
chmod -r $TEST_DIRECTORY/readable_executable_directory/nonreadable_file

chmod +r $TEST_DIRECTORY/readable_non-executable_directory/readable_file
chmod -r $TEST_DIRECTORY/readable_non-executable_directory/nonreadable_file

chmod +r $TEST_DIRECTORY/readable_executable_directory/readable_file
chmod -r $TEST_DIRECTORY/readable_executable_directory/nonreadable_file

msg "Setting directory permissions within test directory structure"
chmod -r-x $TEST_DIRECTORY/non-readable_non-executable_directory
chmod -r+x $TEST_DIRECTORY/non-readable_executable_directory
chmod +r+x $TEST_DIRECTORY/readable_executable_directory
chmod +r-x $TEST_DIRECTORY/readable_non-executable_directory
chmod +r+x $TEST_DIRECTORY/readable_executable_directory

msg
msg "Setup script complete"
exit 0
