# Completely Fair Scheduler (CFS) de Linux

### Steven Josue González Monroy - 201903974

## Introducción

El Completely Fair Scheduler (CFS) es el planificador de procesos predeterminado en el kernel de Linux desde la versión 2.6.23. Fue desarrollado por Ingo Molnár y se implementó para mejorar la equidad y eficiencia en la distribución del tiempo de CPU entre los procesos.

## Características principales

1. **Equidad**: El objetivo principal del CFS es proporcionar un tiempo de ejecución justo a todos los procesos.

2. **Árbol rojo-negro**: Utiliza una estructura de datos de árbol rojo-negro para organizar los procesos.

3. **Tiempo virtual de ejecución**: Asigna un tiempo virtual de ejecución a cada proceso para determinar su prioridad.

4. **Escalabilidad**: Funciona eficientemente tanto en sistemas con pocos núcleos como en sistemas con muchos núcleos.

5. **Prioridad dinámica**: Ajusta dinámicamente las prioridades de los procesos basándose en su comportamiento.

6. **Soporte para grupos de control**: Permite la gestión de recursos a nivel de grupo de procesos.

## Funcionamiento

### 1. Organización de procesos

- Los procesos se organizan en un árbol rojo-negro basado en su tiempo virtual de ejecución.
- El proceso con el menor tiempo virtual de ejecución se coloca en la parte izquierda del árbol.

### 2. Cálculo del tiempo virtual de ejecución

- Se calcula como: tiempo_virtual = tiempo_real_de_ejecución * (peso_base / peso_proceso)
- El peso del proceso se determina por su prioridad nice.

### 3. Selección del próximo proceso

- El CFS selecciona el proceso con el menor tiempo virtual de ejecución (el más a la izquierda en el árbol).

### 4. Quantum de tiempo

- No utiliza un quantum fijo, sino que calcula dinámicamente el tiempo de ejecución basado en el número de procesos en ejecución.

### 5. Prioridad y peso

- Utiliza valores de "nice" (-20 a +19) para asignar pesos a los procesos.
- Los procesos con mayor prioridad (valores de nice más bajos) reciben más tiempo de CPU.

### 6. Latencia objetivo

- El CFS intenta mantener una latencia objetivo, que es el tiempo mínimo que cada proceso debería ejecutarse al menos una vez.

## Ventajas

1. Mejor respuesta interactiva en comparación con planificadores anteriores.
2. Distribución justa del tiempo de CPU entre procesos.
3. Buen rendimiento tanto en sistemas de escritorio como en servidores.
4. Manejo eficiente de cargas de trabajo mixtas (CPU-bound e I/O-bound).

## Conclusión

El Completely Fair Scheduler representa un enfoque innovador en la planificación de procesos en Linux, proporcionando un equilibrio entre equidad, eficiencia y capacidad de respuesta. Su diseño flexible y escalable lo hace adecuado para una amplia gama de sistemas y cargas de trabajo.