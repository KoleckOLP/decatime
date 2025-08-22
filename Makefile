# This Makefile is designed to be as straightforward as possible,
# following a strict, sequential build order.

# The `all` target runs first. It depends on targets for `folder1` and `folder2`.
# The `.` before `PHONY` is important and means this is a phony target.
.PHONY: all
all: build_folders

# A target to build all folders in a specific order.
# The `&&` ensures that the second command only runs if the first one succeeds.
.PHONY: build_folders
build_folders:
	@echo "--- Building realtime project ---"
	$(MAKE) -C realtime
	@echo "--- Building converter project ---"
	$(MAKE) -C converter

# The `clean` target runs the `clean` command in each subdirectory.
# This ensures that all generated files are removed from both folders.
.PHONY: clean
clean:
	@echo "--- Cleaning up all projects ---"
	$(MAKE) -C realtime clean
	$(MAKE) -C converter clean
