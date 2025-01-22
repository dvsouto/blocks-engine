#!/bin/bash

# Get the directory of the script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd $SCRIPT_DIR/../ && pwd)"

# TODO Select shaderc by platfrom
SHADERC_COMPILER_PATH="$ROOT_DIR/vcpkg_installed/x64-osx/tools/bgfx/shaderc"
SHADERC_COMPILER_INCLUDE_PATH="$ROOT_DIR/vcpkg_installed/x64-osx/include/bgfx"
SHADERS_PATH="$ROOT_DIR/assets/shaders"
BIN_PATH="$ROOT_DIR/assets/shaders/bin"

# Create binary directories
mkdir -p $BIN_PATH/osx
mkdir -p $BIN_PATH/linux
mkdir -p $BIN_PATH/windows

# OSX
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/osx/vertex_color.opengl.bin --type vertex --verbose --profile 440 --platform osx -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/osx/vertex_color.metal.bin --type vertex --verbose --profile metal31-14 --platform osx -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/osx/vertex_color.vulkan.bin --type vertex --verbose --profile spirv16-13 --platform osx -i $SHADERC_COMPILER_INCLUDE_PATH

# Linux
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/linux/vertex_color.opengl.bin --type vertex --verbose --profile 440 --platform linux -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/linux/vertex_color.vulkan.bin --type vertex --verbose --profile spirv16-13 --platform linux -i $SHADERC_COMPILER_INCLUDE_PATH

# Windows
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/windows/vertex_color.opengl.bin --type vertex --verbose --profile 440 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/windows/vertex_color.vulkan.bin --type vertex --verbose --profile spirv16-13 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/windows/vertex_color.dx11.bin --type vertex --verbose --profile s_5_0 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/vertex_color.sc -o $BIN_PATH/windows/vertex_color.dx10.bin --type vertex --verbose --profile s_4_0 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH



# OSX
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/osx/fragment_color.opengl.bin --type fragment --verbose --profile 440 --platform osx -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/osx/fragment_color.metal.bin --type fragment --verbose --profile metal31-14 --platform osx -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/osx/fragment_color.vulkan.bin --type fragment --verbose --profile spirv16-13 --platform osx -i $SHADERC_COMPILER_INCLUDE_PATH

# Linux
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/linux/fragment_color.opengl.bin --type fragment --verbose --profile 440 --platform linux -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/linux/fragment_color.vulkan.bin --type fragment --verbose --profile spirv16-13 --platform linux -i $SHADERC_COMPILER_INCLUDE_PATH

# Windows
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/windows/fragment_color.opengl.bin --type fragment --verbose --profile 440 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/windows/fragment_color.vulkan.bin --type fragment --verbose --profile spirv16-13 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/windows/fragment_color.dx11.bin --type fragment --verbose --profile s_5_0 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH
$SHADERC_COMPILER_PATH -f $SHADERS_PATH/color/fragment_color.sc -o $BIN_PATH/windows/fragment_color.dx10.bin --type fragment --verbose --profile s_4_0 --platform windows -i $SHADERC_COMPILER_INCLUDE_PATH