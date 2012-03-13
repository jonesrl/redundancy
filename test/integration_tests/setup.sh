#!/bin/bash

# when determining if a file is a valid scan target, this table represents all of the
# meaningful combinations of permissions
# directory is readable     directory is executable     file is readable
# 0                         0                            0
# 0                         0                            1
# 0                         1                            1
# 0                         1                            1
# 1                         0                            1
# 1                         0                            1
# 1                         1                            1
# 1                         1                            1


echo "Starting setup script"
echo

echo "Creating test directory structure in $TEST_DIRECTORY"
mkdir $TEST_DIRECTORY
mkdir $TEST_DIRECTORY/non-readable_non-executable_directory
mkdir $TEST_DIRECTORY/non-readable_executable_directory
mkdir $TEST_DIRECTORY/readable_executable_directory
mkdir $TEST_DIRECTORY/readable_non-executable_directory


echo "Creating files within test directory structure"
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

echo "Setting file permissions within test directory structure"
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

echo "Setting directory permissions within test directory structure"
chmod -r-x $TEST_DIRECTORY/non-readable_non-executable_directory
chmod -r+x $TEST_DIRECTORY/non-readable_executable_directory
chmod +r+x $TEST_DIRECTORY/readable_executable_directory
chmod +r-x $TEST_DIRECTORY/readable_non-executable_directory
chmod +r+x $TEST_DIRECTORY/readable_executable_directory

echo
echo "Setup script complete"
exit 0
