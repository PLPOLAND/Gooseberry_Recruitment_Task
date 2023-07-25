# Color noise generator

## Description:
This is a simple color noise generator written in C++. Written as recruitment task.

## Usage:
You can use this program to generate color noise in 3 different colors: brown, pink and velvet. 
Generated noise is saved in CSV file. You can specify number of samples, sample rate in main.cpp file.
### Compilation:
```bash
make
```
### Running:

```bash
./ColorNoiseGenerator
``` 
### Cleaning (removing executable):
```bash
make clean
```

## Links:
- Brown noise resource: https://noisehack.com/generate-noise-web-audio-api/
- Pink noise resource: https://www.firstpr.com.au/dsp/pink-noise/
- Valvet noise resource: https://www.researchgate.net/publication/260701331_A_Perceptual_Study_on_Velvet_Noise_and_Its_Variants_at_Different_Pulse_Densities 
- CSVWriter library (BSD 2-Clause) copyright to: https://github.com/al-eax/CSVWriter
