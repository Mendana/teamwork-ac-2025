# 🖥 Proyecto Arquitectura de Computadores 2025

## Descripción
Este proyecto corresponde al **trabajo en grupo de Arquitectura de Computadores**, centrado en la **fase 1: Programa Monohilo**, con extensión futura a SIMD y multihilo.  
El objetivo es implementar filtros sobre imágenes y analizar mejoras de rendimiento usando distintas técnicas de programación.

**Integrantes:**  
- Díaz Mendaña, Diego
- García Pernas, Pablo
- Rama García, Mateo  
- Suárez Fernández, Fernando 

---

## 📂 Estructura del repositorio


---

## ⚙ Configuración de la VM

1. Usuario: `student`  
2. Contraseña: `teamwork`  
3. OS: Ubuntu Desktop 18.04.3 LTS (mínima)  
4. Software preinstalado: `build-essential`, `git`, `cimg-dev`, `openssh-server`  
5. IDE: Visual Studio Code con extensiones C/C++ y TODO Highlight  
6. Configuración recomendada:
   - CPU: máximo de núcleos posibles (mínimo 2)
   - Memoria: mínimo 3 GiB (o mitad de tu RAM si >6 GiB)
7. Instalar **Guest Additions** y reiniciar
8. Copiar imágenes de prueba a `/images`

---

## 🚀 Flujo de trabajo

### 1. Issues
- Cada tarea se abre como Issue con la plantilla adecuada:
  - 🧑‍💻 Código
  - 📄 Documentación
  - ✅ QA / Revisión
  - 🛠️ Infraestructura
- Los Issues se gestionan en el **Project Board**:
  - 🟢 To Do → 🟡 In Progress → 🔵 Review → ✅ Done

### 2. Ramas
- Rama principal: `main`  
- Cada tarea: `feature/nombre-tarea`  
- Ejemplo: `feature/mono-tiempos`

### 3. Pull Requests
- Crear PR desde la rama de la tarea a `main`
- Plantilla obligatoria: `.github/pull_request_template.md`
- Vincular Issue con `Closes #NUMERO`
- Al menos **1 compañero revisa** antes del merge

### 4. Documentación
- Guardar la memoria y capturas en `/docs`
- Cada sección puede estar vinculada a un Issue
- Tablas y resultados dentro de `/docs/data` o `/docs/screenshots`

---

## 🖼 Imágenes de prueba
- Descargar desde el enlace oficial y copiar en `/images`:
```bash
cd ~/Pictures
wget http://rigel.atc.uniovi.es/grado/2ac/2021-teamwork-images.tar.gz
tar xvfz 2021-teamwork-images.tar.gz
```


- Directorios:
  - `normal/`: imágenes con exposición correcta
  - `contrast/`: imágenes con alteración de contraste/exposición
  - `whitebalance/`: imágenes con alteración de balance de blancos
  - `backgrounds/`: fondos degradados para fusión

---

## 📌 Referencias
- [Guía de instrucciones intrínsecas Intel](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)
- [MMX y SSE Primer](https://www.tommesani.com/MMXPrimer.html)
- [Crunching Numbers con AVX](https://www.codeproject.com/Articles/874396/Crunching-Numbers-with-AVX-and-AVX)
- [Cheatsheet de instrucciones x86](https://db.in.tum.de/~finis/x86-intrin-cheatsheet-v2.2.pdf)

---

## 📖 Estado actual
- **Entrega 1 (Monohilo)**: en desarrollo
- **Entrega 2 (SIMD y Multihilo)**: pendiente  
- Todas las tareas están gestionadas mediante **GitHub Issues + Project Board**

---

## 📝 Notas
- Para ejecutar programas: compilar en modo Release con `make release` y ejecutar desde el directorio raíz:
```bash
release/single-thread

- Repetir el algoritmo si el tiempo de ejecución no está entre 8-15 segundos para mediciones válidas.

- Guardar resultados de tiempo, desviación típica y acelerar posteriores versiones (SIMD/multihilo).