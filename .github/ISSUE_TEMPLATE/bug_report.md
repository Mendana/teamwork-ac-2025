---
name: "🐛 Reporte de error"
about: "Reportar un error, bug o comportamiento inesperado en el código"
title: "[BUG] "
labels: ["bug", "error", "investigación"]
assignees:
---

## 🐛 Descripción del error

### Resumen del problema
<!-- Describe de forma clara y concisa cuál es el error -->

### Comportamiento esperado
<!-- Explica qué debería ocurrir en condiciones normales -->

### Comportamiento actual
<!-- Describe qué está ocurriendo en su lugar -->

### Impacto del error
- [ ] 🔴 **Crítico** - Bloquea funcionalidad principal o causa crashes
- [ ] 🟠 **Alto** - Funcionalidad incorrecta que afecta resultados
- [ ] 🟡 **Medio** - Problema menor que no afecta funcionalidad core
- [ ] 🟢 **Bajo** - Problema cosmético o de usabilidad

---

## 🔄 Reproducción del error

### Pasos para reproducir
<!-- Lista detallada de pasos para reproducir el error -->
1. Ir a [ubicación/archivo]
2. Ejecutar comando/función [comando específico]
3. Usar datos/parámetros [especificar]
4. Observar el error en [ubicación específica]

### Frecuencia del error
- [ ] ✅ **Siempre** - Ocurre cada vez
- [ ] 🔄 **Frecuente** - Ocurre la mayoría de las veces
- [ ] 🎲 **Ocasional** - Ocurre a veces
- [ ] 🦄 **Raro** - Ocurrió pocas veces
- [ ] ❓ **Una vez** - Solo observado una vez

### Condiciones específicas
<!-- Describe cuándo ocurre el error -->
- **Tamaño de datos:** [pequeño/mediano/grande]
- **Configuración:** [específica del sistema]
- **Timing:** [inicio/durante/final del proceso]
- **Dependencias:** [con otros módulos/funciones]

---

## 🖥️ Información del entorno

### Sistema operativo
- **OS:** [Windows 10/11, Ubuntu 20.04, macOS, etc.]
- **Arquitectura:** [x86, x64, ARM]
- **Version:** [número específico]

### Entorno de desarrollo
- **Compilador:** [GCC 9.4.0, Clang 12, MSVC 2019, etc.]
- **IDE/Editor:** [VS Code, Visual Studio, Vim, etc.]
- **Herramientas:** [Make, CMake, etc. con versiones]

### Configuración del proyecto
- **Rama:** [main, feature/X, etc.]
- **Commit:** [hash del commit si es relevante]
- **Configuración de build:** [Debug/Release, flags especiales]

---

## 📊 Evidencias del error

### Mensajes de error
```
[Pega aquí el mensaje de error exacto]
```

### Output completo
```
[Incluye el output completo donde aparece el error]
```

### Logs relevantes
```
[Si hay logs adicionales que puedan ser útiles]
```

### Stack trace (si aplica)
```
[Si hay stack trace o backtrace disponible]
```

---

## 📸 Capturas de pantalla
<!-- Añade capturas de pantalla si el error es visual o ayuda a explicarlo -->

---

## 🔍 Información adicional

### Datos de entrada utilizados
<!-- Describe los datos o parámetros que causaron el error -->
- **Archivos:** [nombre y características de archivos usados]
- **Parámetros:** [valores específicos de parámetros]
- **Configuración:** [settings relevantes]

### Intentos de solución
<!-- Describe qué has intentado para resolver el problema -->
- [ ] Recompilar el proyecto
- [ ] Reiniciar el entorno
- [ ] Probar con datos diferentes
- [ ] Revisar documentación
- [ ] [Otro intento específico]

### Observaciones adicionales
<!-- Cualquier otra información que pueda ser relevante -->

---

## 🎯 Análisis preliminar (opcional)

### Posible causa
<!-- Si tienes ideas sobre qué puede estar causando el error -->

### Archivos/módulos sospechosos
<!-- Lista archivos que podrían estar relacionados -->
- `src/archivo1.c` - [razón por la que sospechas]
- `src/archivo2.h` - [razón por la que sospechas]

### Función/línea específica
<!-- Si puedes pinpointerarlo más específicamente -->
- **Archivo:** [nombre del archivo]
- **Función:** [nombre de la función]
- **Línea aproximada:** [número de línea]

---

## ✅ Criterios de resolución

### El bug estará resuelto cuando
- [ ] El comportamiento erróneo ya no ocurra
- [ ] El programa produzca el resultado esperado
- [ ] No se introduzcan regresiones
- [ ] Se incluyan tests para prevenir el error en el futuro
- [ ] La documentación se actualice si es necesario

### Testing requerido
- [ ] Verificar el caso específico reportado
- [ ] Probar casos similares o relacionados
- [ ] Ejecutar suite completa de tests
- [ ] Validar en múltiples entornos si es necesario

---

## 🔗 Referencias

### Issues relacionados
<!-- Enlaces a otros issues que pueden estar relacionados -->

### Documentación relevante
<!-- Enlaces a docs que pueden ayudar a entender el contexto -->

### Commits sospechosos
<!-- Si sabes de cambios recientes que pueden haber introducido el error -->