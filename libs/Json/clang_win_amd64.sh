#!/bin/bash

docker run --rm \
	-it \
	--privileged \
	-v $(pwd):/src \
	-v winLib:/winLib \
		windows_clang clang $@