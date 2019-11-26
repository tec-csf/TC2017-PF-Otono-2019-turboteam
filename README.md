# *[Problema de las reinas]*
---
#### Materia: *Análisis y Diseño de Algoritmos (TC2017)*

#### Semestre: *Otoño 2019*

##### Campus: *Santa Fe*

##### Integrantes:
1. *[Rafael Díaz]* *[A01024592]*
2. *[David Benjamin Ruiz Salazar]* *[A01020825]*

---
## 1. Aspectos generales

### 1.1 Requerimientos

A continuación se mencionan los requerimientos mínimos del proyecto, favor de tenerlos presente para que cumpla con todos.

* El equipo tiene la libertad de elegir el problema a resolver.
* El proyecto deberá utilizar [OpenMP](https://www.openmp.org/) para la implementación del código paralelo.
* Todo el código y la documentación del proyecto debe alojarse en este repositorio de GitHub. Favor de mantener la estructura de carpetas propuesta.

### 1.2 Estructura del repositorio
El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# este archivo
    - secuencial		# Carpeta con la solución secuencial
    - parallel			# Carpeta con la solución paralela
    - comparativo       # Carpeta que contiene ambas soluciones en una y se comparan los tiempos 
    - docs              # Carpeta con los documentos, tablas, gráficas, imágenes
```

### 1.3 Documentación  del proyecto

Como parte de la entrega final del proyecto, se debe incluir la siguiente información:

* Descripción del problema a resolver.
* Descripción de la solución secuencial con referencia (enlace) al código secuencial alojado en la carpeta [secuencial](secuencial/).
* Análisis de los inhibidores de paralelismo presente y una explicación de cómo se solucionaron.
* Descripción de la solución paralela con referencia (enlace) al código paralelo alojado en la carpeta [paralelo](paralelo/).
* Tabla de resultados con los tiempos de ejecución medidos para cada variante de la solución secuencial vs. la solución paralela, teniendo en cuenta: 5 tamaños diferentes de las entradas, 5 opciones diferentes de números de CPU (threads), 4 ocpiones diferentes de balanceo (*auto, guided, static, dynamic*).
* Gráfica(s) comparativa(s) de los resultados obtenidos en las mediciones.
* Interpretación de los resultados obtenidos.
* Guía paso a paso para la ejecución del código y replicar los resultados obtenidos.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación seleccionado.

## 2. Descripción del problema

*[En este problema se intente obtener cuántas diferentes configuraciones existen para 8 reinas de ajedrez dentro de un tablero de n x n espacios sin que se amenacen entre ellas.]*

## 3. Solución secuencial

*[.]*

## 4. Análisis de los inhibidores del paralelismo

*[En este problema usualmente se necesita saber la localización de todas las reinas anteriormente colocadas, para que no se ataquen entre ellas; sin embargo al momento de implementar la paralelización se puede usar la cláusula shared, esta nos ayudará a que no se coloque ninguna reina que entre en conflicto con la que esté colocando algún otro thread. También se comparte la i entre todos los threads para que no se coloquen dos reinas en la misma columna.]*

## 5. Solución paralela

*[En la versión paralela se ejecuta casi el mismo código, solo que se toman en cuenta los inhibidores indicados y se usó la cláusula reduction para uno de los valores que contiene la respuesta.]*

## 6. Tabla de resultados

*[Incluya aquí la tabla con los resultados de las mediciones.]*

## 7. Gráfica(s) comparativa(s)

*[Incluya aquí la(s) gráfica(s) comparativa(s).]*

## 8. Interpretación de los resultados

*[Es evidente que la implementación con paralelismo resulta superior a la secuencial debido a la gran cantidad de comparaciones que se tienen que ejecutar. Solo en casos muy específicos no se nota una mejoría, esto se debe a que la cantidad de cálculos es tan pequeña que no tiene sentido hacer las operaciones de paralelismo]*

## 9. Guía paso a paso

*[Primero se compila el código con un compilador de c++ con el comando:
g++ -fopenmp  Queen.cpp
donde Queen.cpp es el nombre del tipo de ejecución deseado; ya sea secuencial, paralelo o comparativo.
Posteriormente se ejecuta con el comando:
OMP_NUM_THREADS=X SCHEDULE=METODO ./a.out
Donde X es el número de threads deseados y METODO es el tipo de schedule deseado; se pueden usar static, dynamic, grouped o auto.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
