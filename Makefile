all:
	g++ -o main.o -c ./src/main.cpp
	g++ -o NoiseGenerator.o -c ./src/NoiseGenerator.cpp
	g++ -o WhiteNoise.o -c ./src/WhiteNoiseGenerator.cpp
	g++ -o BrownNoise.o -c ./src/BrownNoiseGenerator.cpp
	g++ -o NoiseToCSV.o -c ./src/NoiseToCSVWriter.cpp
	g++ -o PinkNoise.o -c ./src/PinkNoiseGenerator.cpp
	g++ -o VelvetNoise.o -c ./src/VelvetNoiseGenerator.cpp

	g++ main.o NoiseGenerator.o WhiteNoise.o BrownNoise.o NoiseToCSV.o PinkNoise.o VelvetNoise.o -o ColorNoiseGenerator
	rm -rf *.o

clean:
	rm -rf ColorNoiseGenerator