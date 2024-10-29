# push_swap - Ordenamiento de Stacks

**push_swap** es un proyecto en **C** que implementa un algoritmo de ordenamiento de números utilizando dos stacks. El objetivo principal es ordenar una serie de números en la pila A, utilizando operaciones permitidas en las stacks y minimizando el número de movimientos.

## Objetivo

El proyecto tiene como objetivo implementar un programa que ordene números de una pila utilizando un mínimo de instrucciones. El programa debe ser capaz de ordenar una serie de números enteros en una pila A, utilizando una segunda pila B como auxiliar.

## Operaciones Permitidas

El programa puede utilizar las siguientes operaciones:

- `sa`: Intercambia los dos primeros elementos del stack A.
- `sb`: Intercambia los dos primeros elementos del stack B.
- `ss`: Realiza `sa` y `sb` al mismo tiempo.
- `pa`: Toma el primer elemento del stack B y lo coloca en la pila A.
- `pb`: Toma el primer elemento del stack A y lo coloca en la pila B.
- `ra`: Desplaza todos los elementos del stack A una posición hacia arriba.
- `rb`: Desplaza todos los elementos del stack B una posición hacia arriba.
- `rr`: Realiza `ra` y `rb` al mismo tiempo.
- `rra`: Desplaza todos los elementos del stack A una posición hacia abajo.
- `rrb`: Desplaza todos los elementos del stack B una posición hacia abajo.
- `rrr`: Realiza `rra` y `rrb` al mismo tiempo.

## Compilación

Para compilar el proyecto, ejecuta el comando `make` en el directorio raíz:

```bash
make
```

## Ejecución

```bash
./push_swap <números>
```