@echo off

SET source_files=..\src\*.cpp ..\src\*.c
SET include_dir=..\dependencies\includes
SET library_dir=..\dependencies\lib
SET libraries=-lglfw3 -lgdi32
SET pre_processor_defines=GLFW_INCLUDE_NONE
SET debug_flags= -Werror -Wall -Wclobbered -Wempty-body -Wignored-qualifiers -Wmissing-field-initializers -Wtype-limits -Wuninitialized -Wshift-negative-value

IF NOT EXIST build mkdir build
pushd build

g++ %debug_flags% %source_files% -I %include_dir% -L %library_dir% %libraries%  -D %pre_processor_defines% -o demo
start demo

popd