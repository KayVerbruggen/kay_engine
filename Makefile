compile_flags=-g -Werror -Wall -Wclobbered -Wempty-body -Wignored-qualifiers -Wmissing-field-initializers -Wtype-limits -Wuninitialized -Wshift-negative-value

include_dir=-I dependencies/includes
library_dir=-L dependencies/lib
libraries=-lglfw3 -lgdi32
pre_processor=-D GLFW_INCLUDE_NONE
obj_files=build/main.o build/window.o build/camera.o build/input.o build/draw.o build/light.o build/math.o build/mesh.o build/shader.o build/timer.o build/stb_image.o build/texture.o build/glad.o build/entity.o
all: demo

main.o: src/main.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/main.cpp -o build/main.o

window.o: src/window.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/window.cpp -o build/window.o

camera.o: src/camera.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/camera.cpp -o build/camera.o

draw.o: src/draw.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/draw.cpp -o build/draw.o

input.o: src/input.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/input.cpp -o build/input.o

light.o: src/light.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/light.cpp -o build/light.o

math.o: src/math.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/math.cpp -o build/math.o

mesh.o: src/mesh.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/mesh.cpp -o build/mesh.o

shader.o: src/shader.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/shader.cpp -o build/shader.o 

timer.o: src/timer.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/timer.cpp -o build/timer.o

stb_image.o: src/stb_image.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/stb_image.cpp -o build/stb_image.o

texture.o: src/texture.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/texture.cpp -o build/texture.o

glad.o: src/glad.c
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/glad.c -o build/glad.o

entity.o: src/entity.cpp
	g++ $(compile_flags) $(include_dir) $(pre_processor) -c src/entity.cpp -o build/entity.o

demo: $(obj_files)
	g++ $(compile_flags) -o build/demo build/*.o $(include_dir) $(library_dir) $(libraries) $(pre_processor)

clean:
	rm build/*.o target