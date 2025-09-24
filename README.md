# 🖥️ Proyecto Arquitectura de Computadores 2025

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)]()
[![License](https://img.shields.io/badge/license-MIT-blue)]()
[![Version](https://img.shields.io/badge/version-1.0.0-orange)]()

## 📖 Descripción del proyecto

Este proyecto corresponde al **trabajo en grupo de Arquitectura de Computadores** de la Universidad de Oviedo, curso 2024-2025. El objetivo principal es **implementar y optimizar filtros de procesamiento de imágenes** utilizando diferentes paradigmas de programación para analizar mejoras de rendimiento.

### 🎯 Objetivos principales
- **Implementar filtros de imagen** con diferentes técnicas de optimización
- **Analizar rendimiento** comparando versiones monohilo, SIMD y multihilo
- **Aplicar buenas prácticas** de desarrollo colaborativo y documentación técnica
- **Evaluar técnicas de paralelización** y optimización de código

### 📈 Fases del proyecto
1. **🔄 Fase 1: Implementación Monohilo** *(en desarrollo)*
   - Desarrollo de algoritmos base secuenciales
   - Establecimiento de benchmarks de referencia
   - Análisis de rendimiento baseline

2. **⚡ Fase 2: Optimización SIMD** *(planificada)*
   - Paralelización a nivel de datos con instrucciones vectoriales
   - Uso de extensiones SSE, AVX para optimización
   - Comparación de rendimiento vs. versión monohilo

3. **🧵 Fase 3: Paralelización Multihilo** *(planificada)*
   - Implementación con múltiples threads
   - Análisis de escalabilidad y overhead
   - Evaluación de diferentes estrategias de paralelización

### 👥 Equipo de desarrollo
| Miembro | Rol principal | GitHub |
|---------|---------------|---------|
| **Díaz Mendaña, Diego** | Project Lead & Backend Developer | [@usuario] |
| **García Pernas, Pablo** | SIMD Specialist & Performance Analyst | [@usuario] |
| **Rama García, Mateo** | Infrastructure & Testing Lead | [@usuario] |
| **Suárez Fernández, Fernando** | Documentation & QA Manager | [@usuario] |

---

## 🏗️ Arquitectura del proyecto

### 📂 Estructura del repositorio

```
teamwork-ac-2025/
├── 📁 src/                     # Código fuente principal
│   ├── 📄 main.c              # Punto de entrada del programa
│   ├── 📄 image_filters.c     # Implementación de filtros
│   ├── 📄 image_filters.h     # Headers y definiciones
│   ├── 📄 benchmark.c         # Utilidades de medición
│   └── 📄 utils.c             # Funciones auxiliares
├── 📁 include/                 # Headers públicos
├── 📁 test/                    # Tests unitarios y de integración
│   ├── 📄 test_filters.c      # Tests de filtros
│   └── 📄 test_performance.c  # Tests de rendimiento
├── 📁 data/                    # Datos de prueba y resultados
│   ├── 📁 images/             # Imágenes de test
│   └── 📁 benchmarks/         # Resultados de benchmarks
├── 📁 docs/                    # Documentación del proyecto
│   ├── 📄 memoria.md          # Memoria técnica principal
│   ├── 📄 workflow.md         # Flujo de trabajo del equipo
│   ├── 📁 screenshots/        # Capturas de pantalla
│   ├── 📁 diagrams/           # Diagramas técnicos
│   └── 📁 benchmarks/         # Análisis de rendimiento
├── 📁 scripts/                 # Scripts de automatización
│   ├── 📄 setup.sh            # Configuración del entorno
│   ├── 📄 benchmark.sh        # Ejecución de benchmarks
│   └── 📄 build.sh            # Script de compilación
├── 📁 .github/                 # Configuración de GitHub
│   ├── 📁 ISSUE_TEMPLATE/     # Plantillas de issues
│   ├── 📄 pull_request_template.md
│   └── 📁 workflows/          # CI/CD (futuro)
├── 📄 Makefile                 # Sistema de build
├── 📄 README.md               # Este archivo
├── 📄 LICENSE                 # Licencia del proyecto
└── 📄 .gitignore              # Archivos a ignorar por git
```


---

## 🛠️ Configuración del entorno de desarrollo

### 📋 Requisitos del sistema

#### Especificaciones de la VM
- **Sistema Operativo:** Ubuntu Desktop 18.04.3 LTS (instalación mínima)
- **Usuario por defecto:** `student`
- **Contraseña:** `teamwork`
- **Configuración de hardware recomendada:**
  - **CPU:** Máximo de núcleos disponibles (mínimo 2 cores)
  - **RAM:** Mínimo 3 GiB (recomendado: mitad de RAM disponible si >6 GiB)
  - **Almacenamiento:** Mínimo 20 GB de espacio libre

#### Software preinstalado
- ✅ `build-essential` - Herramientas de compilación
- ✅ `git` - Control de versiones
- ✅ `cimg-dev` - Librería de procesamiento de imágenes CImg
- ✅ `openssh-server` - Servidor SSH para acceso remoto
- ✅ **Visual Studio Code** con extensiones:
  - C/C++ IntelliSense
  - TODO Highlight
  - GitLens (recomendado)

### ⚙️ Configuración inicial

#### 1. Configuración de la VM
```bash
# Actualizar el sistema
sudo apt update && sudo apt upgrade -y

# Instalar dependencias adicionales (si es necesario)
sudo apt install -y htop valgrind gdb

# Configurar Git (personalizar con tus datos)
git config --global user.name "Tu Nombre"
git config --global user.email "tu.email@uniovi.es"
```

#### 2. Instalación de Guest Additions
1. Insertar CD de Guest Additions desde el menú de VirtualBox
2. Ejecutar desde terminal:
```bash
sudo sh /media/$USER/VBox*/VBoxLinuxAdditions.run
sudo reboot
```

#### 3. Clonar el repositorio
```bash
cd ~/Desktop
git clone https://github.com/Mendana/teamwork-ac-2025.git
cd teamwork-ac-2025
```

#### 4. Configuración de imágenes de prueba
```bash
# Crear directorio para imágenes
mkdir -p ~/images

# Descargar imágenes oficiales del curso
cd ~/images
wget http://rigel.atc.uniovi.es/grado/2ac/2021-teamwork-images.tar.gz
tar xvfz 2021-teamwork-images.tar.gz

# Verificar estructura
ls -la ~/images/
```

---

## 🚀 Guía de desarrollo

### 📋 Flujo de trabajo (Git Flow)

#### 1. 📝 Gestión de tareas con Issues
Cada tarea del proyecto se gestiona mediante **GitHub Issues** utilizando plantillas específicas:

- **🧑‍💻 Código** - Para implementación y modificación de código
- **📄 Documentación** - Para escritura y actualización de documentación
- **✅ QA/Revisión** - Para revisión de código y testing
- **🛠️ Infraestructura** - Para configuración y setup del entorno
- **� Bug Report** - Para reportar errores y problemas
- **� Feature Request** - Para proponer nuevas funcionalidades

#### 2. 🌿 Estrategia de branching
```
main                    # Rama principal (producción)
├── feature/nombre      # Nuevas funcionalidades
├── bugfix/descripcion  # Corrección de errores
├── docs/seccion        # Documentación
└── infra/setup         # Configuración e infraestructura
```

**Convención de nomenclatura:**
- `feature/filtro-median` - Nueva funcionalidad
- `bugfix/memory-leak-filters` - Corrección de bug
- `docs/memoria-resultados` - Documentación
- `infra/vm-setup-guide` - Infraestructura

#### 3. 🔄 Workflow de desarrollo

```mermaid
graph LR
    A[Issue creado] --> B[Crear rama feature/*]
    B --> C[Desarrollo + commits]
    C --> D[Push a GitHub]
    D --> E[Crear Pull Request]
    E --> F[Code Review]
    F --> G[Merge a main]
    G --> H[Cerrar Issue]
```

**Pasos detallados:**
1. **Crear issue** usando plantilla apropiada
2. **Crear rama** desde `main`:
   ```bash
   git checkout main
   git pull origin main
   git checkout -b feature/nombre-tarea
   ```
3. **Desarrollar** con commits atómicos y descriptivos
4. **Push** y crear **Pull Request** vinculado al issue
5. **Code Review** por al menos 1 compañero
6. **Merge** después de aprobación y tests

### 🏗️ Sistema de build

#### Compilación básica
```bash
# Compilación en modo debug (desarrollo)
make debug

# Compilación optimizada (benchmarks)
make release

# Limpieza de archivos compilados
make clean

# Ejecutar tests
make test
```

#### Estructura del Makefile
- **Debug mode:** Compilación con símbolos de debug (`-g -O0`)
- **Release mode:** Compilación optimizada (`-O3 -DNDEBUG`)
- **Flags de warning:** `-Wall -Wextra -Wpedantic`
- **Estándar C:** `-std=c99`

---

## 🧪 Testing y validación

### 🎯 Estrategia de testing

#### Tipos de tests implementados
- **Tests unitarios** - Validación de funciones individuales
- **Tests de integración** - Verificación de interacción entre módulos
- **Tests de rendimiento** - Benchmarks y análisis de performance
- **Tests de regresión** - Prevención de errores en nuevas versiones

#### Ejecución de tests
```bash
# Ejecutar todos los tests
make test

# Tests específicos
./test/test_filters
./test/test_performance

# Tests con Valgrind (detección de memory leaks)
make test-valgrind
```

### � Benchmarking

#### Criterios de medición
- **Tiempo de ejecución objetivo:** 8-15 segundos para mediciones válidas
- **Métricas recolectadas:**
  - Tiempo promedio de ejecución
  - Desviación estándar
  - Uso de memoria (RSS/VSize)
  - Uso de CPU
  - Cache misses (con `perf`)

#### Ejecución de benchmarks
```bash
# Benchmark completo
./scripts/benchmark.sh

# Benchmark específico con repeticiones
./release/programa --benchmark --iterations=10

# Profiling con perf
perf stat -e cache-misses,cache-references ./release/programa
```

---

## 📊 Datasets y recursos

### 🖼️ Imágenes de prueba

La suite de imágenes oficial incluye diferentes categorías para testing exhaustivo:

#### Estructura de directorios de imágenes
```
~/images/
├── 📁 normal/          # Imágenes con exposición correcta
│   ├── 🖼️ landscape1.jpg    # Paisajes de prueba
│   ├── 🖼️ portrait1.jpg     # Retratos de prueba
│   └── 🖼️ objects1.jpg      # Objetos diversos
├── 📁 contrast/        # Imágenes con alteración de contraste
│   ├── 🖼️ high_contrast1.jpg
│   └── 🖼️ low_contrast1.jpg
├── 📁 whitebalance/    # Alteración de balance de blancos
│   ├── 🖼️ warm_tone1.jpg
│   └── 🖼️ cool_tone1.jpg
└── 📁 backgrounds/     # Fondos degradados para fusión
    ├── 🖼️ gradient1.jpg
    └── 🖼️ texture1.jpg
```

#### Características técnicas de las imágenes
- **Formatos soportados:** JPG, PNG, BMP
- **Resoluciones típicas:** 1920x1080, 1280x720, 800x600
- **Profundidad de color:** 24-bit RGB
- **Tamaño de dataset:** ~50MB total

### 📈 Resultados esperados

#### Métricas de rendimiento por fase
| Fase | Tiempo objetivo | Speedup esperado | Uso memoria |
|------|-----------------|------------------|-------------|
| Monohilo | 10-15s | 1.0x (baseline) | < 512MB |
| SIMD | 3-5s | 3-4x | < 512MB |
| Multihilo | 2-4s | 4-8x | < 1GB |

---

## 📚 Referencias técnicas

### 🔗 Documentación oficial
- **[Intel Intrinsics Guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)** - Referencia completa de instrucciones SIMD
- **[CImg Library Documentation](http://cimg.eu/)** - Documentación de la librería de procesamiento de imágenes
- **[GNU Make Manual](https://www.gnu.org/software/make/manual/)** - Guía del sistema de build

### 📖 Recursos de aprendizaje
- **[MMX y SSE Primer](https://www.tommesani.com/MMXPrimer.html)** - Introducción a programación SIMD
- **[Crunching Numbers con AVX](https://www.codeproject.com/Articles/874396/Crunching-Numbers-with-AVX-and-AVX)** - Optimización con instrucciones AVX
- **[x86 Intrinsics Cheatsheet](https://db.in.tum.de/~finis/x86-intrin-cheatsheet-v2.2.pdf)** - Referencia rápida de instrucciones

### 🛠️ Herramientas de desarrollo
- **GDB** - Debugging de aplicaciones C/C++
- **Valgrind** - Detección de memory leaks y profiling
- **Perf** - Profiling de rendimiento a nivel de sistema
- **Htop** - Monitor de recursos del sistema

---

## 🎯 Estado del proyecto y roadmap

### 📅 Timeline de desarrollo

#### Sprint 1: Infraestructura y Setup ✅
- [x] Configuración de VM y herramientas
- [x] Setup del repositorio y plantillas
- [x] Descarga e integración de imágenes de prueba
- [x] Sistema de build básico

#### Sprint 2: Implementación Monohilo 🔄 *(en progreso)*
- [ ] Implementación de filtros básicos
- [ ] Sistema de benchmarking
- [ ] Tests unitarios
- [ ] Documentación de algoritmos

#### Sprint 3: Optimización SIMD 📋 *(planificado)*
- [ ] Análisis de vectorización
- [ ] Implementación con instrucciones SSE/AVX
- [ ] Comparativas de rendimiento
- [ ] Optimización de memory layout

#### Sprint 4: Paralelización Multihilo 📋 *(planificado)*
- [ ] Diseño de estrategia de threading
- [ ] Implementación con pthreads/OpenMP
- [ ] Análisis de escalabilidad
- [ ] Benchmarking final

### 🏆 Criterios de éxito
- **Funcionalidad:** Todos los filtros implementados correctamente
- **Rendimiento:** Speedups >= objetivos planificados
- **Calidad:** Cobertura de tests > 80%
- **Documentación:** Memoria técnica completa y profesional

---

## 🤝 Contribución al proyecto

### 📋 Guías de contribución

#### Para miembros del equipo
1. **Seguir el workflow** definido con issues y PRs
2. **Usar las plantillas** correspondientes para cada tipo de tarea
3. **Escribir commits descriptivos** siguiendo conventional commits
4. **Realizar code review** exhaustivo antes de merge
5. **Mantener documentación** actualizada

#### Ejemplo de commit message
```
feat(filters): implementar filtro de mediana optimizado

- Añadir implementación eficiente con sorting network
- Incluir tests unitarios para diferentes tamaños de kernel
- Documentar complejidad temporal y uso de memoria

Closes #15
```

### 🔍 Code Review Guidelines
- **Funcionalidad:** ¿El código hace lo que debe hacer?
- **Rendimiento:** ¿Es eficiente la implementación?
- **Legibilidad:** ¿Es fácil de entender y mantener?
- **Testing:** ¿Están cubiertas las funcionalidades críticas?
- **Documentación:** ¿Están documentados los cambios importantes?

---

## 📞 Soporte y contacto

### 🚨 Reporte de problemas
- **Bugs críticos:** Usar plantilla de Bug Report en Issues
- **Dudas técnicas:** GitHub Discussions
- **Propuestas:** Feature Request template

### 👥 Contacto del equipo
Para consultas académicas o colaboración:
- **Email institucional:** [usuario]@uniovi.es
- **Discord del equipo:** #teamwork-ac-2025

### 📖 Recursos adicionales
- **[Wiki del proyecto](https://github.com/Mendana/teamwork-ac-2025/wiki)** - Documentación técnica extendida
- **[Project Board](https://github.com/Mendana/teamwork-ac-2025/projects)** - Seguimiento de tareas
- **[Releases](https://github.com/Mendana/teamwork-ac-2025/releases)** - Versiones del software

---

## 📄 Licencia

Este proyecto está licenciado bajo la MIT License - ver el archivo [LICENSE](LICENSE) para más detalles.

---

## 🏅 Reconocimientos

- **Universidad de Oviedo** - Escuela de Ingeniería Informática
- **Departamento de Informática** - Cátedra de Arquitectura de Computadores
- **Profesores:** Por la guía y recursos proporcionados
- **Comunidad Open Source** - Por las herramientas y librerías utilizadas

---

*Última actualización: Septiembre 2025*