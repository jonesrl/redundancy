#!/bin/bash

echo "Starting cleanup script"
echo

echo "Deleting directory structure $TEST_DIRECTORY"
chmod +r+x $TEST_DIRECTORY/*
rm -rf $TEST_DIRECTORY
exit 0


