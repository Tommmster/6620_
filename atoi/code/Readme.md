## Scope
Se propone codificar una versión reducida de la función ``` int atoi(char *)```, implementando la conversión
en MIPS32

## Construcción
`make` construye cuatro programas
* latoi : Implementa atoi mediante un loop
* latoi_mips : Implementa el loop en Mips32

* ratoi: Implementa atoi mediante una función recursiva
* ratoi_mips: Implementa la función recursiva en Mips32

## Próximos pasos
Queda como ejercicio implementar mas casos de prueba. Por ejemplo
* Filtrar espacios
* Retornar si se encuentra un caracter que no corresponde a un dígito
