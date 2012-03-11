#!/bin/bash

# the directory containing the project source code
PROJECT_DIRECTORY=$HOME/redundancy

# the directory containing the integration tests
SCRIPT_DIRECTORY=$PROJECT_DIRECTORY/test/integration_tests

# the build directory containing the integration_tests executable
BUILD_DIRECTORY=$HOME/redundancy-build-desktop-Qt_4_7_4_in_PATH__System__Release/test/integration_tests

# call the setup script
$SCRIPT_DIRECTORY/setup.sh
if [ $? -ne 0 ]
then
    echo "setup failed. aborting integration tests"
    exit 1
fi


# if setup ran successfully, run the integration tests
$BUILD_DIRECTORY/integration_tests

if [ $? -ne 0 ]
then
    echo "integration_tests failed. aborting."
    exit 1
fi
# if the integration tests ran successfully, run the cleanup script
# or maybe I should clean up anyway...
$SCRIPT_DIRECTORY/cleanup.sh

if [ $? -ne 0 ]
then
    echo "clean failed. manually clean up."
    exit 1
fi
