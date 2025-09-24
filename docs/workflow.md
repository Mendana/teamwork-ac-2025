# 🚀 Flujo de trabajo del proyecto

## 1. Organización
- El trabajo se divide en **Infraestructura**, **Código**, **Documentación** y **QA**.
- Todas las tareas se gestionan en **GitHub Issues** y están en el **Project Board** (Kanban).
- Cada entrega tendrá un **milestone** propio (Monohilo, SIMD, Multihilo).

## 2. Issues
- Cada tarea se abre como **Issue** usando una plantilla (código, docs, QA, infra).
- El Issue se asigna a un responsable y se mueve en el tablero:
  - 🟢 To Do → 🟡 In Progress → 🔵 Review → ✅ Done

## 3. Ramas
- La rama principal es `main`.
- Cada tarea se hace en una rama `feature/nombre-tarea`.
- Ejemplo: `feature/mono-tiempos`.

## 4. Pull Requests
- Una vez terminada la tarea, se crea un **Pull Request** desde la rama a `main`.
- El PR debe:
  - Usar la plantilla de PR (`.github/pull_request_template.md`).
  - Estar vinculado al Issue con `Closes #NUMERO`.
  - Ser revisado al menos por **1 compañero** antes del merge.

## 5. Documentación
- La memoria está en `/docs` en formato Markdown.
- Cada parte de la memoria se trata como un Issue propio (igual que el código).
- Se añaden capturas y tablas dentro de `/docs/screenshots` o `/docs/data`.

## 6. Entregas
- Al final de cada entrega, `main` debe contener:
  - Código funcionando en la VM.
  - Imágenes de prueba y resultados.
  - Memoria actualizada.
  - README con instrucciones.

---
✅ Con este flujo, todos ven qué hacen los demás, nadie pisa el trabajo de otro, y todo queda registrado en GitHub.
