#!/bin/bash

(
	cd Event;
	make;
	./a.out || exit 1;
) || exit 1

(
	cd HdlCollector;
	make;
	./a.out || exit 1;
) || exit 1
