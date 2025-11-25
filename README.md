# Proyecto Arquitectura de Computadores 2025

## Descripción

Proyecto de optimización de procesamiento de imágenes desarrollado para la asignatura de Arquitectura de Computadores de la Universidad de Oviedo, curso 2024-2025. Implementa un filtro de inversión de blancos y negros mediante tres aproximaciones: monohilo, SIMD y multihilo.

### Algoritmo implementado

Filtro de inversión B&W (algoritmo #3):
1. Conversión a escala de grises: `L(i) = 0.3*R(i) + 0.59*G(i) + 0.11*B(i)`
2. Inversión: `L(i) = 255 - L(i)`

## Estructura del proyecto

```
teamwork-ac-2025/
├── src/
│   ├── 2acuniovi-single-thread/    # Implementación monohilo
│   │   ├── main.cpp
│   │   └── Makefile
│   ├── 2acuniovi-simd/             # Implementación SIMD (SSE2)
│   │   ├── main.cpp
│   │   └── Makefile
│   └── 2acuniovi-multi-thread/     # Implementación multihilo (pthreads)
│       ├── main.cpp
│       └── Makefile
├── data/
│   ├── files/                       # Información del sistema
│   ├── pictures/                    # Imágenes de prueba
│   │   ├── backgrounds/
│   │   ├── contrast/
│   │   ├── normal/
│   │   └── whitebalance/
│   └── xlsx/                        # Resultados de benchmarks
├── docs/
│   ├── workflow.md                  # Flujo de trabajo del equipo
│   └── memoria/                     # Documentación técnica
└── LICENSE
```

## Implementaciones

### 1. Versión monohilo

Implementación secuencial básica que procesa píxel a píxel aplicando la fórmula del filtro.

```bash
cd src/2acuniovi-single-thread
make release
./release/single-thread
```

### 2. Versión SIMD

Optimización mediante instrucciones SSE2 (`__m128d`) que procesa 2 píxeles simultáneamente (datos tipo `double`). Utiliza:
- `_mm_loadu_pd`: Carga de datos no alineados
- `_mm_mul_pd`, `_mm_fmadd_pd`: Operaciones aritméticas vectorizadas
- `_mm_sub_pd`: Sustracción vectorial para la inversión
- Alineamiento de memoria a 16 bytes (`_mm_malloc`)

```bash
cd src/2acuniovi-simd
make release
./release/simd
```

### 3. Versión multihilo

Paralelización con pthreads distribuyendo el procesamiento de píxeles entre 8 threads. Cada thread procesa un segmento independiente de la imagen.

```bash
cd src/2acuniovi-multi-thread
make release
./release/multi-thread
```

## Compilación

Cada implementación incluye un Makefile con dos modos:

- **Debug**: `make debug` - Compila con símbolos de depuración (`-g3`)
- **Release**: `make release` - Compila sin optimización (`-O0`) para benchmarking preciso

Flags comunes:
- `-Wall`: Advertencias completas
- `-fno-tree-vectorize`: Desactiva auto-vectorización del compilador (single-thread)
- Librerías: `-lpthread -lm -lX11`

## Benchmarking

Cada programa ejecuta el filtro 250 iteraciones y mide el tiempo total con `clock_gettime(CLOCK_REALTIME)`. Los resultados se imprimen en segundos.

## Dependencias

- **Compilador**: g++ con soporte C++11
- **Librerías**:
  - CImg (`cimg-dev`): Procesamiento de imágenes
  - pthread: Multihilo
  - X11: Visualización de imágenes
- **Sistema operativo**: Linux (probado en Ubuntu 18.04.3 LTS)

## Uso

1. Colocar la imagen `bailarina.bmp` en el directorio de cada implementación
2. Compilar con `make release`
3. Ejecutar el binario generado en `release/`
4. La imagen procesada se guarda como `bailarina2.bmp`

## Documentación adicional

- `docs/workflow.md`: Flujo de trabajo del equipo y metodología de desarrollo
- `docs/memoria/`: Memoria técnica del proyecto con análisis de rendimiento

## Licencia

Este proyecto está licenciado bajo la MIT License. Ver archivo [LICENSE](LICENSE) para más detalles.