#!/bin/bash

# the directory containing the project source code
PROJECT_DIRECTORY=$HOME/redundancy

# the directory containing the integration tests
SCRIPT_DIRECTORY=$PROJECT_DIRECTORY/test/integration_tests

# the build directory containing the integration_tests executable
BUILD_DIRECTORY=$HOME/redundancy-build-desktop-Qt_4_7_4_in_PATH__System__Release/test/integration_tests

# the test directory where fake files and directories are created
# this variable is used by setup.sh and cleanup.sh
export TEST_DIRECTORY=`pwd`/test_directory

# make sure that any prior test runs are cleaned up
if [ -d $TEST_DIRECTORY ]
then
    echo "Test directory found from prior run. Cleaning up"
    $SCRIPT_DIRECTORY/cleanup.sh
fi

# call the setup script
$SCRIPT_DIRECTORY/setup.sh
if [ $? -ne 0 ]
then
    echo "setup failed. aborting integration tests"
    exit 1
fi


# if setup ran successfully, run the integration tests
$BUILD_DIRECTORY/integration_tests

# should I continue anyway if the tests failed? seems better to get a clean start everytime
if [ $? -ne 0 ]
then
    echo "integration_tests failed. aborting."
#    exit 1
fi

# run the cleanup script
if [ -d $TEST_DIRECTORY ]
then
    $SCRIPT_DIRECTORY/cleanup.sh
fi

if [ $? -ne 0 ]
then
    echo "clean failed. manually clean up."
    exit 1
fi
