#!/bin/bash
# TODO: This script will not run from the command-line, only from within QtCreator.
#       I am relying on the BUILD_DIRECTORY variable being the current directory, like it is in
#       QtCreator. Consider parsing command-line arguments to set some of these variables instead of
#       hard-coding it. If a variable is not passed in on the command-line, then let it default to the
#       values that QtCreator expects.

# the directory containing the project source code
echo current directory is $PWD
PROJECT_DIRECTORY=$HOME/Projects/jonesrl-redundancy

# the directory containing the integration tests
SCRIPT_DIRECTORY=$PROJECT_DIRECTORY/test/integration_tests

# the build directory -- the following assumes that the script is running from qtcreator
# the advantage of using pwd is that when the debug and release builds are created in separate
# direcories, this will still work
BUILD_DIRECTORY=`pwd`

# the directory containing the integration_tests executable
EXE_DIRECTORY=$BUILD_DIRECTORY/test/integration_tests

# the test directory where fake files and directories are created
# this variable is used by setup.sh and cleanup.sh
export TEST_DIRECTORY=`pwd`/test_directory

# delete the testing directory? 1 is yes, 0 is no
DO_CLEANUP=0

# print messages to stdout describing what is happening in the script? 1 is yes, 0 is no
export VERBOSE=0

msg()
{
    if [ $VERBOSE -eq 1 ]
    then
        echo "$1"
    fi
}

# call the cleanup script
if [ -d $TEST_DIRECTORY ]
then
    msg "Found test directory"
    if [ $DO_CLEANUP -eq 1 ]
    then
        msg "Cleaning up test directory"
        $SCRIPT_DIRECTORY/cleanup.sh
    else
        msg "Skipping cleanup"
    fi
fi

# call the setup script
if [ -d $TEST_DIRECTORY ]
then
    msg "Found test directory. Skipping setup"
else
    msg "Running setup script"
    $SCRIPT_DIRECTORY/setup.sh
    if [ $? -ne 0 ]
    then
        msg "setup failed. aborting integration tests"
        exit 1
    fi
fi

# run the integration tests
msg "Starting integration tests."
$EXE_DIRECTORY/integration_tests
msg "Integration tests complete."

# run the cleanup script
if [ -d $TEST_DIRECTORY ]
then
    if [ $DO_CLEANUP -eq 1 ]
    then
        msg "Running cleanup."
        $SCRIPT_DIRECTORY/cleanup.sh
        if [ $? -ne 0 ]
        then
            msg "Cleanup failed. Manual cleanup required."
        else
            msg "Cleanup complete."
        fi
     else
        msg "Skipping cleanup."
    fi
fi


