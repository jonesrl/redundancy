#!/bin/bash

./e.sh

if [ $? -eq 0 ]
then
    echo "success"
else
    echo "failed"
fi

