BUILD_DIR = build
CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Release

build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake $(CMAKE_FLAGS) ..
	cd $(BUILD_DIR) && cmake --build .

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build

test: rebuild
	cd $(BUILD_DIR) && ctest --output-on-failure 

test-verbose: rebuild
	cd $(BUILD_DIR) && ./knife_tests --gtest_catch_exceptions=0 --gtest_color=yes