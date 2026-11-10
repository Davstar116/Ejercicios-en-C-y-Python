import time

# Función iterativa
def fibonacci_iterativo(n):
    sequence = [0, 1]
    for i in range(2, n):
        sequence.append(sequence[i-1] + sequence[i-2])
    return sequence[:n]

# Función recursiva
def fibonacci_recursivo(n):
    if n <= 1:
        return n
    else:
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2)

# Función para obtener la secuencia
def obtener_fibonacci_recursivo(n):
    return [fibonacci_recursivo(i) for i in range(n)]

# Comparación de tiempos
n = 10

# Tiempo de ejecución del iterativo
inicio_iterativo = time.time()
resultado_iterativo = fibonacci_iterativo(n)
fin_iterativo = time.time()
print(f"Fibonacci iterativo (n={n}): {resultado_iterativo}")
print(f"Tiempo de ejecución (iterativo): {fin_iterativo - inicio_iterativo:.6f} segundos")

# Tiempo de ejecución recursivo
inicio_recursivo = time.time()
resultado_recursivo = obtener_fibonacci_recursivo(n)
fin_recursivo = time.time()
print(f"Fibonacci recursivo (n={n}): {resultado_recursivo}")
print(f"Tiempo de ejecución (recursivo): {fin_recursivo - inicio_recursivo:.6f} segundos")
