---
name: "✅ Tarea de QA y revisión"
about: "Revisión exhaustiva de código, documentación, testing y validación de calidad"
title: "[QA] "
labels: ["QA", "revisión", "calidad", "testing"]
assignees:
---

## 🎯 Objetivo de la revisión

### Elemento a revisar
<!-- Especifica claramente qué se va a revisar -->
- **Tipo:** [Pull Request, Issue, Código, Documentación, Release]
- **Ubicación:** [Link al PR #123, archivo específico, sección]
- **Autor/Responsable:** [@usuario]
- **Fecha límite:** [DD/MM/YYYY]

### Alcance de la revisión
- [ ] 🔍 **Revisión de código** - Calidad, estilo, funcionalidad
- [ ] 📋 **Revisión de documentación** - Completitud, claridad, precisión
- [ ] 🧪 **Testing funcional** - Casos de prueba, cobertura, resultados
- [ ] ⚡ **Revisión de rendimiento** - Benchmarks, optimización
- [ ] 🔒 **Revisión de seguridad** - Vulnerabilidades, mejores prácticas
- [ ] 🏗️ **Revisión de arquitectura** - Diseño, patrones, escalabilidad

---

## 📋 Criterios de calidad del código

### Funcionalidad
- [ ] El código hace lo que se supone que debe hacer
- [ ] Se manejan correctamente todos los casos de uso
- [ ] Los casos extremos están considerados
- [ ] El manejo de errores es apropiado
- [ ] No hay regresiones en funcionalidad existente

### Calidad del código
- [ ] El código sigue las convenciones de estilo del proyecto
- [ ] Las variables y funciones tienen nombres descriptivos
- [ ] El código está bien comentado donde es necesario
- [ ] No hay código duplicado o redundante
- [ ] La complejidad es apropiada y mantenible

### Arquitectura y diseño
- [ ] La solución sigue principios de diseño sólidos
- [ ] La modularización es apropiada
- [ ] Las dependencias están bien gestionadas
- [ ] El código es extensible y mantenible
- [ ] Se siguen patrones establecidos del proyecto

---

## 🧪 Validación funcional

### Testing básico
- [ ] **Compilación:** El código compila sin errores ni warnings
- [ ] **Ejecución:** El programa ejecuta correctamente
- [ ] **Funcionalidad core:** Las características principales funcionan
- [ ] **Casos de prueba:** Se ejecutan todos los tests relevantes
- [ ] **Casos extremos:** Se prueban límites y condiciones especiales

### Testing en entorno
- [ ] **VM de desarrollo:** Probado en entorno estándar
- [ ] **Diferentes configuraciones:** Testado en múltiples setups
- [ ] **Datos reales:** Probado con datasets representativos
- [ ] **Condiciones de estrés:** Testado bajo carga/volumen alto
- [ ] **Compatibilidad:** Verificado en diferentes plataformas

### Validación de resultados
- [ ] **Correctitud:** Los resultados son matemáticamente correctos
- [ ] **Precisión:** La precisión cumple los requisitos
- [ ] **Consistencia:** Los resultados son reproducibles
- [ ] **Comparación:** Los resultados coinciden con referencias conocidas
- [ ] **Benchmarking:** El rendimiento está dentro de parámetros esperados

---

## 📊 Métricas y rendimiento

### Medidas de rendimiento
- [ ] **Tiempo de ejecución:** [Objetivo: < X segundos/minutos]
- [ ] **Uso de memoria:** [Objetivo: < X MB/GB]
- [ ] **Uso de CPU:** [Monitorear picos y promedio]
- [ ] **I/O de disco:** [Si es relevante]
- [ ] **Escalabilidad:** [Comportamiento con datos grandes]

### Comparación con baseline
- [ ] **Before vs After:** Comparar con versión anterior
- [ ] **Regresión de rendimiento:** Identificar degradaciones
- [ ] **Mejoras:** Documentar optimizaciones logradas
- [ ] **Trade-offs:** Analizar compromisos de diseño

---

## 📝 Revisión de documentación

### Completitud
- [ ] Toda la funcionalidad nueva está documentada
- [ ] Los cambios en APIs están reflejados
- [ ] Se incluyen ejemplos de uso
- [ ] Las dependencias están actualizadas
- [ ] Los requisitos del sistema están claros

### Calidad y claridad
- [ ] La documentación es fácil de entender
- [ ] No hay ambigüedades o contradicciones
- [ ] El estilo es consistente con el resto del proyecto
- [ ] Las imágenes y diagramas son claros e informativos
- [ ] La estructura es lógica y navegable

### Precisión técnica
- [ ] La información técnica es correcta
- [ ] Los ejemplos de código funcionan
- [ ] Las instrucciones son reproducibles
- [ ] No hay información obsoleta
- [ ] Las referencias externas son válidas

---

## ✅ Lista de verificación específica

### Pre-revisión
- [ ] Entender el contexto y objetivos del cambio
- [ ] Revisar issues y PRs relacionados
- [ ] Familiarizarse con el código base relevante
- [ ] Preparar entorno de testing si es necesario

### Durante la revisión
- [ ] Ejecutar todos los tests automatizados
- [ ] Probar manualmente funcionalidades críticas
- [ ] Verificar que la documentación está actualizada
- [ ] Comprobar estándares de código y estilo
- [ ] Analizar impacto en rendimiento

### Verificación cruzada
- [ ] Revisar con al menos otro miembro del equipo
- [ ] Validar criterios de aceptación del issue original
- [ ] Confirmar que se resuelven todos los puntos requeridos
- [ ] Verificar compatibilidad con trabajo en paralelo

### Post-revisión
- [ ] Documentar hallazgos y recomendaciones
- [ ] Comunicar problemas identificados
- [ ] Verificar que se implementan las correcciones
- [ ] Dar aprobación final o solicitar cambios

---

## 📸 Evidencias de testing

### Capturas de pantalla
- [ ] Compilación exitosa sin warnings
- [ ] Ejecución de tests automatizados
- [ ] Output del programa funcionando
- [ ] Métricas de rendimiento (si aplica)
- [ ] Comparación before/after (si aplica)

### Logs y outputs
- [ ] Logs de ejecución completos
- [ ] Resultados de benchmarks
- [ ] Output de herramientas de análisis estático
- [ ] Reportes de cobertura de tests
- [ ] Métricas de calidad del código

### Documentación de testing
- [ ] Plan de pruebas ejecutado
- [ ] Casos de prueba documentados
- [ ] Resultados detallados por caso
- [ ] Problemas encontrados y resolución
- [ ] Recomendaciones de mejora

---

## 🚨 Problemas y riesgos identificados

### Categorías de problemas
- [ ] 🔴 **Crítico** - Bloquea funcionalidad básica
- [ ] 🟠 **Alto** - Impacto significativo en calidad/rendimiento
- [ ] 🟡 **Medio** - Mejoras recomendadas
- [ ] 🟢 **Bajo** - Optimizaciones menores
- [ ] 🔵 **Informativo** - Observaciones sin impacto

### Template de reporte de problema
```
**Problema:** [Descripción concisa]
**Severidad:** [Crítico/Alto/Medio/Bajo]
**Ubicación:** [Archivo:línea o sección]
**Impacto:** [Descripción del impacto]
**Sugerencia:** [Cómo solucionarlo]
**Evidencia:** [Captura/log/output que demuestra el problema]
```

---

## 📋 Criterios de aceptación

### Para aprobar la revisión
- [ ] ✅ Cero problemas críticos pendientes
- [ ] ✅ Problemas de alta prioridad resueltos o justificados
- [ ] ✅ Testing completo ejecutado exitosamente
- [ ] ✅ Documentación actualizada y validada
- [ ] ✅ Rendimiento dentro de parámetros aceptables
- [ ] ✅ Al menos una revisión por pares adicional

### Para solicitar cambios
- [ ] ❌ Problemas críticos identificados
- [ ] ❌ Tests fallan o cobertura insuficiente
- [ ] ❌ Documentación incompleta o incorrecta
- [ ] ❌ Degradación significativa de rendimiento
- [ ] ❌ No cumple estándares de calidad del proyecto

---

## 🔄 Seguimiento y próximos pasos

### Acciones pendientes
<!-- Lista de acciones que deben tomarse basadas en la revisión -->
- [ ] Acción 1: [Descripción] - Responsable: [@usuario]
- [ ] Acción 2: [Descripción] - Responsable: [@usuario]

### Re-revisión requerida
- [ ] Después de correcciones solicitadas
- [ ] Validación de testing adicional
- [ ] Revisión de documentación actualizada
- [ ] Verificación de rendimiento mejorado

### Comunicación de resultados
- [ ] Feedback detallado al autor
- [ ] Actualización del estado del PR/issue
- [ ] Documentación de lecciones aprendidas
- [ ] Comunicación a stakeholders relevantes
