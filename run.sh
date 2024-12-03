#!/usr/bin/bash 

bash build.sh
lastExitCode=$?
if [ $lastExitCode != 0 ]; then
    exit $lastExitCode
fi

echo "Run: Running main..."
./main
echo "Run: Finished! Exit Code $?"