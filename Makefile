compile_flags=-g -Werror -Wall -Wclobbered -Wempty-body -Wignored-qualifiers -Wmissing-field-initializers -Wtype-limits -Wuninitialized -Wshift-negative-value

include_dir=-I dependencies/includes
library_dir=-L dependencies/lib
libraries=-lglfw3 -lgdi32
pre_processor=-D GLFW_INCLUDE_NONE
obj_files=build/main.o build/window.o build/camera.o build/input.o build/draw.o build/light.o build/math.o build/mesh.o build/shader.o build/timer.o build/stb_image.o build/texture.o build/glad.o build/entity.o build/config.o
exec_name=build/demo
all: $(exec_name)

build/main.o: src/main.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/main.cpp -o build/main.o

build/window.o: src/window.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/window.cpp -o build/window.o

build/camera.o: src/camera.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/camera.cpp -o build/camera.o

build/draw.o: src/draw.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/draw.cpp -o build/draw.o

build/input.o: src/input.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/input.cpp -o build/input.o

build/light.o: src/light.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/light.cpp -o build/light.o

build/math.o: src/math.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/math.cpp -o build/math.o

build/mesh.o: src/mesh.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/mesh.cpp -o build/mesh.o

build/shader.o: src/shader.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/shader.cpp -o build/shader.o 

build/timer.o: src/timer.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/timer.cpp -o build/timer.o

build/stb_image.o: src/stb_image.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/stb_image.cpp -o build/stb_image.o

build/texture.o: src/texture.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/texture.cpp -o build/texture.o

build/glad.o: src/glad.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/glad.cpp -o build/glad.o

build/entity.o: src/entity.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/entity.cpp -o build/entity.o

build/config.o: src/config.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/config.cpp -o build/config.o

$(exec_name): $(obj_files)
	g++ $(compile_flags) -o $@ $(obj_files) $(include_dir) $(library_dir) $(libraries) $(pre_processor)

clean:
	rm build/*.o