# Rango
inicio = -20
fin = 50

# Encabezado
print(f"{'Celsius':<8} {'Fahrenheit':<10}")
print(f"{'='*8} {'='*10}")

# Tabla
for celsius in range(inicio, fin + 1):
    fahrenheit = celsius * 9 / 5 + 32
    print(f"{celsius:<8} {fahrenheit:<10.2f}")    