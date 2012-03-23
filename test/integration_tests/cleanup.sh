#!/bin/bash
msg()
{
    if [ $VERBOSE -eq 1 ]
    then
        echo "$1"
    fi
}

msg "Starting cleanup script"
msg
msg "Deleting directory structure $TEST_DIRECTORY"
chmod +r+x $TEST_DIRECTORY/*
rm -rf $TEST_DIRECTORY
exit 0


